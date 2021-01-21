// https://www.coursera.org/learn/c-plus-plus-red/programming/5a8aD/diek-na-osnovie-dvukh-viektorov

#include <vector>
#include <stdexcept>

template <typename T>
class Deque {
public:
    Deque() = default;

    bool Empty() const {
        return head_.empty() && tail_.empty();
    }

    size_t Size() const {
        return head_.size() + tail_.size();
    }

    const T& operator [] (size_t i) const {
        return GetElement(i);
    }

    T& operator [] (size_t i) {
        return GetElement(i);
    }

    const T& At(size_t i) const {
        CheckOutOfRange(i);
        return GetElement(i);
    }

    T& At(size_t i) {
        CheckOutOfRange(i);
        return GetElement(i);
    }

    const T& Front() const {
        return head_.empty() ? tail_.front() : head_.back();
    }

    T& Front() {
        return head_.empty() ? tail_.front() : head_.back();
    }

    const T& Back() const {
        return tail_.empty() ? head_.front() : tail_.back();
    }

    T& Back() {
        return tail_.empty() ? head_.front() : tail_.back();
    }

    void PushFront(const T& elem) {
        head_.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail_.push_back(elem);
    }

private:
    std::vector<T> head_, tail_;

    T& GetElement(size_t i) {
        return i < head_.size() ? head_[head_.size() - i - 1] : tail_[i - head_.size()];
    }

    const T& GetElement(size_t i) const {
        return i < head_.size() ? head_[head_.size() - i - 1] : tail_[i - head_.size()];
    }

    void CheckOutOfRange(size_t i) const {
        if (i >= Size()) {
            throw std::out_of_range("Index is out of range");
        }
    }
};

int main() {

    Deque<int> deque;

    return 0;
}