#include <iostream>
#include <vector>

bool IsPal(const std::vector<int>& vec, int left, int right) {
  if (vec[left] != vec[right]) {
    return false;
  }
  if (left >= right) {
    return true;
  } else {
    return IsPal(vec, left + 1, right - 1);
  }
}

int main() {
  std::vector<int> vector;
  vector.emplace_back(1);
  vector.emplace_back(2);
  vector.emplace_back(3);
  vector.emplace_back(5);
  vector.emplace_back(3);
  vector.emplace_back(2);
  vector.emplace_back(1);

  std::cout << IsPal(vector, 0, vector.size() - 1) << std::endl;
}