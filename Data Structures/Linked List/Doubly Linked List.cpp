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
};