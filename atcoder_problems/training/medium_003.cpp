#include <iostream>
#include <vector>
#include <numeric>

int main() {
  std::string S;
  std::cin >> S;

  int64_t N = static_cast<int64_t>(S.length()) + 1;

  // Typcai solution is counting successive '<' from left and '>' from right.
  // The max of both element should be the answer.

  std::vector<int64_t> greater_successive_count_from_left(N);
  for (auto i = 1ll; i < N; ++i) {
    if (S[i - 1] == '<')
      greater_successive_count_from_left[i] = greater_successive_count_from_left[i - 1] + 1;
    else
      greater_successive_count_from_left[i] = 0;
  }

  std::vector<int64_t> lesser_successive_count_from_right(N);
  lesser_successive_count_from_right[N - 1] = 0;
  for (auto i = N - 2; 0 <= i; --i) {
    if (S[i] == '>')
      lesser_successive_count_from_right[i] = lesser_successive_count_from_right[i + 1] + 1;
    else
      lesser_successive_count_from_right[i] = 0;
  }

  int64_t sum = 0;
  for (auto i = 0ll; i < N; ++i) {
    sum += std::max(greater_successive_count_from_left[i], lesser_successive_count_from_right[i]);
  }

  std::cout << sum << std::endl;
  return 0;
}

// My original submission, which got WA
int main_wa() {
  std::string S;
  std::cin >> S;

  auto N = S.length() + 1;
  std::vector<int64_t> answer(N);

  answer[0] = 0;
  for (auto i = 1ll; i < N; ++i) {
    if (S[i - 1] == '<') {
      answer[i] = answer[i - 1] + 1;
    }

    // Count successive '>' from i
    int64_t successive_lesser_count = 0;
    for (auto j = i; j < N; ++j) {
      if (S[j] != '>')
        break;
      ++successive_lesser_count;
    }

    answer[i] = std::max(answer[i], successive_lesser_count);

    if (0 < successive_lesser_count) {
      // Note that we can go down to 0 at the end of successive '>'s
      answer[i + successive_lesser_count] = 0;
      for (auto j = 1ll; j < successive_lesser_count; ++j) {
        answer[i + successive_lesser_count - j] = answer[i + successive_lesser_count - j + 1] + 1;
      }
    }

    i += successive_lesser_count;
  }

  auto sum = std::accumulate(answer.begin(), answer.end(), 0ll);
  std::cout << sum << std::endl;
  return 0;
}
