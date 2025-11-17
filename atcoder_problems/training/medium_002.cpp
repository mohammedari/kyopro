#include <iostream>

int main() {
  std::string S;
  std::cin >> S;

  // Find W, and count the number of B in the left side
  // We can increment `count_B_in_left` when we find 'B' to keep O(N) time complexity.
  // Note that we should use int64_t to avoid overflow as N can be up to 2x10^5.
  int64_t count_B_in_left = 0;
  int64_t total_turn_around_count = 0;
  for (auto i = 0u; i < S.length(); ++i) {
    if (S[i] == 'W') {
      total_turn_around_count += count_B_in_left;
    }
    else {
      ++count_B_in_left;
    }
  }

  std::cout << total_turn_around_count << std::endl;
  return 0;
}
