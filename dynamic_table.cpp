#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* arr;
    int capacity;
    int size;

    // Resizes the array by doubling its capacity
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    // Constructor
    DynamicArray(int initialCapacity = 2) : capacity(initialCapacity), size(0) {
        arr = new int[capacity];
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }

    // Adds an element to the end of the array
    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    // Access element at specific index
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Returns current size of the array
    int getSize() const {
        return size;
    }

    // Returns current capacity of the array
    int getCapacity() const {
        return capacity;
    }
};
