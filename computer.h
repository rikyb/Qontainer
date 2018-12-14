#ifndef COMPUTER_H
#define COMPUTER_H
#include<apparecchio.h>


class Computer :public Apparecchio
{
private:
    bool Fisso;
    double Pollici;

public:
    Computer(bool=false,
             double=0);

    bool get_Fisso() const;
    double get_Pollici() const;

    void set_Fisso(bool);
    void set_Pollici(double);

    Computer* clone() const;
    void sconto(float);
    void estendi_garanzia(unsigned int);

    //virtual ~Articolo()=default;
};

#endif // COMPUTER_H
