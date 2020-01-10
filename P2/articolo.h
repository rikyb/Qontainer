#ifndef ARTICOLO_H
#define ARTICOLO_H
#include <QString>
#include <QDate>

class Item
{
private:
    QString brand;
    QString name;
    float price;
    QDate release_data;
    unsigned  int quantity;
    unsigned  int warranty;
public:
    Item(QString =QString(),
             QString =QString(),
             unsigned  int =0,
             QDate= QDate(),
             unsigned  int =0,
             unsigned  int =0
             );

    QString get_brand()const;
    QString get_name()const;
    float get_price()const;
    QDate get_release_data()const;
    unsigned int get_quantity()const;
    unsigned int get_warranty()const;

    void set_brand(QString);
    void set_name(QString);
    void set_price(float);
    void set_release_data(QDate);
    void set_quantity(unsigned  int);
    void set_warranty(unsigned  int);

    virtual Item* clone() const =0;
    virtual void sconto(float) =0;
    virtual void estendi_warranty(unsigned int)=0;

    //virtual ~Item()=default;
};

#endif // ARTICOLO_H
