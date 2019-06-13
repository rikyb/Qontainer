#include "basewindow.h"
#include <QDesktopWidget>
#include <QFileDialog>
#include<iostream>

using namespace std;



BaseWindow::BaseWindow(QWidget* parent):
    QWidget(parent)

{
    setFixedSize(900,400);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());

    setWindowTitle(tr("Elettronica"));
    //DeepPtr<Alcolico> deep;
    //deep.pointer=new Vino("Merlot Veronese",14,"Verona","Botte",2005,"Merlot",false);
    //list.add(deep->clone());



    edit=false;
    pop=new PopUp();
    //srcw=new SearchW();
    QListW=new QListWidget();
    AddItemsToList();


    clickableList = new QLineEdit();
    clickableList->setReadOnly(true);
    clickableList->setAlignment(Qt::AlignCenter);

    counter = new QLineEdit();
    counter->setPlaceholderText("Ricerca");//riki

    /* Searchbar sottolayout riki
    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchLayout->addWidget(counter);*/

    addButton=new QPushButton(tr("ADD"));
    addButton->setMinimumSize(70,50);

    edtButton=new QPushButton(tr("EDIT"));
    edtButton->setMinimumSize(70,50);

    rmvButton=new QPushButton(tr("REMOVE"));
    rmvButton->setMinimumSize(70,50);

    srcButton=new QPushButton(tr("SEARCH"));
    srcButton->setMinimumSize(70,50);

    saveButton=new QPushButton(tr("SAVE"));
    saveButton->setMinimumSize(70,50);

    loadButton=new QPushButton(tr("LOAD"));
    loadButton->setMinimumSize(70,50);

    rstButton=new QPushButton(tr("RESET"));
    rstButton->setMinimumSize(70,50);

    connect(addButton,SIGNAL(clicked()),this,SLOT(onAddClicked()));
    connect(edtButton,SIGNAL(clicked()),this,SLOT(onEdtClicked()));
    connect(rmvButton,SIGNAL(clicked()),this,SLOT(onRmvClicked()));
    connect(loadButton,SIGNAL(clicked()),this,SLOT(onLoadClicked()));
    connect(saveButton,SIGNAL(clicked()),this,SLOT(onSaveClicked()));
    connect(rstButton,SIGNAL(clicked()),this,SLOT(onRstClicked()));
    connect(pop,SIGNAL(acceptedSignal()),this,SLOT(onItemAdded()));

    connect(srcButton,SIGNAL(clicked()),this,SLOT(onSrcClicked()));//test di riki

    //filter buttons
    grado=new QSpinBox();//standard
    grado->setRange(0,99);
    gr=new QLabel("Grado");
    nome=new QLineEdit();
    nomeLabel=new QLabel("Nome");
    pro=new QComboBox();
    provLabel=new QLabel("Provenienza");//type selection
    ferm=new QRadioButton(tr("Fermentato"));
    dist=new QRadioButton(tr("Distillato"));
    tfer=new QComboBox();//type search
    ferLabel=new QLabel("Tipo di fermentazione");
    matpr=new QComboBox();
    disLabel=new QLabel("Materia prima");
    vin= new QRadioButton(tr("Vino"));//subctype selection
    bir=new QRadioButton(tr("Birra"));
    gin=new QRadioButton(tr("Gin"));
    rum=new QRadioButton(tr("Rum"));
    teq=new QRadioButton(tr("Tequila"));
    tipo=new QLineEdit();
    tipLabel=new QLabel("Tipo");
    col=new QComboBox();
    colLabel=new QLabel("Colore");
    friz=new QCheckBox(tr("Frizzante"));
    annLabel=new QLabel("Annata");
    ann=new QComboBox();


    HLayout=new QHBoxLayout();
    VLayout=new QVBoxLayout();
    V2Layout=new QVBoxLayout();
    V3= new QVBoxLayout();
    H2= new QHBoxLayout();
    H3= new QHBoxLayout();
    H4= new QHBoxLayout();
    H5= new QHBoxLayout();
    H6= new QHBoxLayout();
    VL1=new QVBoxLayout();
    VL2=new QVBoxLayout();
    VL3=new QVBoxLayout();
    VL4=new QVBoxLayout();
    VL5=new QVBoxLayout();
    VL6=new QVBoxLayout();
    HL=new QHBoxLayout();
    VLayout->addWidget(addButton);
    VLayout->addWidget(edtButton);
    VLayout->addWidget(rmvButton);
    VLayout->addWidget(srcButton);
    VLayout->addWidget(saveButton);
    VLayout->addWidget(loadButton);
    VLayout->addWidget(rstButton);
    V2Layout->addWidget(counter);
    V2Layout->addWidget(QListW);
   /*
    *      LASCIO COMMENTATO SE NON VOGLIO IL MACELLO CHE POI HO NEL POP UP
    *  VL1->addWidget(gr);//grado
    VL1->addWidget(grado);
    VL2->addWidget(nomeLabel);//nome
    VL2->addWidget(nome);
    VL3->addWidget(provLabel);//provenienza
    VL3->addWidget(pro);
    H2->addLayout(VL1);//standard fields
    H2->addLayout(VL2);
    H2->addLayout(VL3);
    H3->addWidget(ferm);//type select
    H3->addWidget(dist);
    HL->addWidget(ferLabel);//type label
    HL->addWidget(disLabel);
    H4->addWidget(tfer);
    H4->addWidget(matpr);
    H5->addWidget(vin);
    H5->addWidget(bir);
    H5->addWidget(teq);
    H5->addWidget(rum);
    H5->addWidget(gin);
    VL4->addWidget(annLabel);//annata
    VL4->addWidget(ann);
    VL5->addWidget(tipLabel);//tipo
    VL5->addWidget(tipo);
    VL6->addWidget(colLabel);//colore
    VL6->addWidget(col);
    H6->addLayout(VL5);
    H6->addLayout(VL6);
    H6->addWidget(friz);
    H6->addLayout(VL4);
    V3->addLayout(H2);
    V3->addLayout(H3);
    V3->addLayout(HL);
    V3->addLayout(H4);
    V3->addLayout(H5);
    V3->addLayout(H6);*/
    HLayout->addLayout(V2Layout);
    HLayout->addLayout(V3);
    HLayout->addLayout(VLayout);
    setLayout(HLayout);
}

void BaseWindow::onAddClicked(){
    pop->reset();
    pop->show();
}

void BaseWindow::onItemAdded(){
    if(edit){
        delete picked;
        edit=false;
    }
    list.add(pop->res()->clone());
    QListW->addItem((list.end()-1)->pointer->getNome());
}

void BaseWindow::AddItemsToList(){
    Container<DeepPtr<Alcolico>>::iterator it=list.begin();
    for(;it!=list.end();it++)
    QListW->addItem((*it)->getNome());
}

void BaseWindow::onEdtClicked(){
    edit=true;
    DeepPtr<Alcolico> sup;
    bool found=false;
    picked=QListW->currentItem();   //l'item selezionato
    if(picked){
        Container<DeepPtr<Alcolico>>::iterator it=list.begin();
        unsigned int i=0;
        for(;!found&&it!=list.end();it++){
            if((*it)->getNome()==picked->text()){   //verifico che il testo selezionato sia uguale al nome
                sup=(*it)->clone(); //clono
                list.erase(i);  //elimino in quella posizione
                found=true;
            }
            i++;
        }
        pop->setValues(sup);
        pop->show();
    }else{
        QMessageBox::warning(this,tr("Attenzione!"),tr("Nessun elemento selezionato"));
    }
}

void BaseWindow::onSrcClicked(){
    //srcw->show();
/*
    edit=true;
    DeepPtr<Alcolico> sup;
    bool found=false;
    picked=QListW->currentItem();   //l'item selezionato
    if(picked){
        Container<DeepPtr<Alcolico>>::iterator it=list.begin();
        unsigned int i=0;
        for(;!found&&it!=list.end();it++){
            if((*it)->getNome()==picked->text()){   //verifico che il testo selezionato sia uguale al nome
                sup=(*it)->clone(); //clono
                list.erase(i);  //elimino in quella posizione
                found=true;
            }
            i++;
        }
        pop->setValues(sup);
        pop->show();
    }else{
        QMessageBox::warning(this,tr("Attenzione!"),tr("Nessun elemento selezionato"));
    }



    barra di ricerca del tutor
        QRegExp regex(searchbar->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
        proxymodel->setFilterRegExp(regex);
        */
}

void BaseWindow::onRmvClicked(){
    QListWidgetItem* picked=QListW->currentItem();
    bool found=false;
    if(picked){Container<DeepPtr<Alcolico>>::iterator it=list.begin();
        unsigned int i=0;
        for(;!found&&it!=list.end();it++){
            if((*it)->getNome()==picked->text()){
                list.erase(i);
                found=true;
            }
            i++;
        }
        delete picked;
    }
}

//carico da file sovrascrivendo la vecchia list
bool BaseWindow::LoadFromFile(QString fileLocation){

    QListW->clear(); //voglio eliminare quello che ho caricato col file precedente

    QFile file(fileLocation);
    file.open(QIODevice::ReadOnly);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonArray array=document.object().value("Alcolici").toArray();
    if(!array.isEmpty()){
        if(!list.isEmpty()){
            list.clear();
        }
        foreach(const QJsonValue& v, array) {
            QString tipo = QString(v.toObject().value("typeID").toString());
            if(tipo=="Vino"){
                    list.add(new Vino(v.toObject().value("nome").toString(),
                                      v.toObject().value("grado").toInt(),
                                      v.toObject().value("provenienza").toString(),
                                      v.toObject().value("fermentazione").toString(),
                                      v.toObject().value("anno").toInt(),
                                      v.toObject().value("tipo").toString(),
                                      v.toObject().value("frizzante").toBool()));
            }
            else if(tipo=="Birra"){
                    list.add(new Birra(v.toObject().value("nome").toString(),
                                       v.toObject().value("grado").toInt(),
                                       v.toObject().value("provenienza").toString(),
                                       v.toObject().value("fermentazione").toString(),
                                       v.toObject().value("tipo").toString(),
                                       v.toObject().value("colore").toString()));
            }
            else if(tipo=="Gin"){
                    list.add(new Gin(v.toObject().value("nome").toString(),
                                     v.toObject().value("grado").toInt(),
                                     v.toObject().value("provenienza").toString(),
                                     v.toObject().value("matprima").toString(),
                                     v.toObject().value("tipo").toString()));
            }
            else if(tipo=="Rum"){
                    list.add(new Rum(v.toObject().value("nome").toString(),
                            v.toObject().value("grado").toInt(),
                            v.toObject().value("provenienza").toString(),
                            v.toObject().value("matprima").toString(),
                            v.toObject().value("tipo").toString(),
                            v.toObject().value("anno").toInt()));
            }
            else if(tipo=="Tequila"){
                    list.add(new Tequila(v.toObject().value("nome").toString(),
                                         v.toObject().value("grado").toInt(),
                                         v.toObject().value("provenienza").toString(),
                                         v.toObject().value("matprima").toString(),
                                         v.toObject().value("tipo").toString(),
                                         v.toObject().value("anno").toInt()));
            }
        }
        return true;
    }
    return false;
}


void BaseWindow::onLoadClicked(){
    QFileDialog dialog(this);
    dialog.setNameFilter("*.json");
    QString fileName = dialog.getOpenFileName(this, "Get list from a file", "", "Json File (*.json)");
    if(LoadFromFile(fileName)){
        QMessageBox::information(this,tr("Caricamento file"),tr("Caricamento avvenuto con successo"));
        AddItemsToList();
    }
    else
        QMessageBox::warning(this,tr("Errore"),tr("File non valido"));
}

void BaseWindow::onSaveClicked(){
    QFileDialog dialog(this);
    dialog.setNameFilter("*.json");
    QString fileName = dialog.getSaveFileName(this, "Save current list", "", "Json File (*.json)");
    if(!fileName.endsWith(".json")) {
        fileName += ".json";
    }
    QFile saveLocation(fileName);

    QJsonArray AlcArray;
    for(auto it=list.begin();it!=list.end();it++){
        QJsonObject singleEntry;
        singleEntry.insert("nome",QJsonValue::fromVariant((*it)->getNome()));
        singleEntry.insert("grado",QJsonValue::fromVariant((*it)->getGrado()));
        singleEntry.insert("provenienza",QJsonValue::fromVariant((*it)->getProvenienza()));
        if(dynamic_cast<Fermentato*>((*it).pointer)){
            Fermentato* auxf=static_cast<Fermentato*>((*it).pointer);
            singleEntry.insert("fermentazione",QJsonValue::fromVariant(auxf->getFermentazione()));
            if(dynamic_cast<Vino*>((*it).pointer)){
                Vino* auxv=static_cast<Vino*>((*it).pointer);
                singleEntry.insert("typeID",QJsonValue::fromVariant("Vino"));
                singleEntry.insert("anno",QJsonValue::fromVariant(auxv->getAnnata()));
                singleEntry.insert("tipo",QJsonValue::fromVariant(auxv->getTipo()));
                singleEntry.insert("frizzante",QJsonValue::fromVariant(auxv->getFrizzante()));
            }else{
                Birra* auxb=static_cast<Birra*>((*it).pointer);
                singleEntry.insert("typeID",QJsonValue::fromVariant("Birra"));
                singleEntry.insert("tipo",QJsonValue::fromVariant(auxb->getTipo()));
                singleEntry.insert("colore",QJsonValue::fromVariant(auxb->getColore()));
            }
        }else{
            Distillato* auxd=static_cast<Distillato*>((*it).pointer);
            singleEntry.insert("matprima",QJsonValue::fromVariant(auxd->getMat()));
            if(dynamic_cast<Gin*>((*it).pointer)){
                Gin* auxg=static_cast<Gin*>((*it).pointer);
                singleEntry.insert("typeID",QJsonValue::fromVariant("Gin"));
                singleEntry.insert("tipo",QJsonValue::fromVariant(auxg->getTipo()));
            }else if(dynamic_cast<Rum*>((*it).pointer)){
                Rum* auxr=static_cast<Rum*>((*it).pointer);
                singleEntry.insert("typeID",QJsonValue::fromVariant("Rum"));
                singleEntry.insert("tipo",QJsonValue::fromVariant(auxr->getTipo()));
                singleEntry.insert("anno",QJsonValue::fromVariant(auxr->getAnnata()));
            }else{
                Tequila* auxt=static_cast<Tequila*>((*it).pointer);
                singleEntry.insert("typeID",QJsonValue::fromVariant("Tequila"));
                singleEntry.insert("tipo",QJsonValue::fromVariant(auxt->getTipo()));
                singleEntry.insert("anno",QJsonValue::fromVariant(auxt->getAnnata()));
            }

        }
        AlcArray.append(singleEntry);
    }
    QJsonObject toInsert;
    toInsert.insert("Alcolici", AlcArray);
    QJsonDocument doc(toInsert);
    if(!saveLocation.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this,tr("Errore"),tr("File non valido"));
        return;
    }else{
    saveLocation.write(doc.toJson());
    QMessageBox::information(this,tr("Salvataggio file"),tr("Salvataggio avvenuto con successo"));
    }
}

void BaseWindow::onRstClicked(){
    QListW->clear();
    AddItemsToList();//????
}
