#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

long hashe(long a);

int main() {
  long a;
  cin>>a;
  long x = hashe(a);
  
  int antall = 0;
  for(int i = 10000; i < 99999; i++){
    if(a != i && x == hashe(i)){
      antall++;
      cout<<"kollisjon mellom " << a<< " og " << i<< ". Begge blir " <<x<<endl; 
    }
    
  }
  cout<<"ferdig! antall kollisjoner: " << antall <<endl;
  
}

long hashe(long a){
  long opplegg = pow(a,2);
  stringstream ss;
  ss << opplegg;
  long midt = ss.str().size()/2-1;
  return stoi(ss.str().substr(midt, 3));
}