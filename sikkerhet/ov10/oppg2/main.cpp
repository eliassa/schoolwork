 #include <iostream>
#include <string>
#include <random>
#include <sstream>
using namespace std;
const string meld = "114b70745a521c57371f7a245d6440662d49";


int main(){
  string nokkel = "Dette er en noekkel";
  //Lag seed fra nøkkel
  seed_seq seed(nokkel.begin(), nokkel.end());
  
  //Velger pseudo-tilfeldig tall med gitt seed
  minstd_rand0 generator(seed);
  
  //velger distribusjon
  uniform_int_distribution<char> distribution;
  
  
  
  
  string dekrypt = "";
  for(int i = 0; i <(int)meld.size()-1; i++){
    string hexStr = "";
    hexStr += meld.at(i);
    hexStr += meld.at(i+1);
    cout << hexStr;
    
    int t = (int)distribution(generator);
    int b = 0;
    stringstream ss;
    ss << hex << hexStr;
    ss >> b;
    cout << " = " << b << endl;
    //ss << hex << (b^t);
    //ss >> g;
    int g= (b^t);
    dekrypt += (char)g;
    i++;
  }
    cout << dekrypt <<endl;
    
}
