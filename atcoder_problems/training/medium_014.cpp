#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

int main() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::string> s(H);
  for (auto i = 0; i < H; ++i) {
    std::cin >> s[i];
  }

  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      if (s[i][j] == '#') {
        // Find adjacent '#'
        bool found_adjacent = false;
        const std::vector<std::pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        for (const auto& dir : directions) {
          int ni = i + dir.first;
          int nj = j + dir.second;

          if (ni >= 0 && ni < H && nj >= 0 && nj < W && s[ni][nj] == '#') {
            found_adjacent = true;
            break;
          }
        }

        if (!found_adjacent) {
          std::cout << "No" << std::endl;
          return 0;
        }
      }
    }
  }

  std::cout << "Yes" << std::endl;
  return 0;
}
