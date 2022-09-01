#include <cmath>
#include <iostream>
#include <vector>

int Maximo(const std::vector<int>& vec, int inicio, int final) {
  // Caso Base
  if (inicio == final) {
    // En este caso estamos devolviendo el último elemento
    return vec[inicio];
  }
  if (vec[inicio] >= Maximo(vec, inicio + 1, final)) {
    return vec[inicio];
  } else {
    return (Maximo(vec, inicio + 1, final));
  }
}

int main() {
  std::vector<int> vector;
  vector.emplace_back(20);
  vector.emplace_back(6);
  vector.emplace_back(2);
  vector.emplace_back(8);
  vector.emplace_back(22);
  vector.emplace_back(0);

  std::cout << Maximo(vector, 0, vector.size() - 1) << std::endl;
}