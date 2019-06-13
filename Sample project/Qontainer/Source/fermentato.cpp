#include "fermentato.h"

Fermentato::Fermentato(QString f):Alcolico(),fermentazione(f){}
Fermentato::Fermentato(QString n,unsigned int g,QString p,QString f):Alcolico (n,g,p),fermentazione(f){}

QString Fermentato::getFermentazione()const {
    return fermentazione;
}
