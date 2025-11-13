#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> X(N);
  for (auto i = 0; i < N; ++i) {
    std::cin >> X[i];
  }

  auto min_sum = std::numeric_limits<int>::max();
  for (auto P = 1; P <= 100; ++P) {

    auto sum = std::accumulate(X.begin(), X.end(), 0, [P](int acc, int x) {
      return acc + (x - P) * (x - P);
    });

    if (sum < min_sum)
      min_sum = sum;
  }

  std::cout << min_sum << std::endl;
  return 0;
}