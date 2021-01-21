// https://www.coursera.org/learn/c-plus-plus-red/programming/Jr583/tablitsa

#include <vector>

#include "test_runner.h"


// Реализуйте здесь шаблонный класс Table
template<typename T>
class Table {
public:
    Table(size_t rows, size_t cols) {
        Resize(rows, cols);
    }

    const std::vector<T>& operator [] (size_t idx) const {
        return data_[idx];
    }

    std::vector<T>& operator [] (size_t idx) {
        return data_[idx];
    }

    void Resize(size_t rows, size_t columns) {
        data_.resize(rows);
        for (auto& item : data_) {
            item.resize(columns);
        }
    }

    std::pair<size_t, size_t> Size() const {
        if (!data_.empty() && !data_[0].empty()) {
            return {data_.size(), data_[0].size()};
        }
        return  {0, 0};
    }

private:
    std::vector<std::vector<T>> data_;
};


void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);

  return 0;
}
