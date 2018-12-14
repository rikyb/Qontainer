#include "apparecchio.h"

Apparecchio::Apparecchio(QString C,
                         QString G,
                         QString O,
                         unsigned int R,
                         unsigned int A):
    CPU(C),
    GPU(G),
    Operating_system(O),
    Ram(R),
    Memoria_archiviazione(A){
}

//getter
QString Apparecchio::get_CPU() const{
        return CPU;
    }

QString Apparecchio::get_GPU() const{
        return GPU;
    }

QString Apparecchio::get_Operating_system() const{
        return Operating_system;
    }

unsigned int Apparecchio::get_Ram() const{
        return Ram;
    }

unsigned int Apparecchio::get_Memoria_archiviazione() const{
        return Memoria_archiviazione;
    }

//setter

void Apparecchio:: set_CPU(QString& C){
    CPU=C;
}

void Apparecchio:: set_GPU(QString& G){
    GPU=G;
}

void Apparecchio:: set_Operating_system(QString& O){
    Operating_system=O;
}

void Apparecchio:: set_Ram(unsigned int& R){
    Ram=R;
}

void Apparecchio:: set_Memoria_archiviazione(unsigned int& M){
    Memoria_archiviazione=M;
}


