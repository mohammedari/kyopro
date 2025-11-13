#include <iostream>
#include <vector>

void output(const std::vector<int>& child_count) {
  for (auto c : child_count)
    std::cout << c << std::endl;
}

int main() {
  std::string S;
  std::cin >> S;

  auto N = S.length();

  // find RL pair
  std::vector<int> rl_pairs;
  for (auto i = 0; i < N - 1; ++i) {
    if (S[i] == 'R' && S[i + 1] == 'L')
      rl_pairs.push_back(i);
  }

  // for each RL pair, find successive R in left and L in right
  std::vector<int> successive_r_in_left(rl_pairs.size());
  std::vector<int> successive_l_in_right(rl_pairs.size());
  for (int i = 0;  auto pair_left : rl_pairs) {
    for (auto l = pair_left - 1; 0 <= l; --l) {
      if (S[l] == 'R')
        ++successive_r_in_left[i];
      else
        break;
    }
    for (auto r = pair_left + 2; r < N; ++r) {
      if (S[r] == 'L')
        ++successive_l_in_right[i];
      else
        break;
    }

    ++i;
  }

  std::vector<int> answer(N);
  for (int i = 0; auto pair_left : rl_pairs) {
    answer[pair_left] = 1 + successive_r_in_left[i] / 2 + (successive_l_in_right[i] / 2 + successive_l_in_right[i] % 2);
    answer[pair_left + 1] = 1 + (successive_r_in_left[i] / 2 + successive_r_in_left[i] % 2) + (successive_l_in_right[i] / 2);

    ++i;
  }

  output(answer);
  return 0;
}

int main_tle() {
  std::string S;
  std::cin >> S;

  auto N = S.length();
  std::vector<int> child_count(N, 1);
  std::vector<int> previous_child_count(N);

  int round = 0;
  while (true)
  {
    std::vector<int> next_child_count(N);
    for (auto i = 0; i < N; ++i) {
      auto c = S[i];

      if (c == 'L')
        next_child_count[i - 1] += child_count[i];
      else
        next_child_count[i + 1] += child_count[i];
    }

    if (previous_child_count == next_child_count) {
      if (0 == round % 2)
        output(child_count);
      else
        output(next_child_count);

      break;
    } 

    previous_child_count = child_count;
    child_count = next_child_count;
    ++round;
  }

  return 0;
}
