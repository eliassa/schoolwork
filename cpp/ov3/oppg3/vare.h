//
// vare.h
//

#include<string>
using namespace std;
const double moms = 0.25;
class Vare{
public:
Vare(string navn, int varenr, double pris) :
  varenavn(navn), varenr(varenr), pris(pris){}
  
  string finnNavn(){return varenavn;}
  int finnVarenr(){return varenr;}
  double finnPrisPrEnhet() {return pris;}
  void settPris(double nyPris) {pris = nyPris;}
  double finnPrisUtenMoms(int antall){return antall*pris;}
  double finnPrisMedMoms(int antall){return antall*pris*moms;}
                                    
private:
  string varenavn;
  int varenr;
  double pris;
};


  
  