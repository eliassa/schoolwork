#include <iostream>
#include <string>
using namespace std;

int main() {
  string ord1;
  string ord2;
  string ord3;
  cout<< "skriv inn tre ord, avslutt hvert ord med enter"<< endl;
  cin >>ord1;
  cin >>ord2;
  cin >>ord3;
  
  string setning = ord1 + " " + ord2 + " " +ord3 + ".";
  cout << setning <<endl;
  cout<< ord1 << ": " <<ord1.length()<<endl;
  cout<< ord2 << ": " <<ord2.length()<<endl;
  cout<< ord3 << ": " <<ord3.length()<<endl;
  
  string setning2 = setning;
  setning2[9] = 'x';
  setning2[10] = 'x';
  setning2[11] = 'x';
  
  cout << setning<<endl;
  cout << setning2<<endl;
  
  string begynnelsen ="";
  if(setning.size() >=5){
    for(int i =0; i<5; ++i){
      begynnelsen+=setning[i];
    }
  }else{
    for(int i =0; i<(int)setning.size(); ++i){
      begynnelsen+=setning[i];
    }
  }
  cout<<begynnelsen<<endl;
  
  
  if(setning.find("hallo") != string::npos){
    cout << "setning inneholder hallo" << endl;
  }else{
    cout << "setning inneholder IKKE hallo" << endl;
  }
  
  
  size_t pos = setning.find("er", 0);
  while (pos != string::npos){
      cout<< "'er' funnet på: " << pos <<endl;
      pos = setning.find("er", pos+1);
  }
  
}


