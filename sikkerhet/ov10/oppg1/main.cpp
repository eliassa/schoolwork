#include <iostream>
#include <string>
using namespace std;
const string meld = "judwxohuhuCghuhCkduCixqqhwCphoglqjhqD"; 
int main() {
  //antar at C tilsvarer mellomrom:
  string test = "";
  for(int i = 0; i < (int)meld.size(); ++i){
    char e = (char)(meld.at(i)) - 35;
    test += e;
  }
  cout << test;
}
