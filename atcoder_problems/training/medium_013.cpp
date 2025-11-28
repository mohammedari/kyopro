#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> t(N);
  std::vector<int> x(N);
  std::vector<int> y(N);
  for (auto i = 0; i < N; ++i) {
    std::cin >> t[i] >> x[i] >> y[i];
  }

  int current_x = 0;
  int current_y = 0;
  int current_t = 0;
  for (auto i = 0; i < N; ++i) {
    int dt = t[i] - current_t;
    int dist = std::abs(x[i] - current_x) + std::abs(y[i] - current_y);

    if (dist > dt || (dt - dist) % 2 != 0) {
      std::cout << "No" << std::endl;
      return 0;
    }

    current_x = x[i];
    current_y = y[i];
    current_t = t[i];
  }

  std::cout << "Yes" << std::endl;
  return 0;
}
