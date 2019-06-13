#include "apparecchio.h"

Device::Device(QString C,
                         QString G,
                         QString O,
                         unsigned int R,
                         unsigned int A):
    CPU(C),
    GPU(G),
    Operating_system(O),
    Ram(R),
    storage(A){
}

//getter
QString Device::get_CPU() const{
        return CPU;
    }

QString Device::get_GPU() const{
        return GPU;
    }

QString Device::get_Operating_system() const{
        return Operating_system;
    }

unsigned int Device::get_Ram() const{
        return Ram;
    }

unsigned int Device::get_storage() const{
        return storage;
    }

//setter

void Device:: set_CPU(QString C){
    CPU=C;
}

void Device:: set_GPU(QString G){
    GPU=G;
}

void Device:: set_Operating_system(QString O){
    Operating_system=O;
}

void Device:: set_Ram(unsigned int R){
    Ram=R;
}

void Device:: set_storage(unsigned int M){
    storage=M;
}


