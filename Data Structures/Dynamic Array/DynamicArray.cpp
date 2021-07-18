
#include <iostream>
using namespace std;
template <typename T> // Creating T generic.
class Array { // Dynamic array implemented using static arrays.

private:
	T* arr;
	int len = 0; // Assumed length of array
	int capacity = 0; // The maximum capacity of elements that the array can hold. 
public:
	Array() : Array(16) { // Calls the other constructor. Sets capacity to 16 by default.
		len = 0;
	}
	Array(int capacity) {
		if (capacity < 0) throw new std::invalid_argument("Invalid capacity. Capacity has to be over 0"); // Checking for capacity validity.
		this->capacity = capacity;
		arr = new T[capacity]; // Creating an object array of size capacity, and then casting it to T[] type.
		len = 0;
	}
	int length() { return len; }
	bool isEmpty() { return len == 0; }

	T get(int index) { return arr[index]; }
	void set(int index, T element) { arr[index] = element; }

	void clear() {
		for (int i = 0; i < len-1; i++) { // Iterating through each element and setting it to null.
			arr[i] = NULL;
		}
		len = 0; // Length is obviously now 0.
	}

	// Appends element to the end of the array.
	void add(T elem) { // Before adding the element to the array, we make sure that the capacity will not be exceeeded.
		if (len + 1 >= capacity) {
			if (capacity == 0) capacity++; // If capacity is none we just make it 1 at least.
			else capacity *= 2; // After that, we just double the capacity.
			T* new_array = new T[capacity]; // New static temp array that will be used to store the values that arr CURRENTLY holds.
			for (int i = 0; i < length(); i++) { // Copying all the values from the old array (arr) to the new array (new_array)
				new_array[i] = arr[i];
			}
			arr = new_array; // Making arr the newly made array.

		}
		arr[len++] = elem;
	}
	int getCapacity() {
		return this->capacity;
	}
	T removeAt(int index) {
		if (index >= len + 1) {
			throw new std::invalid_argument("Index out of bounds!");
		}
		T data = arr[index]; // The value removed will still need to returned, so we initialise it here, before its removed, and return it later.
		T* new_array = new T[len - 1]; // Creating a new array that will be one index smaller than the array being removed from.
		for (int i = 0, j = 0; i < len; i++, j++) {
			if (i == index) j--; // We're skipping over the index by fixing j to its current value temporarily so that the object at index is not added to the new array.
			else new_array[j] = arr[i];
		}
		this->arr = new_array; // Now we can set the arr value to the newly made array.
		capacity = --len; // Decreasing length by 1 and making capacity equal to length.
		return data; // Return the value that was removed.
	}
	bool remove(T obj) {
		for (int i = 0; i < len; i++) { // Iterating through all objects
			if (arr[i] == obj) { // If the current iteration is equal to the object that has to be removed
				removeAt(i); // Then we remove it using the function declared above.
				return true; // Return true cause we were successfully able to remove it.
			}
		}
		return false; // Otherwise just return false since we could not remove obj from the array.
	}
	int indexOf(T obj) {
		for (int i = 0; i < len; i++) {
			if (this->arr[i] == obj) return i; // Return the index at wherever the object was found.
		}
		return -1; // Otherwise return -1 if the object was not found within the array.
	}
	bool contains(T obj) {
		return indexOf(obj) != -1; // If the object does not exist in the array, we can call indexOf on it, if indexOf returns -1, it means it doesn't exist within the array.
	}
	bool hasNext() {
		int index = 0;
		return index < len;
	}
	T next() {
		int index = 0;
		return arr[index++];
	}
};
int main() {
	Array<int> a = Array<int>(2);
	a.add(0);
	a.add(1);
	a.add(3);
	a.add(6);
	a.add(2);
	a.add(7);
	a.add(4);
	a.add(8);
	a.add(3);
	cout << a.get(5) << endl;
	a.set(5, 3);
	cout << a.get(5) << endl;
	return 0;
}