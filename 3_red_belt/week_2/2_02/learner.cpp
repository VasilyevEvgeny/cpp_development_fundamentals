#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

class Learner {
 private:
  std::set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    std::set<string> unique_words(words.begin(), words.end());
    size_t dict_size_prev = dict.size();
    for (auto& word : unique_words) {
        dict.insert(word);
    }

    return dict.size() - dict_size_prev;
  }

  vector<string> KnownWords() {
    return {dict.begin(), dict.end()};
  }
};


int main() {
    Learner learner;
    string line;
    while (getline(std::cin, line)) {
        vector<string> words;
        std::stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        std::cout << learner.Learn(words) << "\n";
    }
    std::cout << "=== known words ===\n";
    for (auto word : learner.KnownWords()) {
        std::cout << word << "\n";
    }
}