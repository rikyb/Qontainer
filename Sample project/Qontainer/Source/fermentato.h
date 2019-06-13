#ifndef FERMENTATO_H
#define FERMENTATO_H
#include "alcolico.h"


class Fermentato: public Alcolico
{
private:
    QString fermentazione;
public:
    Fermentato(QString f="");
    Fermentato(QString n,unsigned int g,QString p,QString f);
    QString getFermentazione()const;
};

#endif // FERMENTATO_H
