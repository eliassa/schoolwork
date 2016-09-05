#include <iostream>
using namespace std;

int main() {
 double tall;
 double *peker = &tall;
 double &ref = tall;
 
 tall = 3.0;
 cout << tall<<endl;
 *peker = 4.0;
 cout << tall << endl;
 ref =5.0;
 cout<< tall <<endl;
}
