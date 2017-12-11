#include <set>
#include <string>
#include <iostream>

class TwoToOne {
public:
  static std::string longest(const std::string &s1, const std::string &s2) {
    std::set<char> s;
    for (auto& c : s1) {
      s.insert(c);
    }

    for (auto& c : s2) {
      s.insert(c);
    }

    std::string ret;
    for (auto itr = s.begin(); itr != s.end(); ++itr) {
      ret += *itr;
    }

    return ret;
  }
};

int main () {
  using namespace std;
  cout << TwoToOne::longest("aretheyhere", "yestheyarehere") << endl;
  cout << TwoToOne::longest("loopingisfunbutdangerous", "lessdangerousthancoding") << endl;
  return 0;
}
