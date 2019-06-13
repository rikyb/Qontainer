#include "tequila.h"
#include <QDate>

Tequila::Tequila(QString n,unsigned int g,QString p,QString m,QString t,unsigned int i):Distillato (n,g,p,m),tipo(t),annata(i){}

QString Tequila::getTipo()const{
    return tipo;
}

unsigned int Tequila::getAnnata()const{
    return annata;
}

unsigned int Tequila::GetInvecchiatura()const{
    return QDate::currentDate().year()-annata;
}

Tequila* Tequila::clone()const{
    return new Tequila(*this);
}

bool Tequila::operator==(const Alcolico& a) const{
    Tequila* r=dynamic_cast<Tequila*>(&const_cast<Alcolico&>(a));
    if(r)
        return static_cast<Distillato*>(const_cast<Tequila*>(this))==static_cast<Distillato*>(r)&&getTipo()==r->getTipo()&&GetInvecchiatura()==r->GetInvecchiatura() ;
    return false;
}
