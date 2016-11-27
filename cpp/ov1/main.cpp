#include <iostream>
#include <fstream>


using namespace std;

/*
** Oppgave 1a
int main() {
  
  
  int ANTALL_DAGER= 5;
  int under10= 0;
  int mellom10og20 = 0;
  int over20= 0;
  int a;
  for(int i = 0; i < ANTALL_DAGER; ++i){
    cout << "temp nr " << i+1 <<":";
    cin >> a;
    if(a < 10)under10++;
    else if(a >=10 && a<=20) mellom10og20++;
    else over20++;
  }
  
  cout << "antall under 10:" << under10 <<endl;
  cout << "antall mellom 10 og 20:" << mellom10og20 << endl;
  cout << "antall over 20: " << over20 << endl;
 
  
  
}
***************************************************************/
 
 
/*
** Oppgave 1b
*/

void lesInnTemp(double temp[], int antall);


int main(){
  const int ANTALL_DAGER= 10;
  int under10= 0;
  int mellom10og20 = 0;
  int over20= 0;
  double temp[10];
  
  lesInnTemp(temp, ANTALL_DAGER);
  
  for(int i =0; i <ANTALL_DAGER; i ++){
    double a = temp[i];
    if(a < 10)under10++;
    else if(a >=10 && a<=20) mellom10og20++;
    else over20++;
  }
  
  cout << "antall under 10:" << under10 <<endl;
   cout << "antall mellom 10 og 20:" << mellom10og20 << endl;
   cout << "antall over 20: " << over20 << endl;
  
  
}

void lesInnTemp(double temp[], int antall){
  const char fil[] = "temp.txt";
  ifstream innfil;
  innfil.open(fil);
  if(!innfil){
    cout<<"Feil ved åpning av fil"<<endl;
    exit(EXIT_FAILURE);
  }
  
  for(int i = 0; i < antall; ++i){
    innfil>>temp[i];
  }
};