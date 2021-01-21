#include <string>
#include <vector>
using namespace std;

// Реализуйте этот макрос так, чтобы функция main компилировалась
#define UNIQ_ID_IMPL_2(line_number) var##line_number
#define UNIQ_ID_IMPL(line_number) UNIQ_ID_IMPL_2(line_number)
#define UNIQ_ID UNIQ_ID_IMPL(__LINE__)

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};

  return 0;
}