#ifndef VINO_H
#define VINO_H
#include "fermentato.h"

class Vino:public Fermentato
{
private:
    unsigned int annata;
    QString tipo;
    bool frizzante;
public:
    Vino(QString n,unsigned int g,QString p,QString f,unsigned int a,QString t,bool fr);
    unsigned int getAnnata()const;
    QString getTipo() const;
    bool getFrizzante() const;
    Vino* clone() const;
    bool operator==(const Alcolico&)const;
};

#endif // VINO_H
