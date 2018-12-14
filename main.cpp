#include "mainwindow.h"
#include <QApplication>
#include "articolo.h"
#include "apparecchio.h"
#include "computer.h"
#include "printer.h"
#include "smartphone.h"




#include<QDebug>

int main(int argc, char *argv[])
{
    Computer* test=new Computer();
   /* qDebug()<<test->get_Marca();
    test->set_Marca("ciao");
    qDebug()<<test->get_Marca();

    qDebug()<<test->get_Garanzia();
    test->set_Garanzia(6);
    qDebug()<<test->get_Garanzia();
*/
    qDebug()<<test->get_Prezzo();
    test->set_Prezzo(100);
    qDebug()<<test->get_Prezzo();
    test->sconto(3);
    qDebug()<<test->get_Prezzo();



   /* QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
}
