#ifndef POPUP_H
#define POPUP_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QGroupBox>
#include <QMessageBox>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QStackedLayout>
#include "Source/birra.h"
#include "Source/vino.h"
#include "Source/gin.h"
#include "Source/rum.h"
#include "Source/tequila.h"
#include "Source/deepptr.h"
#include "Source/container.h"

class PopUp:public QWidget
{
    Q_OBJECT
public:
    explicit PopUp(QWidget *parent = nullptr);
    QLayout* defaultLayout();
    void reset();
    DeepPtr<Alcolico> res();
    void setValues(DeepPtr<Alcolico>);
    ~PopUp()=default;
public slots:
    void onAddClicked();
    void onClearClicked();
    void onVChecked();
    void onBChecked();
    void onGChecked();
    void onRChecked();
    void onTChecked();
signals:
    void acceptedSignal();
private:
    DeepPtr<Alcolico> ritorno;
    QGroupBox* cat;
    QGroupBox* bir;
    QGroupBox* vin;
    QGroupBox* gin;
    QGroupBox* rum;
    QGroupBox* teq;
    QSpinBox* grado;
    QLabel* gr;
    QLabel* nomelabel;
    QLabel* provlabel;
    QLabel* ferlabel1;
    QLabel* ferlabel2;
    QLabel* disLabel1;
    QLabel* disLabel2;
    QLabel* disLabel3;
    QLabel* annLabel1;
    QLabel* annLabel2;
    QLabel* annLabel3;
    QLabel* tipLabel1;
    QLabel* tipLabel2;
    QLabel* tipLabel3;
    QLabel* tipLabel4;
    QLabel* tipLabel5;
    QLabel* colLabel;
    QLineEdit* nome;
    QLineEdit* pro;//provenienza
    QLineEdit* fer1;//fermentazione
    QLineEdit* fer2;
    QLineEdit* dis1;//distillazione
    QLineEdit* dis2;
    QLineEdit* dis3;
    QLineEdit* ann1;//annata
    QLineEdit* ann2;
    QLineEdit* ann3;
    QLineEdit* tip1;//tipologia
    QLineEdit* tip2;
    QLineEdit* tip3;
    QLineEdit* tip4;
    QLineEdit* tip5;
    QLineEdit* col;//colore
    QCheckBox* friz;//frizzante
    QPushButton* add;
    QPushButton* clear;
    QRadioButton* v;
    QRadioButton* b;
    QRadioButton* g;
    QRadioButton* r;
    QRadioButton* t;
    QVBoxLayout* qv;
    QStackedLayout* groups;//selzionatore layout
    std::list<QWidget*> l;
};

#endif // POPUP_H
