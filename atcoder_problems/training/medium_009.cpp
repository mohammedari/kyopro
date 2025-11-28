#include <iostream>
#include <vector>
#include <numeric>

int Gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int A, B, C;
  std::cin >> A >> B >> C;

  int g = Gcd(A, B);
  if (C % g == 0)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;

  return 0;
}
