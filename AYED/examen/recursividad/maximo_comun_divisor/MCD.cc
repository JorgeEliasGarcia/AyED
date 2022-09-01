#include <iostream>

int MCD(const int a, const int b, int divisor = 2) {
  // Caso base
  if (divisor >= a || divisor >= b) {
    return 1;
  }
  if (a % divisor == 0 && b % divisor == 0) {
    return divisor * MCD(a / divisor, b / divisor, divisor);
  }
  return MCD(a, b, divisor + 1);
}

int main() {
  std::cout << MCD(35, 25) << std::endl;

  return 0;
}