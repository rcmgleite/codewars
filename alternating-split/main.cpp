#include <string>
#include <iostream>
#include <functional>

class OddEvenGetter {
public:
  using f_type = std::function<bool(int)>;
  explicit OddEvenGetter(f_type f) : f_(f) {}

  std::string operator()(const std::string& str) {
    std::string ret;
    for (int i = 1; i <= str.size(); i++) {
      if (f_(i)) {
        ret += str[i - 1];
      }
    }

    return ret;
  }

private:
  f_type f_;
};

bool odd (int n) {
  return n % 2 != 0;
}

std::string getOdd (const std::string& str) {
  auto oddGetter = OddEvenGetter(odd);
  return oddGetter(str);
}

bool even (int n) {
  return n % 2 == 0;
}

std::string getEven (const std::string& str) {
  auto evenGetter = OddEvenGetter(even);
  return evenGetter(str);
}

class EncryptDecrypt {
public:
  using f_type = std::function<std::string(const std::string&)>;
  explicit EncryptDecrypt (f_type f) : f_(f) { }

  std::string operator()(const std::string& str, int n) {
    std::string ret(str);
    while (n > 0) {
      ret = f_(ret);
      n--;
    }

    return ret;
  }

private:
  f_type f_;
};

std::string doEncrypt (const std::string& text) {
  return getEven(text) + getOdd(text);
}

std::string encrypt (const std::string& text, int n) {
  auto encrypter = EncryptDecrypt(doEncrypt);
  return encrypter(text, n);
}

std::string doDecrypt (const std::string& encryptedText) {
  std::string ret;
  int firstHalfRunner = 0;
  int stringHalf = encryptedText.size() / 2;
  int secondHalfRunner = stringHalf;
  while (firstHalfRunner < stringHalf) {
    ret.push_back(encryptedText[secondHalfRunner]); 
    secondHalfRunner++;
    ret.push_back(encryptedText[firstHalfRunner]); 
    firstHalfRunner++;
  }

  if (secondHalfRunner < encryptedText.size()) {
    ret.push_back(encryptedText[secondHalfRunner]); 
  }

  return ret;
}

std::string decrypt (const std::string& encryptedText, int n) {
  auto decrypter = EncryptDecrypt(doDecrypt);
  return decrypter(encryptedText, n);
}

int main () {
  using namespace std;
  int nIter = 1;
  string encrypted = encrypt("This kata is very interesting!", nIter);
  cout << "Encrypted: " << encrypted << endl; 
  string decrypted = decrypt(encrypted, nIter);
  cout << "Decrypted: " << decrypted << endl;

  return 0;
}
