#include "smartphone.h"

Smartphone::Smartphone(double P,
                       QString R,
                       bool T,
                       bool J,
                       bool Ta,
                       bool W):
    inch(P),
    network(R),
    keyboard(T),
    jack(J),
    tablet(Ta),
    wifi(W){
}

//getter
double Smartphone:: get_inch()const{
    return inch;
}

QString Smartphone::get_network()const{
    return network;
}

bool Smartphone::get_keyboard() const{
    return keyboard;
}

bool Smartphone::get_jack()const{
    return jack;
}

bool Smartphone::get_tablet()const{
    return tablet;
}
bool Smartphone::get_wifi() const{
    return wifi;
}

//setter

void Smartphone::set_inch(double P){
    inch=P;
}

void Smartphone::set_network(QString R){
    network=R;
}

void Smartphone::set_keyboard(bool T){
    keyboard=T;
}

void Smartphone::set_jack(bool J){
    jack=J;
}

void Smartphone::set_tablet(bool Ta){
    tablet=Ta;
}

void Smartphone::set_wifi(bool W){
    wifi=W;
}

Smartphone* Smartphone::clone() const{
    return new Smartphone(*this);
}

void Smartphone::discount(float less){
    set_price(get_price()*((100-less)/100));                      //test
}


void Smartphone::extend_warranty(unsigned int warranty){
     set_warranty(get_warranty()+warranty);                          //test
}

