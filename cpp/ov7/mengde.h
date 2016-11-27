#ifndef MENGDE_DEFINERT
#define MENGDE_DEFINERT

#include <vector>
#include <string>

class Mengde {
private:
  std::vector <int> mengde;
public:
  // 2a tom mengde:
  Mengde();
  // Slik at vi sette inn en vector som start:
  Mengde(std::vector <int> m);
  
  // 2b Union summen:
  Mengde operator+(const Mengde &denAndre) const;
  // 2c Nytt tall:
  Mengde &operator+=(const int nyttTall);
  // 2d Sette en mengde lik en annen
  Mengde &operator=(const Mengde &denAndre);
  
   std::string toString() const;
  
};


#endif