#ifndef APPARECCHIO_H
#define APPARECCHIO_H
#include<QString>
#include"articolo.h"

class Apparecchio: public Articolo{
private:
    QString CPU;
    QString GPU;
    QString Operating_system;
    unsigned int Ram;
    unsigned int Memoria_archiviazione;

public:
    Apparecchio(QString=QString(),
                QString=QString(),
                QString=QString(),
                unsigned int=0,
                unsigned int=0
                );

    QString get_CPU()const;
    QString get_GPU()const;
    QString get_Operating_system()const;
    unsigned int get_Ram()const;
    unsigned int get_Memoria_archiviazione()const;

    void set_CPU(QString&);
    void set_GPU(QString&);
    void set_Operating_system(QString&);
    void set_Ram(unsigned int&);
    void set_Memoria_archiviazione(unsigned int&);

};

#endif // APPARECCHIO_H
