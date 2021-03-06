#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include <assert.h>
#include <cstring>
#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 2;
const int GROWTH_FACTOR = 2;

template <class T>
class dynamic_array {
    T *array;
    int capacity = INITIAL_CAPACITY;
    int _size;

public:
    //initialize an empty dynamic array
    dynamic_array() {
        array = new T[capacity];
        _size = 0;
    }
    //destuctor of array
    ~dynamic_array() {
        delete[] array;
        // std::cout << "destroyed dynamic array" <<std::endl;
    }
    // delete at index
    void deleteAt(int index) {
        assert(0 <= index && index < _size);
        _size--;
        for (int i = index; i < _size; i++) {
            array[i] = array[i + 1];
        }
    }

    // doubles capacity if it has to and deletes reference to current array.
    void resize() {
        capacity *= GROWTH_FACTOR;
        T *temp = new T[capacity];
        for(int i = 0; i < _size; i++) {
            temp[i] = std::move(array[i]);
        }
        delete [] array;
        array = temp;
    }

    // inserts an element at index
    void insertAt(T& element, int index) {
        // check that the index is with in the range
        assert(0 <= index && index <= _size);
        // if the array is full, resize it
        if(_size >= capacity) {
            resize();
        }
        // move the values forward
        // in order to make room
        // for the inserted value
        for(int i = _size; i > index; i--) {
            array[i] = array[i-1];
        }
        // update the size
        _size++;
        // insert the value
        array[index] = element;
    }
    // inserts an element after the last element
    void append(T& element) {
        insertAt(element, _size);
    }
    //returns current size
    int getsSize() {
        return _size;
    }


    // returns the value stored at index pos
    T get(int index) {
        assert(0 <= index && index < _size);
        return array[index];
    }

    // returns a reference to the value
    T& operator[](int index) {
        assert(0 <= index && index < _size);
        return array[index];
    }

    void pretty_print() {
        cout << "[";
        for (int i = 0; i < _size - 1; i++) {
            cout << array[i] << " ";
        }
        if (_size) {
            cout << array[_size - 1];
        }
        cout << "]\n";
    }
};

#endif //DYNAMIC_ARRAY_H_