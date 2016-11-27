#include "mengde.h"
#include <set>

using namespace std;

// 2a tom mengde:
Mengde::Mengde(){}
// Slik at vi sette inn en vector som start:
Mengde::Mengde(vector <int> m):mengde(m){}

// 2b Union summen:
Mengde Mengde::operator+(const Mengde &denAndre) const{
  // kanskje dumt å bruke set, føler det er litt juks
  // set sorterer også så får ikke helt like resultater.
  set<int> tall(mengde.begin(),mengde.end());
  tall.insert(denAndre.mengde.begin(),denAndre.mengde.end());
  return Mengde(vector<int>(tall.begin(),tall.end()));
}

// 2c Nytt tall:
Mengde &Mengde::operator+=(const int nyttTall){
  for (const auto tall: mengde){
    if (tall == nyttTall){
      return *this;
    }
  }
  mengde.push_back(nyttTall);
  return *this;
}
// 2d Sette en mengde lik en annen
Mengde &Mengde::operator=(const Mengde &denAndre){
  mengde = denAndre.mengde;
  return *this;
}

 string  Mengde::toString() const{
  string res = "{";
  for (auto &tall: mengde){
    if (tall !=mengde.front()){
      res+="," + to_string(tall);
    } else{
      res+=to_string(tall);
    }
  }
  return res + "}";
}