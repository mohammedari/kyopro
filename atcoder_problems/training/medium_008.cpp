#include <iostream>
#include <vector>
#include <numeric>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> a(N);
  for (auto i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> color_counts(9, 0);
  for (auto ai : a) {
    if (1 <= ai && ai <= 399)
      ++color_counts[0];
    else if (400 <= ai && ai <= 799)
      ++color_counts[1];
    else if (800 <= ai && ai <= 1199)
      ++color_counts[2];
    else if (1200 <= ai && ai <= 1599)
      ++color_counts[3];
    else if (1600 <= ai && ai <= 1999)
      ++color_counts[4];
    else if (2000 <= ai && ai <= 2399)
      ++color_counts[5];
    else if (2400 <= ai && ai <= 2799)
      ++color_counts[6];
    else if (2800 <= ai && ai <= 3199)
      ++color_counts[7];
    else
      ++color_counts[8];
  }

  int color_variation = 0;
  for (auto i = 0u; i < color_counts.size() - 1; ++i) {
    if (color_counts[i] > 0)
      ++color_variation;
  }

  int min_color_variation = std::max(color_variation, 1);
  int max_color_variation = color_variation + color_counts[8];

  std::cout << min_color_variation << " " << max_color_variation << std::endl;
  return 0;
}
