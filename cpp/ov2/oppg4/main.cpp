#include <iostream>

int main() {
  int a=5;
  int b;   //må innitialisere variabelen b
  int *c=&b;
  a = b + *c; //*a og *b krever pekeroperand, endret til a og b
  b = 2; //&b kan ikke tilegnes, endret til b
}
