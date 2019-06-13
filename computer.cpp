#include "computer.h"
#include "QDebug"
Computer::Computer(bool F,
                   double P):
    laptop(F),
    inch(P){
}

//getter
bool Computer::get_laptop()const{
    return laptop;
}

double Computer::get_inch()const{
    return inch;
}

//setter
void Computer::set_laptop(bool F){
    laptop=F;
}

void Computer::set_inch(double P){
    inch=P;
}

Computer* Computer::clone() const{
    return new Computer(*this);
}

void Computer::discount(float less){
    set_price(get_price()*((100-less)/100));                   //test
}

void Computer::extend_warranty(unsigned int warranty){
    set_warranty(get_warranty()+warranty);                         //test
}

