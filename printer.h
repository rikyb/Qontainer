#ifndef PRINTER_H
#define PRINTER_H
#include<QString>
#include"articolo.h"

class Printer : public Articolo
{
private:
    bool Colors;
    QString Type;
    QString Print_format;
    unsigned int Page_min;

public:
    Printer(bool=false,
            QString=QString(),
            QString=QString(),
            unsigned int=0
            );

    bool get_Colors() const;
    QString get_Type() const;
    QString get_Print_format() const;
    unsigned int get_Page_min() const;

    void set_Colors(bool);
    void set_Type(QString&);
    void set_Print_format(QString&);
    void set_Page_min(unsigned int&);

    Printer* clone()const;
    unsigned int sconto();
    unsigned int estendi_garanzia();

    //~Printer();


};

#endif // PRINTER_H
