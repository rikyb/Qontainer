#ifndef TEQUILA_H
#define TEQUILA_H
#include "distillato.h"

class Tequila:public Distillato
{
private:
    unsigned int annata;
    QString tipo;
public:
    Tequila(QString n,unsigned int g,QString p,QString m,QString t,unsigned int i);
    QString getTipo()const;
    unsigned int getAnnata()const;
    unsigned int GetInvecchiatura()const;
    Tequila* clone()const;
    bool operator==(const Alcolico&)const;
};

#endif // TEQUILA_H
