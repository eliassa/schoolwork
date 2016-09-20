
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>


using namespace std;


int main() {
  boost::multiprecision::cpp_int b(66514), p(17), m(86609);
  // (p-th power of b) mod m = (3rd power of 2) mod 4 = 8 mod 4 = 0
  cout <<boost::multiprecision::powm(b, p, m) << endl;
}