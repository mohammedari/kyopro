#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> a(N);
  for (auto i = 0; i < N; ++i) {
    std::cin >> a[i];
  }


  std::unordered_map<int, int> count;
  for (const auto& num : a) {
    ++count[num - 1];
    ++count[num];
    ++count[num + 1];
  }

  int max_count = 0;
  for (const auto& [key, value] : count) {
    if (value > max_count) {
      max_count = value;
    }
  }

  std::cout << max_count << std::endl;
  return 0;
}
