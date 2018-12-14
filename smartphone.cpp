#include "smartphone.h"

Smartphone::Smartphone(double P,
                       QString R,
                       bool T,
                       bool J,
                       bool Ta,
                       bool W):
    Pollici(P),
    Rete(R),
    Tastiera(T),
    Jack(J),
    Tablet(Ta),
    Wifi(W){
}

//getter
double Smartphone:: get_Pollici()const{
    return Pollici;
}

QString Smartphone::get_Rete()const{
    return Rete;
}

bool Smartphone::get_Tastiera() const{
    return Tastiera;
}

bool Smartphone::get_Jack()const{
    return Jack;
}

bool Smartphone::get_Tablet()const{
    return Tablet;
}
bool Smartphone::get_Wifi() const{
    return Wifi;
}

//setter

void Smartphone::set_Pollici(double P){
    Pollici=P;
}

void Smartphone::set_Rete(QString R){
    Rete=R;
}

void Smartphone::set_Tastiera(bool T){
    Tastiera=T;
}

void Smartphone::set_Jack(bool J){
    Jack=J;
}

void Smartphone::set_Tablet(bool Ta){
    Tablet=Ta;
}

void Smartphone::set_Wifi(bool W){
    Wifi=W;
}

Smartphone* Smartphone::clone() const{
    return new Smartphone(*this);
}

void Smartphone::sconto(float less){
    set_Prezzo(get_Prezzo()*((100-less)/100));                      //test
}


void Smartphone::estendi_garanzia(unsigned int warranty){
     set_Garanzia(get_Garanzia()+warranty);                          //test
}

