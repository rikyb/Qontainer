#include "computer.h"
#include "QDebug"
Computer::Computer(bool F,
                   double P):
    Fisso(F),
    Pollici(P){
}

//getter
bool Computer::get_Fisso()const{
    return Fisso;
}

double Computer::get_Pollici()const{
    return Pollici;
}

//setter
void Computer::set_Fisso(bool F){
    Fisso=F;
}

void Computer::set_Pollici(double P){
    Pollici=P;
}

Computer* Computer::clone() const{
    return new Computer(*this);
}

void Computer::sconto(float less){
    set_Prezzo(get_Prezzo()*((100-less)/100));                   //test
}

void Computer::estendi_garanzia(unsigned int warranty){
    set_Garanzia(get_Garanzia()+warranty);                         //test
}

