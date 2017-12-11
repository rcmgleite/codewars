#include <map>
#include <iostream>

size_t duplicateCount (const char* in) {
  char* walker = const_cast<char*>(in);
  std::map<char, size_t> m;
  while(*walker) {
    m[std::tolower(*walker)]++;
    walker++;
  }

  size_t counter = 0;
  for (auto itr = m.begin(); itr != m.end(); ++itr) {
    if (itr->second > 1) {
      counter++;
    }
  }

  return counter;
}

int main () {
  using namespace std;
  cout << duplicateCount("abcde") << endl;
  cout << duplicateCount("aabbcde") << endl;
  cout << duplicateCount("aabBcde") << endl;
  cout << duplicateCount("indivisibility") << endl;
  cout << duplicateCount("Indivisibilities") << endl;
  cout << duplicateCount("aA11") << endl;
  cout << duplicateCount("ABBA") << endl;
  return 0;
}
