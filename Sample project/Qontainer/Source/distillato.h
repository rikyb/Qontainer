#ifndef DISTILLATO_H
#define DISTILLATO_H
#include "alcolico.h"

class Distillato:public Alcolico
{
private:
    QString matprima;
public:
    Distillato(QString m="");
    Distillato(QString n,unsigned int g,QString p,QString m);
    QString getMat() const;
};

#endif // DISTILLATO_H
