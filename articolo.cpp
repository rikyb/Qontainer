#include "articolo.h"

Articolo::Articolo(QString M,
                   QString N,
                   unsigned  int P,
                   QDate D,
                   unsigned  int Q,
                   unsigned  int G):
    Marca(M),
    Nome(N),
    Prezzo(P),
    Data_uscita(D),
    Quantita(Q),
    Garanzia(G){
}

//getter
QString Articolo::get_Marca() const{
    return Marca;
}

QString Articolo::get_Nome() const{
    return Nome;
}

unsigned int Articolo::get_Prezzo() const{
    return Prezzo;
}

QDate Articolo::get_Data_uscita() const{
    return Data_uscita;
}

unsigned int Articolo::get_Quantita() const{
    return Quantita;
}

unsigned int Articolo::get_Garanzia() const{
    return Garanzia;
}

//setter
void Articolo::set_Marca(QString& M){
    Marca=M;
}

void Articolo::set_Nome(QString& N){
    Nome=N;
}

void Articolo::set_Prezzo(unsigned int& P){
    Prezzo=P;
}

void Articolo::set_Data_uscita(QDate& D){
    Data_uscita=D;
}

void Articolo::set_Quantita(unsigned int& Q){
    Quantita=Q;
}

void Articolo::set_Garanzia(unsigned int& G){
    Garanzia=G;
}











