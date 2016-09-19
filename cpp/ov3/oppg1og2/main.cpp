#include <iostream>

using namespace std;

const double pi = 3.141592;

class Sirkel {
 public:
   Sirkel(double startRadius);// stor S
   int finnAreal() const;
   double finnOmkrets() const;
   
   private://kolon
     double radius;//
     
}; //semikolon

// ==> Implementasjon av klassen Sirkel
Sirkel::Sirkel(double startRadius) ://fjærnet private
  radius(startRadius) {} //endret fra startRadius til radius
  
int Sirkel::finnAreal() const{ //la til const
 return pi * radius * radius;
}
double Sirkel::finnOmkrets() const { //la til double
 double omkrets = 2.0 * pi * radius; //la til double
 return omkrets;
} 

int main() {
  Sirkel enSirkel(5);// la til Sirkel
  int arealet = enSirkel.finnAreal(); //la til int
  cout << "Arealet er lik " << arealet << endl; // la til arealet
  double omkretsen = enSirkel.finnOmkrets(); //la til enSirkel
  cout << "Omkretsen er lik " << omkretsen << endl;
  return 0;
}

