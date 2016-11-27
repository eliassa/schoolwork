
#ifndef PAR_DEFINERT
#define PAR_DEFINERT

//Brude jeg bare ha alt dette over main? leste at man brude deklarere i header
//hvis man har template

template <typename A, typename B> class Par{
public:
  A forste;
  B andre;
  
  //2a
  Par(A forste, B andre):forste(forste),andre(andre){}
  
  //2b
  bool operator>(const Par &denAndre)const{
    return forste+andre > denAndre.forste + denAndre.andre;
  }
  
  //2c
  Par operator+(const Par &denAndre)const{
    return Par(forste +denAndre.forste, andre + denAndre.andre);
  }
  
};

#endif