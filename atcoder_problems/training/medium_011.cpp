#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

int64_t manhattan_distance(const std::tuple<int64_t, int64_t>& a, const std::tuple<int64_t, int64_t>& b) {
  return std::abs(std::get<0>(a) - std::get<0>(b)) + std::abs(std::get<1>(a) - std::get<1>(b));
}

int main() {
  int N, M;
  std::cin >> N >> M;

  std::vector<std::tuple<int64_t, int64_t>> students(N);
  for (auto i = 0; i < N; ++i) {
    auto& coord = students[i];
    std::cin >> std::get<0>(coord) >> std::get<1>(coord);
  }

  std::vector<std::tuple<int64_t, int64_t>> checkpoints(M);
  for (auto i = 0; i < M; ++i) {
    auto& coord = checkpoints[i];
    std::cin >> std::get<0>(coord) >> std::get<1>(coord);
  }

  for (auto i = 0; i < N; ++i) {
    int min_index = 0;
    int64_t min_distance = manhattan_distance(students[i], checkpoints[0]);
    for (auto j = 1; j < M; ++j) {
      int64_t distance = manhattan_distance(students[i], checkpoints[j]);
      if (distance < min_distance) {
        min_distance = distance;
        min_index = j;
      }
    }

    std::cout << min_index + 1 << std::endl;
  }

  return 0;
}
