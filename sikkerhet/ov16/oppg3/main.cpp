#include <iostream>

using namespace std;

int main() {
  char meld[] = {22, 17, 19, 5, 21, 24, 20, 17, 24, 24, 17, 1, 20, 13, 14, 21, 18, 18};
  for(int k = 0; k < 29; ++k){
    cout << "k: " << k << "  --->  ";
    for(int l = 0; l < 18; ++l){
      cout << (char)(meld[l]+65 +k);
    }
    cout << endl;
   
  }
}
