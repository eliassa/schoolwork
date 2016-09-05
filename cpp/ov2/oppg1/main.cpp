#include <iostream>
using namespace std;
int main() {
  int i =3;
  int j =5;
  int *p = &i;
  int *q = &j;
  
  *p = 7;
  *q += 4;
  *q = *p+1;
  p=q;
  
  cout << *p<< " "<<*q <<endl;
  
    cout << "variabel    verdi     adresse"<< endl;
    cout << "i            "<<i << "         " << (long)&i<<endl;
    cout << "j            "<<j << "         " <<(long) &j<<endl;
    cout << "*p           "<<*p << "         " << (long)&*p<<endl;
    cout << "*q           "<<*q << "         " << (long)&*q<<endl;
}
