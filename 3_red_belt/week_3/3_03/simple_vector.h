#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector() {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

  explicit SimpleVector(size_t size) {
    data_ = new T[size];
    size_ = size;
    capacity_ = size_;
  }

  ~SimpleVector() {
    delete[] data_;
  }

  T& operator[](size_t index) {
    return data_[index];
  }

  const T* begin() const { return data_; }
  const T* end() const { return data_ + size_; }
  T* begin() { return data_; }
  T* end() { return data_ + size_; }

  size_t Size() const { return size_; }
  size_t Capacity() const { return capacity_; }

  void PushBack(const T& value) {
    if (size_ == 0) {
      data_ = new T[++capacity_];
    }
    else if (size_ == capacity_) {
      // expand vector capacity
      capacity_ *= 2;
      auto expanded_data = new T[capacity_];
      for (size_t i = 0; i < size_; ++i) {
        expanded_data[i] = data_[i];
      }
      delete[] data_;
      data_ = expanded_data;
    }

    data_[size_++] = value;
  }

private:
  T* data_;
  size_t size_;
  size_t capacity_;
};
