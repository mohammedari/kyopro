#include <iostream>
#include <vector>
#include <numeric>

int main() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::string> S(H);
  for (auto i = 0; i < H; ++i) {
    std::cin >> S[i];
  }

  std::vector<std::vector<int>> ans(H);
  for (auto h = 0; h < H; ++h)
    ans[h] = std::vector<int>(W, 0);

  for (auto h = 0; h < H; ++h) {
    for (auto w = 0; w < W; ++w) {
      if (S[h][w] == '#') {

        // Placeholder for '#'
        ans[h][w] = -1;

        // We increment surrounding cells for each '#'
        for (auto dh = -1; dh <= 1; ++dh) {
          for (auto dw = -1; dw <= 1; ++dw) {
            auto nh = h + dh;
            auto nw = w + dw;
            if (0 <= nh && nh < H && 0 <= nw && nw < W) {
              if (S[nh][nw] != '#') {
                ++ans[nh][nw];
              }
            }
          }
        }

      }
    }
  }

  for (auto h = 0; h < H; ++h) {
    for (auto w = 0; w < W; ++w) {
      if (ans[h][w] == -1) {
        std::cout << '#';
      }
      else {
        std::cout << ans[h][w];
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
