#ifndef SEARCHW_H
#define SEARCHW_H
#include <QMainWindow>
#include <QLineEdit>

class SearchW:public QWidget
{
    Q_OBJECT
public:
    explicit SearchW(QWidget *parent = nullptr);
    ~SearchW()=default;
private:
    QLineEdit* name;
};

#endif // SEARCHW_H
