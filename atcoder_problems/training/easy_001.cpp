#include <iostream>

int main() {

  int A, B;
  std::cin >> A >> B;

  int num_outlet = 1;
  int num_tap = 0;
  while (num_outlet < B) {
    --num_outlet;
    num_outlet += A;

    ++num_tap;
  }

  std::cout << num_tap << std::endl;
  return 0;
}
