#include <string>
#include <list>
#include <iostream>
using namespace std;
template<typename T>
class Queue {
	private:
		std::list<T> list = std::list<T>();
	public:
		Queue() {}
		Queue(T firstElement) { 
			enqueue(firstElement);
		}
		void enqueue(T element) {
			list.push_back(element);
		}
		T dequeue() {
			if (isEmpty()) {
				throw new std::exception("Empty Queue");
			}
			T data = list.front();
			list.pop_front();
			return data;
		}
		T peek() {
			if (isEmpty()) { 
				throw new std::exception("Empty Queue");
			}
			return list.front();
		}
		int getSize() { 
			return list.size(); 
		}
		bool isEmpty() {
			return getSize() == 0;
		}
		std::string toString() {
			if (isEmpty()) return "[]";
			std::string str = "[";
			for (int i = 0; i < getSize(); ++i) {
				str += to_string(*(std::next(list.begin(), i))) + ", ";
			}
			str[str.length() - 2] = ']';
			return str;
		}
};

int main() {
	Queue<int> queue = Queue<int>();
	cout << queue.isEmpty() << endl;
	queue.enqueue(3);
	queue.enqueue(8);
	queue.enqueue(5);
	queue.enqueue(129);
	cout << queue.isEmpty() << endl;
	cout << queue.getSize() << endl;
	cout << queue.toString() << endl;
	cout << queue.dequeue() << " was dequeued." << endl;
	cout << queue.dequeue() << " was dequeued." << endl;
	cout << queue.getSize() << endl;
	cout << queue.toString() << endl;
	cout << queue.peek() << endl;
}