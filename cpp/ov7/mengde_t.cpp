#include "mengde.h"
#include <iostream>

using namespace std;

void skriv(const string &tekst,const Mengde &mengde);

int main(){
  vector<int> numbers = {1,4,3}; 
  Mengde tomMengde;
  Mengde enMengde(numbers);
  
  skriv ("Skriv ut tomMengde: ", tomMengde);
  skriv ("Skriv ut enMengde: ", enMengde);
  
  skriv ("Skriv ut tomMengde+=4: ", tomMengde+=4);
  skriv ("Skriv ut tomMengde+=7: ", tomMengde+=7);
  
  // set sorterer
  skriv ("Skriv ut enMengde+tomMengde: ", (enMengde+tomMengde));
  skriv ("Skriv ut enMengde: ", enMengde);
  
  skriv ("Skriv ut enMengde=enMengde+tomMengde: ", (enMengde=enMengde+tomMengde));
  skriv ("Skriv ut enMengde: ", enMengde);
  
  return 0;
}

void skriv(const string &tekst,const Mengde &mengde){
  cout << tekst << mengde.toString()<<endl;
}