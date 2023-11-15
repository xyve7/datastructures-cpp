//
// Created by xyve on 11/14/23.
//
#include <iostream>
#include <cstring>
#include <stdexcept>

#ifndef DATA_STRUCTURES_MY_VECTOR_H
#define DATA_STRUCTURES_MY_VECTOR_H

template<typename T>
class my_vector {
private:
    T* data;
    std::size_t capacity;
    std::size_t _size;
public:
    my_vector(T* data, size_t size, size_t capacity) {
        if(size > capacity) {
            return;
        }
        this->data = new T[capacity];
        std::memcpy(this->data, data, sizeof(T) * size);
        this->capacity = capacity;
        this->_size = size;
    }
    my_vector(size_t capacity) {
        this->data = new T[capacity];
        this->capacity = capacity;
        this->_size = 0;
    }
    my_vector() {
        this->data = new T[2];
        this->capacity = 2;
        this->_size = 0;
    }
    my_vector(const my_vector<T> &other) {
        this->_size = other._size;
        this->capacity = other.capacity;
        this->data = new T[other.capacity];
        std::memcpy(this->data, other.data, sizeof(T) * other._size);
    }
    ~my_vector() {
        delete[] data;
    }
    void add(T item) {
        if(_size == capacity) {
            T* new_data = new T[capacity * 2];
            this->capacity *= 2;
            std::memcpy(new_data, this->data, this->capacity);
        }
        data[this->_size++] = item;
    }
    T& operator[](size_t index) {
        if(index >= this->_size) {
            throw std::out_of_range("index out of bounds");
        }
        return this->data[index];
    }
    my_vector& operator=(const my_vector<T> &other) {
        this->_size = other._size;
        this->capacity = other.capacity;
        this->data = new T[other.capacity];
        std::memcpy(this->data, other.data, sizeof(T) * other._size);
    }
    bool operator==(const my_vector<T> &other) {
        return this->_size == other._size && std::memcmp(this->data, other.data, other._size) == 0;
    }
    size_t find(T item) {
        for(size_t i = 0; i < this->_size; i++) {
            if(this->data[i] == item) {
                return i;
            }
        }
        throw std::runtime_error("unable to find item");
    }
    bool contains(T item) {
        for(size_t i = 0; i < this->_size; i++) {
            if(this->data[i] == item) {
                return true;
            }
        }
        return false;
    }
    size_t size() {
        return this->_size;
    }
    bool is_empty() {
        return this->_size == 0;
    }
    friend std::ostream& operator<<(std::ostream& out, my_vector<T>& list) {
        if(list._size == 0) {
            out << "[]";
            return out;
        }
        out << "[";
        for (std::size_t i = 0; i < list._size - 1; i++) {
            out << list[i] << ", ";
        }
        out << list[list._size - 1] << "]";
        return out;
    }
};


#endif //DATA_STRUCTURES_MY_VECTOR_H
