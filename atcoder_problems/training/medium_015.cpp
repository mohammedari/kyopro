#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

int main() {
  std::string s;
  std::cin >> s;

  std::string_view keyence = "keyence";

  // Front match
  int front_len = 0;
  for (auto c : s) {
    if (front_len < keyence.length() && keyence[front_len] == c) {
      ++front_len;
      continue;
    }

    break;
  }

  // Back match
  int back_len = 0;
  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    if (back_len < keyence.length() && keyence[keyence.size() - 1 - back_len] == *it) {
      ++back_len;
      continue;
    }

    break;
  }

  if (front_len + back_len >= keyence.length())
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;

  return 0;
}
