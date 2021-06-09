#include <iostream>
#include <list>
#include <vector>


int main() {

  const size_t MAX_ATHLETES = 100'000;
  using Position = std::list<size_t>::iterator;

  size_t n = 0;
  std::cin >> n;

  std::list<size_t> row;
  std::vector<Position> athlete_pos(MAX_ATHLETES + 1, row.end());

  for (size_t i = 0; i < n; ++i) {
    size_t cur_athlete = 0, next_athlete = 0;
    std::cin >> cur_athlete >> next_athlete;
    athlete_pos[cur_athlete] = row.insert(athlete_pos[next_athlete], cur_athlete);
  }

  for (const auto& e : row) {
    std::cout << e << '\n';
  }

  return 0;
}

