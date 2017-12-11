#include <iostream>
#include <vector>

class Kata {
public:
  std::vector<int> foldArray(const std::vector<int>& array, int runs) {
    std::vector<int> ret(array);

    while (runs) {
      ret = doFoldArray(ret);
      runs--;
    }

    return ret;
  }

private:
  std::vector<int> doFoldArray(const std::vector<int>& array) {
    int lowIdx = 0;
    int highIdx = array.size() - 1;
    
    std::vector<int> ret;
    while(lowIdx < highIdx) {
      ret.push_back(array[lowIdx] + array[highIdx]);
      lowIdx++;
      highIdx--;
    }

    if (lowIdx == highIdx) {
      ret.push_back(array[lowIdx]);
    }

    return ret;
  }
};

int main () {
  using namespace std;
  Kata kata;
  auto ret = kata.foldArray(vector<int>({-9, 9, -8, 8, 66, 23}), 1);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
