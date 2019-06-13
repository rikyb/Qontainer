#ifndef GIN_H
#define GIN_H
#include "distillato.h"

class Gin:public Distillato
{
private:
    QString tipo;
public:
    Gin(QString n,unsigned int g,QString p,QString m,QString t);
    QString getTipo() const;
    Gin* clone() const;
    bool operator==(const Alcolico& a)const;
};

#endif // GIN_H
