#include <string>
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
class LinkedList {
	public:
		LinkedList() {}
		void clear() {

		}
};