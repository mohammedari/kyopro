#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> a(N);
  for (auto i = 0; i < N; ++i)
    std::cin >> a[i];

  std::vector<bool> visited(N);
  int current_button = 1;
  int num_pushed = 0;
  while (current_button != 2) {
    if (visited[current_button - 1]) {
      std::cout << -1 << std::endl;
      return 0;
    }
    visited[current_button - 1] = true;

    // push button
    current_button = a[current_button - 1];
    ++num_pushed;
  }

  std::cout << num_pushed << std::endl;
  return 0;
}
