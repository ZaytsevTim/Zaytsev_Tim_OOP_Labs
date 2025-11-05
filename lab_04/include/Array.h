#pragma once
#include <memory>

template<class T>
class Array {
private:
    std::shared_ptr<T[]> data_;
    size_t size_;
    size_t capacity_;
    void resize(size_t new_capacity);

public:
    Array();
    void push_back(const T& value);
    void push_back(T&& value);
    void remove(size_t index);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
};


template<class T>
void Array<T>::resize(size_t new_capacity) {
    std::shared_ptr<T[]> new_data(new T[new_capacity]);
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = std::move(data_[i]);
    }
    data_ = new_data;
    capacity_ = new_capacity;
}

template<class T>
Array<T>::Array() : size_(0), capacity_(10) {
    data_ = std::shared_ptr<T[]>(new T[capacity_]);
}

template<class T>
void Array<T>::push_back(const T& value) {
    if (size_ >= capacity_) {
        resize(capacity_ * 2);
    }
    data_[size_++] = value;
}

template<class T>
void Array<T>::push_back(T&& value) {
    if (size_ >= capacity_) {
        resize(capacity_ * 2);
    }
    data_[size_++] = std::move(value);
}

template<class T>
void Array<T>::remove(size_t index) {
    if (index >= size_) return;
    for (size_t i = index; i < size_ - 1; ++i) {
        data_[i] = std::move(data_[i + 1]);
    }
    --size_;
}

template<class T>
T& Array<T>::operator[](size_t index) {
    return data_[index];
}

template<class T>
const T& Array<T>::operator[](size_t index) const {
    return data_[index];
}

template<class T>
size_t Array<T>::size() const {
    return size_;
}
