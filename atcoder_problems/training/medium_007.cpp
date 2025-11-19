#include <iostream>
#include <vector>
#include <numeric>

int main() {
  int N;
  std::cin >> N;

  std::string S;
  std::cin >> S;

  std::string kAlphabets = "abcdefghijklmnopqrstuvwxyz";

  int max_count = 0;
  for (auto i = 1; i < N - 1; ++i) {
    auto left = S.substr(0, i);
    auto right = S.substr(i, N - i);

    int count = 0;
    for (auto c : kAlphabets) {
      if (left.find(c) != std::string::npos && right.find(c) != std::string::npos)
        ++count;
    }

    max_count = std::max(max_count, count);
  }

  std::cout << max_count << std::endl;
  return 0;
}
