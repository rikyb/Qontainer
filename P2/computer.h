#ifndef COMPUTER_H
#define COMPUTER_H
#include<apparecchio.h>


class Computer :public Device
{
private:
    bool laptop; //is it a laptop computer or not
    double inch; //if laptop computer then need the monitor size

public:
    Computer(bool=false,
             double=0);

    bool get_laptop() const;
    double get_inch() const;

    void set_laptop(bool);
    void set_inch(double);

    Computer* clone() const;
    void discount(float);
    void extend_warranty(unsigned int);

    //virtual ~Articolo()=default;
};

#endif // COMPUTER_H
