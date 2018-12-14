#include "mainwindow.h"
#include <QApplication>
#include "articolo.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    Articolo* test=new Articolo();
    qDebug()<<test->get_Marca();
    QString ciao("ciao");
    test->set_Marca(ciao);
    qDebug()<<test->get_Marca();

   /* QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
}
