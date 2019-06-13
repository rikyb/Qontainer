#ifndef ALCOLICO_H
#define ALCOLICO_H
#include <QString>

class Alcolico
{
private:
    QString nome;
    unsigned int grado;
    QString provenienza;
public:
    Alcolico(QString n="",unsigned int g=0,QString p="");
    QString getNome() const;
    unsigned int getGrado() const;
    QString getProvenienza() const;
    virtual ~Alcolico()=default;
    virtual Alcolico* clone()const =0;
    virtual bool operator==(const Alcolico&)const =0;
    virtual bool operator>(const Alcolico&)const;
    virtual bool operator<(const Alcolico&)const;

};

#endif // ALCOLICO_H
