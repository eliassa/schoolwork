#include <iostream>
#include <cmath>
#include "par.h"

using namespace std;

//----------------------------------------------------------------------------
// Oppgave 1
//------------

/*
template<typename type>
bool likhet(type a, type b){
  cout <<"vanlig sammenlikning"<<endl;
  return a == b;
}
template<>
bool likhet<double>(double a, double b){
  cout <<"egendefinert sammenlikning"<<endl;
  double forskjell = 1e-5;             
  return abs(a-b) < forskjell;
}

int main() {
  cout << "likhet('tekst', 'tekst2'): " << likhet("tekst", "tekst2") << endl;
  cout << "likhet('tekst', 'tekst'): " << likhet("tekst", "tekst") << endl;
  cout << "likhet(1, 2): " << likhet(1, 2) << endl;
  cout << "likhet(1, 1): " << likhet(1, 1) << endl;
  cout << "likhet(1.0, 1.01): " <<likhet(1.0, 1.01) << endl;
  cout << "likhet(1.0, 1.000001): " <<likhet(1.0, 1.000001) << endl;
}
*/
//----------------------------------------------------------------------------
//Oppgave 2
//------------

int main() {
  Par<double, int> p1(3.5, 14);
  
  Par<double, int> p2(2.1, 7);
  
  cout << "p1: " << p1.forste << ", " << p1.andre << endl;
  cout << "p2: " << p2.forste << ", " << p2.andre << endl;
  
  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;
  
  auto sum = p1 + p2;
  cout << "Sum: " << sum.forste << ", " << sum.andre << endl;
}







