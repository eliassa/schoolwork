#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<double> tall;
  tall.emplace_back(1.0);
  tall.emplace_back(1.1);
  tall.emplace_back(1.2);
  tall.emplace_back(1.3);
  tall.emplace_back(1.4);
  
  
  cout << tall.front() << "     " <<tall.back() <<endl;
  
  tall.emplace(tall.begin()+1, 1.05);
  
  for(auto it = tall.begin(); it != tall.end(); ++it){
    cout<< *it << endl;
  }
  cout<<endl;
  double finn = 1.2;
  if(find(tall.begin(), tall.end(), finn)!= tall.end()){
    cout<< "fant " << finn << " i tabellen!"<<endl;
  }else{
    
    cout<<"fant ikke " << finn << " i tabellen"<< endl;
  }
  
  
  
}
