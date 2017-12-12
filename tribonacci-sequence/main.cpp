#include <vector>
#include <iostream>

std::vector<int> tribonacci(std::vector<int> signature, int n) {
  if (n < 0) {
    return std::vector<int>();
  }

  std::vector<int> result(n);
  for (int i = 0; i < n; i++) {
    if (i < 3) {
      result[i] = signature[i];
    } else {
      result[i] = result[i - 3] + result[i - 2] + result[i - 1];
    }
  }
  
  return result;
}

int main () {
  using namespace std;
  auto ret = tribonacci(std::vector<int>({0, 0, 1}), 10);
  for (auto& v : ret) {
    cout << v << " ";
  }
  cout << endl;
  
  return 0;
}
