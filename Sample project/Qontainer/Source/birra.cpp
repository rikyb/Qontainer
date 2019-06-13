#include "birra.h"

Birra::Birra(QString n, unsigned int g, QString p, QString f, QString cat, QString col):Fermentato (n,g,p,f),tipo(cat),colore(col){}

QString Birra::getColore()const{
    return colore;
}

QString Birra::getTipo()const{
    return tipo;
}

Birra* Birra::clone()const{
    return new Birra(*this);
}

bool Birra::operator==(const Alcolico& a) const
{
    Birra* v=dynamic_cast<Birra*>(&const_cast<Alcolico&>(a));
    if(v)
        return static_cast<Fermentato*>(const_cast<Birra*>(this))==static_cast<Fermentato*>(v)&&getTipo()==v->getTipo()&&getColore()==v->getColore();
    return false;
}
