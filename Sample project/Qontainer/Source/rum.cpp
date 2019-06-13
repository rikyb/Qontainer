#include "rum.h"

Rum::Rum(QString n,unsigned int g,QString p,QString m,QString t,unsigned int a):Distillato(n,g,p,m),tipo(t),annata(a){}

unsigned int Rum::getAnnata()const{
    return annata;
}

QString Rum::getTipo()const{
    return tipo;
}

Rum* Rum::clone()const{
    return  new Rum(*this);
}

bool Rum::operator==(const Alcolico& a) const{
    Rum* r=dynamic_cast<Rum*>(&const_cast<Alcolico&>(a));
    if(r)
        return static_cast<Distillato*>(const_cast<Rum*>(this))==static_cast<Distillato*>(r)&&getTipo()==r->getTipo()&&getAnnata()==r->getAnnata() ;
    return false;
}
