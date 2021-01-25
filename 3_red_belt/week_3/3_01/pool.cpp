// https://www.coursera.org/learn/c-plus-plus-red/programming/WtGFB/pul-obiektov

#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate() {
    T* obj;
    if (!deallocated_.empty()) {
      obj = deallocated_.front();
      deallocated_.pop();
    }
    else {
      obj = new T;
    }
    allocated_.insert(obj);

    return obj;
  }

  T* TryAllocate() {
    T* obj;
    if (!deallocated_.empty()) {
      obj = deallocated_.front();
      deallocated_.pop();
      allocated_.insert(obj);

      return obj;
    }
    else {
      return nullptr;
    }
  }

  void Deallocate(T* object) {
    if (allocated_.find(object) != allocated_.end()) {
      allocated_.erase(object);
      deallocated_.push(object);
      return;
    }

    throw std::invalid_argument("No allocated object!");
  }

  ~ObjectPool() {
    // allocated
    for (auto it = allocated_.begin(); it != allocated_.end(); ++it) {
      delete *it;
    }
    allocated_.clear();

    // deallocated
    while (!deallocated_.empty()) {
      delete deallocated_.front();
      deallocated_.pop();
    }
  }

private:
  std::set<T*> allocated_;
  std::queue<T*> deallocated_;
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);

  return 0;
}
