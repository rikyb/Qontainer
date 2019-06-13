#include "vino.h"

Vino::Vino(QString n,unsigned int g,QString p,QString f,unsigned int a,QString t,bool fr):Fermentato(n,g,p,f),annata(a),tipo(t),frizzante(fr){}

unsigned int Vino::getAnnata()const{
    return annata;
}

QString Vino::getTipo()const{
    return tipo;
}

bool Vino::getFrizzante()const{
    return frizzante;
}

Vino* Vino::clone()const{
    return new Vino(*this);
}

bool Vino::operator==(const Alcolico& a) const
{
    Vino* v=dynamic_cast<Vino*>(&const_cast<Alcolico&>(a));
    if(v)
        return static_cast<Fermentato*>(const_cast<Vino*>(this))==static_cast<Fermentato*>(v)&&getAnnata()==v->getAnnata()&&getFrizzante()==v->getFrizzante()&&getTipo()==v->getTipo();
    return false;
}

