#include "printer.h"

Printer::Printer(bool C,
                 QString T,
                 QString F,
                 unsigned int P):
    Colors(C),
    Type(T),
    Print_format(F),
    Page_min(P){
}

//getter
bool Printer::get_Colors() const{
    return Colors;
}

QString Printer::get_Type() const{
    return Type;
}

QString Printer::get_Print_format() const{
    return Print_format;
}

unsigned int Printer::get_Page_min() const{
    return Page_min;
}

//setter

void Printer::set_Colors(bool C)
{
    Colors=C;
}

void Printer::set_Type(QString T)
{
    Type=T;
}

void Printer::set_Print_format(QString F)
{
    Print_format=F;
}

void Printer::set_Page_min(unsigned int P){
    Page_min=P;
}

//override
Printer* Printer::clone() const{
    return new Printer(*this);
}

void Printer::discount(float less){
    set_price(get_price()*((100-less)/100));
}

void Printer::extend_warranty(unsigned int warranty){
    set_warranty(get_warranty()+warranty);                    //test
}

/*
~Printer(){

}
*/
