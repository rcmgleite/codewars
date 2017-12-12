#include <vector>
#include <numeric>
#include <iostream>

typedef unsigned long long ull;
class SumFct {
public:
  static ull perimeter(int n) {
    auto fib = SumFct::fibonacci(n + 1);
    return (ull)4 * std::accumulate(fib.begin(), fib.end(), (ull)0);
  }
 private:
  static std::vector<ull> fibonacci(int n) {
    if (n <= 0) {
      return std::vector<ull>();
    } else if (n == 1) {
      return std::vector<ull>({1});
    } else if (n == 2) {
      return std::vector<ull>({1, 1});
    }

    std::vector<ull> ret(n, 0);
    ret[0] = 1;
    ret[1] = 1;
    fibonacciRec(n - 1, ret);
    return ret;
  }

  static void fibonacciRec(int n, std::vector<ull>& result) {
    if (n < 0 || result[n] != 0) {
      return;
    }
    
    fibonacciRec(n - 1, result);
    result[n] = result[n - 2] + result[n - 1];
  }
};

int main () {
  using namespace std;
  std::cout << SumFct::perimeter(46) << std::endl;
  return 0;
}
