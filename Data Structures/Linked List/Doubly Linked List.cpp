
#include <stdexcept>
#include<iostream>
using namespace std;
template<typename T>
class Node {  // Node defintion
		
	public:
		T data; // Data stored in the node
		Node<T> *next, *prev; // Pointers to next and previous nodes of this node.
		Node(T data, Node<T> *prev, Node<T> *next) {
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
};
template<typename T>
class LinkedList {
	private:
		int size = 0;
		Node<T>* head = nullptr;
		Node<T>* tail = nullptr;
		T remove(Node<T> *node) {
			if (node->next == nullptr) return removeLast(); // Remove the tail if tail node was passed in.
			if (node->prev == nullptr) return removeFirst(); // Remove the head if head node was passed in.
			node->next->prev = node->prev; // Setting the pointers of adjacent nodes to skip/point before and after the node passed in, respectively.   
			node->prev->next = node->next;

			T data = node->data; // Node data has to be returned after node removal.
			node->data = nullptr; // Deallocating/removing/erasing the memory/data of the node that has to be removed. 
			return data;
		}
	public:
		LinkedList() {  // Constructor to create empty linked list.
			head = nullptr;
			tail = nullptr;
			size = 0;
		}
		void clear() {
			Node<T>* trav = head; // Initialising a traverser, which is the head in this case.
			while (trav != nullptr) { // We keep iterating as long as there are elements in the list.
				Node<T>* next = trav->next;
				trav->prev = trav->next = nullptr; // Setting next and previous nodes to nullptr.
				trav->data = nullptr; // Setting current node to nullptr
				trav = next; // Moving onto the next node.
			}
			head = tail = *trav = nullptr; // Resetting head and tail.
			size = 0;
		}
		int getSize() {
			return size;
		}
		bool isEmpty() {
			return getSize() == 0;
		}
		void add(T elem) {
			addLast(elem);
		}
		void addFirst(T elem) {
			if (isEmpty()) { // If the linked list is empty, we only insert in 1 node, which is both the head AND the tail of the linked list.
				head = tail = new Node<T>(&elem, nullptr, nullptr);
			}
			else {
				head->prev = new Node<T>(&elem, nullptr , head); // The previous node that the head points to is the node we have just created.
				head = head->prev; // Then we set the head of the linked list to the previous node that the old head (before new node addition/creation) points to.
			}
			size++;
		}
		void addLast(T elem) { // Same logic as addFirst except we use the tail instead.
			if (isEmpty()) {
				head = tail = new Node<T>(elem, nullptr, nullptr);
			}
			else {
				tail->next = new Node<T>(elem, tail, nullptr);
				tail = tail->next;
			}
			size++;
		}
		T peekFirst() {
			if (isEmpty()) { throw std::exception("Empty linked list"); }
			else return head->data;
		}
		T peekLast() {
			if (isEmpty()) { throw std::exception("Empty linked list"); }
			else return tail->data;
		}
		T removeFirst() {
			if (isEmpty()) { throw std::exception("Empty linked list"); }
			T data = head->data; // Temporarily storing data that will be returned later.
			head = head->next; // The head is now set to the node after/the head points to next, so now we can deallocate/erase the memory/data of the old head.
			size--;
			if (isEmpty()) { tail = nullptr; } // If the list is now empty, we set the tail to nullptr too (since there's nothing in the linked list anymore). 
			else {
				head->prev = nullptr; // Deallocationg/erasing the memory of the node we just removed.
			}
			return data;
		}
		T removeLast() {
			if (isEmpty()) { throw std::exception("Empty linked list"); }
			T data = tail->data;
			tail = tail->prev;
			size--;
			if (isEmpty()) { head = nullptr; }
			else { tail->next = nullptr; }
			return data;
		}
		T removeAt(int index) {
			if (index < 0 || index >= size) throw std::invalid_argument("Invalid index!");
			int i = 0;
			Node<T> trav;
			if (index < size / 2) { // Search from the front of the list
				for (i = 0, trav = head; i != index; i++) // Start at head, then keep traversing.
				{
					trav = trav->next; // Keep moving/iterating through the linked list, by using the traverser. 
				}
				return remove(trav); // We've now reached the node at the passed in index so we can just remove it.
			}
			else { // Search from the back of the list
				for (i = size, trav = tail; i != index; i--) {
					trav = trav->prev;
				}
				return remove(trav);
			}
		}
		bool remove(T obj) { // Remove certain object from the linked list.
			Node<T>* trav = head;
			if (obj == nullptr) { // If object passed in is nullptr type.
				for (trav = head; trav != nullptr; trav = trav.next) { // Start from head node, keep iterating through nodes unless the trav reaches the end of the list.
					if (trav.data == nullptr) { // If the current node's data holds nullptr then we remove it since we've found it.
						remove(trav);
						return true;
					}
				}
			}
			else { // If object passed in is not nullptr
				for (trav = head; trav != nullptr; trav = trav->next) {
					if (trav.data == obj) {
						remove(trav);
						return true;
					}
				}
			}
			return false; // Return false if the object could not be found and removed.
		}
		int indexOf(const T& obj) const { // Similar logic to method above
			Node<T>* trav;
			int i = 0; // Used for storing index of current iteration
			if (&obj == nullptr) {
				for (trav = head; trav != nullptr; trav = trav->next, i++) { // Keep iterating through nodes in the linked list and incrementing index
					if (&(trav->data) == nullptr) {
						return i; // Return current index if current nodes data is nullptr
					}
				}
			}
			else {
				for (trav = head; trav != nullptr; trav = trav->next, i++) {
					T data = trav->data;
					if (data == obj) {
						return i; // Return index of node that has same data/value as object passed in.
					}
				}
			}
			return -1; // Return -1 if object could not be found
		}
		bool contains(T obj) {
			return indexOf(obj) != -1; // If index of object passed in is -1 then that means it doesn't exist in the linked list.
		}
		
};
int main() {
	LinkedList<int> list = LinkedList<int>();
	list.add(3);
	list.add(4);
	list.add(5);
	cout << list.getSize() << endl;
	list.clear();
	cout << list.getSize() << endl;
}




