#ifndef ARTICOLO_H
#define ARTICOLO_H
#include <QString>
#include <QDate>

class Articolo
{
private:
    QString Marca;
    QString Nome;
    unsigned  int Prezzo;
    QDate Data_uscita;
    unsigned  int Quantita;
    unsigned  int Garanzia;
public:
    Articolo(QString =QString(),
             QString =QString(),
             unsigned  int =0,
             QDate= QDate(),
             unsigned  int =0,
             unsigned  int =0
             );

    QString get_Marca()const;
    QString get_Nome()const;
    unsigned int get_Prezzo()const;
    QDate get_Data_uscita()const;
    unsigned int get_Quantita()const;
    unsigned int get_Garanzia()const;

    void set_Marca(QString&);
    void set_Nome(QString&);
    void set_Prezzo(unsigned  int&);
    void set_Data_uscita(QDate&);
    void set_Quantita(unsigned  int&);
    void set_Garanzia(unsigned  int&);

    virtual Articolo* clone() const =0;
    virtual unsigned int sconto()=0;
    virtual unsigned int estendi_garanzia()=0;

    virtual ~Articolo()=default;
};

#endif // ARTICOLO_H
