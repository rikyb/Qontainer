#include "articolo.h"

Item::Item(QString M,
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
QString Item::get_brand() const{
    return brand;
}

QString Item::get_name() const{
    return name;
}

float Item::get_price() const{
    return price;
}

QDate Item::get_release_data() const{
    return release_data;
}

unsigned int Item::get_quantity() const{
    return quantity;
}

unsigned int Item::get_warranty() const{
    return warranty;
}

//setter
void Item::set_brand(QString M){
    brand=M;
}

void Item::set_name(QString N){
    name=N;
}

void Item::set_price(float P){
    price=P;
}

void Item::set_release_data(QDate D){
    release_data=D;
}

void Item::set_quantity(unsigned int Q){
    quantity=Q;
}

void Item::set_warranty(unsigned int G){
    warranty=G;
}











