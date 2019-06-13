#include "articolo.h"

Device::Device(QString M,
                   QString N,
                   unsigned  int P,
                   QDate D,
                   unsigned  int Q,
                   unsigned  int G):
    brand(M),
    name(N),
    price(P),
    release_data(D),
    quantity(Q),
    warranty(G){
}

//getter
QString Device::get_brand() const{
    return brand;
}

QString Device::get_name() const{
    return name;
}

float Device::get_price() const{
    return price;
}

QDate Device::get_release_data() const{
    return release_data;
}

unsigned int Device::get_quantity() const{
    return quantity;
}

unsigned int Device::get_warranty() const{
    return warranty;
}

//setter
void Device::set_brand(QString M){
    brand=M;
}

void Device::set_name(QString N){
    name=N;
}

void Device::set_price(float P){
    price=P;
}

void Device::set_release_data(QDate D){
    release_data=D;
}

void Device::set_quantity(unsigned int Q){
    quantity=Q;
}

void Device::set_warranty(unsigned int G){
    warranty=G;
}











