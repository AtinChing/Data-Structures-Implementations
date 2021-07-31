#include <stdexcept>
#include <iostream>
#include <string>
#include <list>
using namespace std;
template<typename T>
class Stack {

	private:
		std::list<T> list = std::list<T>();
	public:
		Stack() {}
		Stack(T firstElement) {
			list.push_back(firstElement);
		}
		int getSize() { return list.size(); }
		bool isEmpty() { return getSize() == 0; }
		void push(T element) {
			list.push_back(element);
		}
		T pop() {
			if (isEmpty()) { throw new std::exception("Empty stack."); }
			T temp_data = list.back(); // Data/value that we'll have to return after popping the last element, so we initialise it here.
			list.pop_back();
			return temp_data;
		}
		T peek() {
			if (isEmpty()) { throw new std::exception("Empty stack.");  }
			return list.back();
		}
		std::string toString() {
			if (getSize() == 0) return "[]"; 
			std::string str = "[";
			for (int i = 0; i < list.size(); ++i) {
				auto current = std::next(list.begin(), i);
				str += to_string(*current) + ", ";
			}
			str[str.length() - 2] = ']';
			return str;
		}
};	
int main() {
	Stack<int> stack = Stack<int>();
	stack.push(32);
	stack.push(422);
	stack.push(432);
	cout << stack.toString() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.toString();
}