#ifndef BIRRA_H
#define BIRRA_H
#include "fermentato.h"

class Birra:public Fermentato
{
private:
    QString tipo;
    QString colore;
public:
    Birra(QString n,unsigned int g,QString p,QString f,QString cat,QString col);
    QString getColore() const;
    QString getTipo()const;
    Birra* clone()const;
    bool operator==(const Alcolico&)const;
};

#endif // BIRRA_H
