#include <iostream>
#include <vector>
#include <numeric>

bool IsOddString(const std::string_view& s) {
  if (s.length() % 2 == 1)
    return false;

  auto mid = s.length() / 2;
  for (auto i = 0u; i < mid; ++i) {
    if (s[i] != s[mid + i])
      return false;
  }

  return true;
}

int main() {
  std::string S;
  std::cin >> S;

  for (auto i = static_cast<int>(S.length()) - 2; 0 <= i; i -= 2) {
    if (IsOddString(S.substr(0, i))) {
      std::cout << i << std::endl;
      return 0;
    }
  }

  std::cout << 0 << std::endl;
  return 0;
}
