#include <iostream>
#include <string>
using namespace std;

class CaeserCipher {
public:
  string secret;
  int factor;

  // constructor
  CaeserCipher(string s, int f) {
    secret = s;
    factor = f;
  }
  
  // function to encrypt
  string encrypt() {
      string cipher_text;
      for (int i = 0; i < secret.length(); i++) {
        cipher_text += char(int(secret[i]) + (factor % 26)); // fix ascii overflow
      }
      return cipher_text;
  }
  
  // function to decrypt
  string decrypt() {
    string plain_text;
    for (int i = 0; i < secret.length(); i++) {
        plain_text += char(int(secret[i]) - (factor % 26)); // fix ascii overflow
      }
      return plain_text;  
  }
};

int main() {
  string secret = "you seeing this from future";
  CaeserCipher Mycipher(secret, 50);
  cout << Mycipher.decrypt() << endl;
  
  return 0;
}
