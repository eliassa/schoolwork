#include <iostream>
using namespace std;

int finnSum(const int *tabell, int antallElementer){
  int sum = 0;
  for(int i = 0; i < antallElementer; ++i){
    sum+=tabell[i];
  }
  return sum;
}

int main() {
  int tabell[20];
  //int *peker10 = &tabell[10];
  //int *peker15 = &tabell[15];
  for(int i =0; i < 20; ++i){
    tabell[i] = i;
  }
  
  cout << "10 første: " << finnSum(tabell, 10)<< endl;
  cout << "5 neste: " << finnSum(&tabell[10], 5)<<endl;
  cout<< "5 siste: " << finnSum(&tabell[15], 5)<<endl;
  
}
