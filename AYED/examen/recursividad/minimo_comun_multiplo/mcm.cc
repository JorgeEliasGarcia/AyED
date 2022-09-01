#include <iostream>


int Mcm(const int a, const int b, int divisor = 2) {
  if (divisor >= a*b) {
      return a*b; 
  }
  if (divisor % a == 0 && divisor % b == 0) {
      return divisor; 
  }
  return Mcm(a, b, divisor + 1); 
}

int main() {

  std::cout << Mcm(2, 9) << std::endl; 
}