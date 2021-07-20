template<typename T>
class Node {  // Node defintion
	private:
		T data; // Data stored in the node
		Node<T> next, prev; // Next and previous nodes of this node.
	public:
		Node(T data, Node<T> prev, Node<T> next) {
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
};
template<typename T>
class LinkedList {
	private:
		int size = 0;
		Node<T> head = NULL;
		Node<T> tail = NULL;
		T remove(Node<T> node) {
			if (node.next == NULL) return removeLast(); // Remove the tail if tail node was passed in.
			if (node.prev == NULL) return removeFirst(); // Remove the head if head node was passed in.
			node.next.prev = node.prev; // Setting the pointers of adjacent nodes to skip/point before and after the node passed in, respectively.   
			node.prev.next = node.next;

			T data = node.data; // Node data has to be returned after node removal.
			node.data = NULL; // Deallocating/removing/erasing the memory/data of the node that has to be removed. 
			return data;
		}
	public:
		LinkedList() {}
		void clear() {
			Node<T> trav = head; // Initialisng a traverser, which is the head in this case.
			while (trav != NULL) { // We keep iterating as long as there are elements in the list.
				Node<T> next = trav.next;
				trav.prev = trav.next = NULL; // Setting next and previous nodes to null.
				trav.data = NULL; // Setting current node to null
				trav = next; // Moving onto the next node.
			}
			head = tail = trav = NULL; // Resetting head and tail.
			size = 0;
		}
		int size() {
			return size;
		}
		bool isEmpty() {
			return size() == 0;
		}
		void add(T elem) {
			addLast(elem);
		}
		void addFirst(T elem) {
			if (isEmpty()) { // If the linked list is empty, we only insert in 1 node, which is both the head AND the tail of the linked list.
				head = tail = new Node<T>(elem, NULL, NULL);
			}
			else {
				head.prev = new Node<T>(elem, NULL, head); // The previous node that the head points to is the node we have just created.
				head = head.prev; // Then we set the head of the linked list to the previous node that the old head (before new node addition/creation) points to.
			}
			size++;
		}
		void addLast(T elem) { // Same logic as addFirst except we use the tail instead.
			if (isEmpty()) {
				head = tail = new Node<T>(elem, NULL, NULL);
			}
			else {
				tail.next = new Node<T>(elem, tail, NULL);
				tail = tail.next;
			}
			size++;
		}
		T peekFirst() {
			if (isEmpty()) { throw std::runtime_error("Empty linked list"); }
			else return head.data;
		}
		T peekLast() {
			if (isEmpty()) { throw std::runtime_error("Empty linked list"); }
			else return tail.data;
		}
		T removeFirst() {
			if (isEmpty()) { throw std::runtime_error("Empty linked list"); }
			T data = head.data; // Temporarily storing data that will be returned later.
			head = head.next; // The head is now set to the node after/the head points to next, so now we can deallocate/erase the memory/data of the old head.
			size--;
			if (isEmpty()) { tail = NULL; } // If the list is now empty, we set the tail to null too (since there's nothing in the linked list anymore). 
			else {
				head.prev = NULL; // Deallocationg/erasing the memory of the node we just removed.
			}
			return data;
		}
		T removeLast() {
			if (isEmpty() { throw std::runtime_error("Empty linked list")); }
			T data = tail.data;
			tail = tail.prev;
			size--;
			if (isEmpty()) { head = NULL; }
			else { tail.next = NULL; }
			return data;
		}
		T removeAt(int index) {
			if (index < 0 || index >= size) throw std::invalid_argument("Invalid index!");
			int i = 0;
			if (index < size / 2) { // Search from the front of the list
				for (i = 0, trav = head; i != index; i++) // Start at head, then keep traversing.
				{
					trav = trav.next // Keep moving/iterating through the linked list, by using the traverser. 
				}
				return remove(trav); // We've now reached the node at the passed in index so we can just remove it.
			}
			else { // Search from the back of the list
				for (i = size, trav = tail; i != index; i--) {
					trav = trav.prev;
				}
				return remove(trav);
			}
		}
		bool remove(T obj) { // Remove certain object from the linked list.
			Node<T> trav = head;
			if (obj == NULL) { // If object passed in is NULL type.
				for (trav = head; trav != NULL; trav = trav.next) { // Start from head node, keep iterating through nodes unless the trav reaches the end of the list.
					if (trav.data == NULL) { // If the current node's data holds NULL then we remove it since we've found it.
						remove(trav);
						return true;
					}
				}
			}
			else { // If object passed in is not null
				for (trav = head; trav != NULL; trav = trav.next) {
					if (trav.data == obj) {
						remove(trav);
						return true;
					}
				}
			}
			return false; // Return false if the object could not be found and removed.
		}
		int indexOf(T obj) { // Similar logic to method above
			Node<T> trav = head;
			int i = 0; // Used for storing index of current iteration
			if (obj == NULL) {
				for (trav = head; trav != NULL; trav = trav.next, i++) { // Keep iterating through nodes in the linked list and incrementing index
					if (trav.data = NULL) {
						return i; // Return current index if current nodes data is null
					}
				}
			}
			else {
				for (trav = head; trav != NULL; trav = trav.next, i++) {
					if (trav.data == obj) {
						return i; // Return index of node that has same data/value as object passed in.
					}
				}
			}
			return -1; // Return -1 if object could not be found
		}
		bool contains(T obj) {
			return indexOf(obj) == -1; // If index of object passed in is -1 then that means it doesn't exist in the linked list.
		}
		int main() {
		
		}
};




