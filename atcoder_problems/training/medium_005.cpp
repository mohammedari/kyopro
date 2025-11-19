#include <iostream>
#include <vector>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t ans = 0;
  for (auto i = 1ll; i <= N - 1; ++i) {
    ans += i;
  }

  std::cout << ans << std::endl;
  return 0;
}
