#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

int main() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::string> grid(H);
  for (auto i = 0; i < H; ++i) {
    std::cin >> grid[i];
  }

  std::vector<std::string> grid2;
  for (auto i = 0; i < H; ++i) {
    if (grid[i].find('#') != std::string::npos) {
      grid2.push_back(grid[i]);
    }
  }

  auto line_length = W;
  for (auto i = 0; i < line_length; ++i) {
    bool all_dots = true;
    for (auto j = 0; j < grid2.size(); ++j) {
      if (grid2[j][i] == '#') {
        all_dots = false;
        break;
      }
    }

    if (all_dots) {
      for (auto& line : grid2) {
        line.erase(line.begin() + i);
      }

      --i;
      --line_length;
    }
  }

  for (const auto& line : grid2) {
    std::cout << line << std::endl;
  }

  return 0;
}
