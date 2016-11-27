#include "broek.h"
#include <iostream>
#include <string>

using namespace std;

void skriv(const string &tekst, const Broek &Broek);

// //Oppgave 1a2
Broek operator-(const int heltall, const Broek broek);

int main() {
  Broek a(10, 20);
  Broek b(3, 4);
  Broek c;
  c.settBroek(5);
  Broek d = a / b;

  skriv("a = ", a);
  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  b += a;
  ++c;
  d *= d;

  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  c = a + b - d * a;
  c = -c;

  skriv("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  skriv("b = ", b);
  
  //Oppgave 1a
  Broek broekA(25,40);
  
  skriv("broekA = ", broekA);
  skriv("broekA = ", broekA-5);
  
  //Oppgave 1a2
  skriv("broekA = ", 5-broekA);
  
  
  //1b(Teori)
  Broek broekB(35,8);
  skriv("5 - 3 - broekA - 7 - broekB= ", 5 - 3 - broekA - 7 - broekB);

  return 0;
}

void skriv(const string &tekst, const Broek &broek) {
  cout << tekst << broek.finnTeller() << " / ";
  cout << broek.finnNevner() << endl;
}

// //Oppgave 1a2
Broek operator-(const int heltall, const Broek broek){
  // return -broek-(-heltall); //er det lettere å skrive, men kanskje treigere?  
  Broek hjelp = Broek(); 
  hjelp.settBroek(heltall*broek.finnNevner()-broek.finnTeller(), broek.finnNevner());
  return hjelp;
}