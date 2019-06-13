#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include<apparecchio.h>
#include<QString>

class Smartphone: public Device
{
private:

    double inch;
    QString network;
    bool keyboard;
    bool jack;
    bool tablet;
    bool wifi;

public:
    Smartphone(double=0,
               QString=QString(),
               bool=false,
               bool=false,
               bool=false,
               bool=false
            );

    double get_inch()const;
    QString get_network()const;
    bool get_keyboard()const;
    bool get_jack()const;
    bool get_tablet()const;
    bool get_wifi()const;

    void set_inch(double);
    void set_network(QString);
    void set_keyboard(bool);
    void set_jack(bool);
    void set_tablet(bool);
    void set_wifi(bool);

    Smartphone* clone() const;
    void discount(float);
    void extend_warranty(unsigned int);

    //~Smartphone()=default;


};

#endif // SMARTPHONE_H
