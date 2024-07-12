#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
using namespace std;
using std::vector;
using std::array;
template <typename T>
class PriorityQueue {
private:
    int size = 0; // Current size of pq/heap
    int capacity = 0; // Max size of pq/heap
    vector<T> heap; // Actual PQ/heap data itself
    unordered_map<T, vector<int>> map; // Hashmap that maps node values to possible indexes/positions that node value could be stored at within our heap
public:
    PriorityQueue() { // Constuctor, initially empty
    }
    PriorityQueue(int size) { // Constructor, makes pq with an initial capacity
        heap = new vector<T>(size);
        this->size = size;
    }
    // Below constructor is called "Heapify" process, O(n) creation time.
    PriorityQueue(T[] elements) { // Constructing pq with the actual data/elements themselves straight away
        this->size = this->capacity = elements.size();
        heap = new vector<T>(this->size);
        for (int i = 0; i < this->size; i++) {
            heap.push_back(elements[i]);
            map.insert(elements[i], i); // Maps an element/node value to its position(s) within the heap.
        }
        int m = 0;
        int temp = (this->size / 2) - 1;
        if temp > m{ m = temp; }
        for (int i = m; i >= 0; i--) {
            sink(i); // Sinking/bubbling/swapping each element from middle of the heap to first element of heap
        }
    }
    // Otherwise, this is the other implementation, O(nlog(n)) creation time, more obvious priority queue construction method/overload that you'd probably implement.
    PriorityQueue(T[] elements) {
        PriorityQueue(elements.size());
        for (T elem : elements) {
            add(elem); // add implemented below
        }
    }
    bool isEmpty() {
        return size == 0;
    }
    void clear() { // Clears all PQ/Heap data
        map.clear();
        size = 0;
        for (int i = 0; i < capacity; i++) {
            heap[i] = -1;
        }
    }
    int getSize() {
        return size;
    }
};
int main()
{
    cout << "NA NA NA NA NA HEY HEY HEY HEY, GOOD BYE!\n";
}

