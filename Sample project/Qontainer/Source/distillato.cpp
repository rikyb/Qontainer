#include "distillato.h"

Distillato::Distillato(QString m):Alcolico (),matprima(m){}
Distillato::Distillato(QString n,unsigned int g,QString p,QString m):Alcolico (n,g,p),matprima(m){}

QString Distillato::getMat() const
{
    return matprima;
}
