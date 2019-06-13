#ifndef BASEWINDOW_H
#define BASEWINDOW_H
#include <QListWidget>
#include "Source/alcolico.h"
#include "GUI/popup.h"
#include "GUI/searchw.h"
#include <QFile>
#include <QByteArray>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QComboBox>
#include <QButtonGroup>

class BaseWindow: public QWidget
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = nullptr);
    void AddItemsToList();
    ~BaseWindow()=default;
    bool LoadFromFile(QString fileLocation);
public slots:
    void onAddClicked();
    void onItemAdded();
    void onEdtClicked();
    void onRmvClicked();
    void onLoadClicked();
    void onSaveClicked();
    void onRstClicked();
    void onSrcClicked();
private:
    QListWidgetItem* picked;
    bool edit;
    PopUp* pop;
    SearchW* srcw;

    Container<DeepPtr<Alcolico>> list;
    QListWidget* QListW;
    QLineEdit* counter;
    QLineEdit* searchbar;//riki
    QMap<QString,DeepPtr<Alcolico>> saved;
    QPushButton* addButton;
    QPushButton* edtButton;
    QPushButton* rmvButton;
    QPushButton* srcButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
    QPushButton* rstButton;
    QLineEdit* clickableList;
    QHBoxLayout* HLayout;
    QVBoxLayout* VLayout;
    QVBoxLayout* V2Layout;

    QVBoxLayout* V3;//filter
    QHBoxLayout* H2;//standard
    QSpinBox* grado;
    QLineEdit* nome;
    QComboBox* pro;
    QHBoxLayout* H3;//type select
    QRadioButton* ferm;
    QRadioButton* dist;
    QHBoxLayout* H4;//type search
    QComboBox* tfer;
    QComboBox* matpr;
    QHBoxLayout* H5;//subtype selection
    QButtonGroup* subtypes;
    QRadioButton* vin;
    QRadioButton* bir;
    QRadioButton* teq;
    QRadioButton* rum;
    QRadioButton* gin;
    QHBoxLayout* H6;//fields
    QLineEdit* tipo;
    QComboBox* col;
    QCheckBox* friz;
    QComboBox* ann;
    QVBoxLayout* VL1;//grado
    QLabel* gr;
    QVBoxLayout* VL2;//nome
    QLabel* nomeLabel;
    QVBoxLayout* VL3;//provenienza
    QLabel* provLabel;
    QHBoxLayout* HL;//typelabel
    QLabel* ferLabel;
    QLabel* disLabel;
    QVBoxLayout* VL4;//annata
    QLabel* annLabel;
    QVBoxLayout* VL5;//tipo
    QLabel* tipLabel;
    QVBoxLayout* VL6;//colore
    QLabel* colLabel;
};

#endif // BASEWINDOW_H
