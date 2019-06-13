#include "gin.h"

Gin::Gin(QString n,unsigned int g,QString p,QString m,QString t):Distillato (n,g,p,m),tipo(t){}

QString Gin::getTipo()const{
    return tipo;
}

Gin* Gin::clone() const{
    return new Gin(*this);
}

bool Gin::operator==(const Alcolico& a)const{
    Gin* g=dynamic_cast<Gin*>(&const_cast<Alcolico&>(a));
    if(g)
        return static_cast<Distillato*>(const_cast<Gin*>(this))==static_cast<Distillato*>(g)&&getTipo()==g->getTipo() ;
    return false;
}
