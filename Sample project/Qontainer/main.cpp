#include <QApplication>
#include <GUI/basewindow.h>

using namespace std;

int main(int argc,char* argv[])
{
    QApplication a(argc,argv);

    BaseWindow w;
    w.show();
    return a.exec();
}
