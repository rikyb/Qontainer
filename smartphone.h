#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include<apparecchio.h>
#include<QString>

class Smartphone: public Apparecchio
{
private:

    double Pollici;
    QString Rete;
    bool Tastiera;
    bool Jack;
    bool Tablet;
    bool Wifi;

public:
    Smartphone(double=0,
               QString=QString(),
               bool=false,
               bool=false,
               bool=false,
               bool=false
            );

    double get_Pollici()const;
    QString get_Rete()const;
    bool get_Tastiera()const;
    bool get_Jack()const;
    bool get_Tablet()const;
    bool get_Wifi()const;

    void set_Pollici(double);
    void set_Rete(QString);
    void set_Tastiera(bool);
    void set_Jack(bool);
    void set_Tablet(bool);
    void set_Wifi(bool);

    Smartphone* clone() const;
    void sconto(float);
    void estendi_garanzia(unsigned int);

    //~Smartphone()=default;


};

#endif // SMARTPHONE_H
