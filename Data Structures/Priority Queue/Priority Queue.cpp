#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <set>
using namespace std;
using std::vector;
using std::array;
using std::set;
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
    T peek() { // Get value/node/element with lowest priority in pq, if empty null returned
        if isEmpty() return -1;
        return heap[0]
    }
    T poll() { // Removes root of heap
        return removeAt(0);
    }
    bool contains(T elem) {
        return map.find(elem) == map.end();
    }
    void add(T elem) {
        if (size < capacity) {
            heap[size] = elem;
        }
        else {
            heap.add(elem);
            capacity++;
        }
        map.insert(elem, size); // Update map accordingly
        swim(size); // Making recently added element swim/swap its way to its correct position.
        size++;
    }
    bool less(int i, int j) { // if node at i is less than node at j
        return heap[i] < heap[j]
    }
    void swim(int k) { // swimming/swapping a node from bottom to top
        //index of node that is parent of k
        int parent = (k - 1) / 2;
        
        // keep swimming while we have not reached the root and we're less than our parent
        while (k > 0 && less(k, parent)) {
            swap(parent, k); // exchanging k with parent
            k = parent;
            parent = (k - 1) / 2; // index of parent of current node
        }
    }
    void sink(int k) { // top to bottom, node is being sinked/swapping into correct position
        while (true) {
            int left = 2 * k + 1; // left child of node at k
            int right = 2 * k + 2; // right child of node at k
            int smallest = left; // can assume smallest node is the left of the 2 children

            //finding which one is smaller, if right is smaller then obv set smallest = right
            if (right < size && less(right, left)) {
                smallest = right;
            }
            //stop if we're outside the bounds of the tree, or if we cant sink k anymore
            if (left >= size || less(k, smallest)) { break; }
            // move down the tree following the smallest node
            swap(smallest, k);
            k = smallest;
        }
    }
    // swaps 2 nodes
    void swap(int i, int j) {
        T i_elem = heap[i];
        T j_elem = heap[j];
        heap[i] = j_elem;
        heap[j] = i_elem;
        mapSwap(i_elem, j_elem, i, j);
    }
    bool remove(T element) {
        // Logarthmic removal with a map
        int index = mapGet(element);
        if (index != -1) {
            removeAt(index);
        }
        return index != -1;
    }
    T removeAt(int index) {
        if isEmpty() return -1;
        size--;
        T removed = heap[index];
        swap(i, size); // Remember to remove in heaps, number being removed is swapped with right-most element of bottom row, then it is removed, so swap with last element
        heap[size] = -1; // Remove the value
        mapRemove(removed, size);
        if (index == size) return removed; // If last element was removed, then we no need to sink or swim or anything, just straight up return what was just removed.
        T elem = heap[index];
        sink(index);
        if (heap[index] == elem) swim(index); // If sinking the element didn't change its position at all, just try swimming it
        return removed;
    }
    // recursively checks if heap is a min heap, used for testing purposes to ensure heap property is still being maintained, this method gets called with k=0 to start check at the root.
    bool isMinHeap(int k) {
        if k >= size return true; // if outside bounds of heap, return true
        int leftChild = (2 * k) + 1;
        int rightChild = (2 * k) + 2;

        // Make sure that current node k's  value is less than both of its children (left and right children) but only if they exist, otherwise return false cuz then its not a valid heap
        if (leftChild < size && !less(k, leftChild)) return false;
        if (rightChild < size && !less(k, rightChild)) return false;
        // recursively checking that both children are also valid heaps of their own.
        return isMinHeap(leftChild) && isMinHeap(rightChild);
    }
    void mapAdd(T val, int index) {
        bool err = false;
        set<int> setData;
        try {
            set<int> setData = map[val];
        }
        catch (const std::exception& e){
            set<int> setData = new set<int>();
            setData.insert(index);
            map.insert(val, setData);
            err = true;
        }
        if (!err){
            setData.insert(index);
        }
    }
    void mapRemove(T val, int index) {
        set<int> setData = map[val];
        setData.erase(index);
        if (setData.size() == 0) map.erase(val);
    }
    int mapGet(T val) {
        set<T> setData;
        try {
            set<T> setData = map[val];
            return *setData.rbegin(); // Return last element as long as theres a set that exists for this value of val
        }
        catch (const std::exception& e) {
            return -1; // otherwise it doesnt exist in the map, so return null
        }
    }
    // Exchange the index of the 2 nodes internally within the map
    void mapSwap(T val1, T val2, int val1Index, int val2Index) {
        set<int> set1 = map[val1];
        set<int> set2 = map[val2];
        set1.erase(val1Index);
        set2.erase(val2Index);
        set1.insert(val2Index);
        set2.insert(val1Index);
    }
};
int main()
{
    cout << "NA NA NA NA NA HEY HEY HEY HEY, GOOD BYE!\n";
}

