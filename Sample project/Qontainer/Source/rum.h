#ifndef RUM_H
#define RUM_H
#include "distillato.h"

class Rum:public Distillato
{
private:
    QString tipo;
    unsigned int annata;
public:
    Rum(QString n,unsigned int g,QString p,QString m,QString t,unsigned int a);
    unsigned int getAnnata() const;
    QString getTipo() const;
    Rum* clone()const;
    bool operator==(const Alcolico&)const;
};

#endif // RUM_H
