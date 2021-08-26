#include <iostream>
#include <string>
#include <list>
using namespace std;
template<typename T>
class Queue {
private:
    T* arr;
    int length;
    int capacity;
public:
    Queue() : Queue(16){} // Calls the other constructor and sets capacity to 16
    Queue(int capacity) {
        if (capacity <= 0) throw new std::invalid_argument("Invalid capacity. Capacity has to be over 0");
        arr = new T[capacity];
        length = 0;
        this->capacity = capacity;
    }
    void enqueue(T element) {
        if (length + 1 > capacity) {
            T* new_array = new T[capacity * 2];
            for (int i = 0; i < length; ++i) {
                new_array[i] = this->arr[i];
            }
        }
        arr[length] = element;
        length++;
    }
    T dequeue() {
        if (isEmpty()) throw new std::exception("The queue is empty."); 
        T data = arr[0];
        T* new_array = new T[capacity];
        for (int i = 0, j = 0; i < length; ++i) {
            if (i == 0) j--; // We hold/keep j in its place (by decreasing it by 1) so that it skips
            else new_array[j] = arr[i];
            j++;
        }
        length--;
        arr = new_array;
        return data;
    }
    int getSize() {
        return this->length;
    }
    bool isEmpty() { return getSize() == 0; }
    std::string toString() {
        std::string str = "";
        for (int i = 0; i < length; ++i) {
            str += to_string(this->arr[i]) + ", ";
        }
        str.pop_back();
        str.pop_back();
        return str;
    }
};


int main()
{
    Queue<int> q = Queue<int>();
    q.enqueue(1);
    q.enqueue(2);
    cout << q.getSize() << endl;
    cout << q.toString() << endl;
    q.dequeue();
    cout << q.getSize() << endl;
    cout << q.toString() << endl;
}