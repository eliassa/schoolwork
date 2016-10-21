#include <iostream>
#include <vector>
using namespace std;


int main() {
  
  vector<int> meld = {4, 5, 15, 1, 4, 26, 1, 26, 26, 1, 15, 14, 13, 14, 1, 6, 13, 14, 1, 15, 6, 13, 14, 1, 15, 26, 1, 26, 26, 1, 15, 6, 13, 14, 1, 15, 14, 13, 14, 1,15, 20, 13, 15, 0, 13, 4, 23, 12, 15, 10, 20, 1, 4, 10, 20, 1, 14, 1, 27,15, 20, 20, 1, 9, 27, 1, 4, 14, 24, 22, 9, 18, 13, 15, 27, 13, 15, 24, 4};
  for(int number: meld){
  switch (number){
  case 1:
    cout << "e";
    break;
  case 15:
    cout << "r";
    break;
  case 14:
    cout << "k";
    break;
  case 13:
    cout << "a";
    break;
  case 26:
    cout << "p";
    break;
  case 4:
    cout << "n";
    break;
  case 6:
    cout << "b";
    break;
  case 5:
    cout << "å";
    break;
  case 20:
    cout << "t";
    break;
  case 0:
    cout << "h";
    break;
  case 23:
    cout << "f";
    break;
  case 12:
    cout << "ø";
    break;
  case 10:
    cout << "s";
    break;
  case 27:
    cout << "g";
    break;
  case 24:
    cout << "i";
    break;
  case 18:
    cout << "m";
    break;
  case 9:
    cout << "o";
    break;
  case 22:
    cout << "l";
    break;
  default:
    cout << number;
    break;
  }
  };
  
}
