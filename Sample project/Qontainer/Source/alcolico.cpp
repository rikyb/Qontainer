#include "alcolico.h"

Alcolico::Alcolico(QString n,unsigned int g,QString p):nome(n),grado(g),provenienza(p){}

QString Alcolico::getNome()const{
    return nome;
}

unsigned int Alcolico::getGrado()const{
    return grado;
}
QString Alcolico::getProvenienza() const{
    return provenienza;
}

bool Alcolico::operator>(const Alcolico& a)const{
    return this->getGrado()>a.getGrado();
}

bool Alcolico::operator<(const Alcolico& a)const{
    return this->getGrado()<a.getGrado();
}
