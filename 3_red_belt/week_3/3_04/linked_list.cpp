#include "test_runner.h"

#include <vector>
using namespace std;

template <typename T>
class LinkedList {
public:
  struct Node {
      explicit Node() : value(0), next(nullptr) {}
      explicit Node(T value_) : value(value_), next(nullptr) {}
      explicit Node(T value_, Node* node_) : value(value_), next(node_) {}
    T value;
    Node* next = nullptr;
  };

  ~LinkedList() {
    while (head_) {
      PopFront();
    }
  }

  void PushFront(const T& value) {
    Node *tmp = new Node(value, head_);
    head_ = tmp;
  }

  void InsertAfter(Node* node, const T& value) {
    if (!node) {
      return PushFront(value);
    }
    Node* tmp = new Node(value, node->next);
    node->next = tmp;
  }

  void RemoveAfter(Node* node) {
    if (!node) {
      return PopFront();
    }
    else if (!node->next) {
      return;
    }
    else {
      Node* tmp = node->next->next;
      delete node->next;
      node->next = tmp;
    }
  }

  void PopFront() {
    if (!head_) {
      return;
    }
    else if (head_->next) {
      Node* tmp = new Node(head_->next->value, head_->next->next);
      delete head_;
      head_ = tmp;
    }
    else {
      delete head_;
      head_ = nullptr;
    }
  }

  Node* GetHead() { return head_; }
  const Node* GetHead() const { return head_; }

private:
  Node* head_ = nullptr;
};

template <typename T>
vector<T> ToVector(const LinkedList<T>& list) {
  vector<T> result;
  for (auto node = list.GetHead(); node; node = node->next) {
    result.push_back(node->value);
  }
  return result;
}

void TestPushFront() {
  LinkedList<int> list;

  list.PushFront(1);
  ASSERT_EQUAL(list.GetHead()->value, 1);
  list.PushFront(2);
  ASSERT_EQUAL(list.GetHead()->value, 2);
  list.PushFront(3);
  ASSERT_EQUAL(list.GetHead()->value, 3);

  const vector<int> expected = {3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);
}

void TestInsertAfter() {
  LinkedList<string> list;

  list.PushFront("a");
  auto head = list.GetHead();
  ASSERT(head);
  ASSERT_EQUAL(head->value, "a");

  list.InsertAfter(head, "b");
  const vector<string> expected1 = {"a", "b"};
  ASSERT_EQUAL(ToVector(list), expected1);

  list.InsertAfter(head, "c");
  const vector<string> expected2 = {"a", "c", "b"};
  ASSERT_EQUAL(ToVector(list), expected2);
}

void TestRemoveAfter() {
  LinkedList<int> list;
  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }

  const vector<int> expected = {5, 4, 3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);

  auto next_to_head = list.GetHead()->next;
  list.RemoveAfter(next_to_head); // удаляем 3
  list.RemoveAfter(next_to_head); // удаляем 2

  const vector<int> expected1 = {5, 4, 1};
  ASSERT_EQUAL(ToVector(list), expected1);

  while (list.GetHead()->next) {
    list.RemoveAfter(list.GetHead());
  }
  ASSERT_EQUAL(list.GetHead()->value, 5);
}

void TestPopFront() {
  LinkedList<int> list;

  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }
  for (int i = 1; i <= 5; ++i) {
    list.PopFront();
  }
  ASSERT(list.GetHead() == nullptr);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestPushFront);
  RUN_TEST(tr, TestInsertAfter);
  RUN_TEST(tr, TestRemoveAfter);
  RUN_TEST(tr, TestPopFront);
  return 0;
}
