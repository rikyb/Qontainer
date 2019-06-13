#include "popup.h"
#include <QDesktopWidget>

PopUp::PopUp(QWidget* parent):QWidget(parent)
{
    Qt::WA_DeleteOnClose;
    setFixedSize(900,400);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());

    setLayout(defaultLayout());

    fer1=new QLineEdit();
    ferlabel1=new QLabel("Fermentazione");
    fer2=new QLineEdit();
    ferlabel2=new QLabel("Fermentazione");
    dis1=new QLineEdit();
    disLabel1=new QLabel("Materia Prima");
    dis2=new QLineEdit();
    disLabel2=new QLabel("Materia Prima");
    dis3=new QLineEdit();
    disLabel3=new QLabel("Materia Prima");
    ann1=new QLineEdit();
    annLabel1=new QLabel("Annata");
    ann1->setValidator( new QIntValidator(1000, 3000, this) );
    ann2=new QLineEdit();
    annLabel2=new QLabel("Annata");
    ann2->setValidator( new QIntValidator(1000, 3000, this) );
    ann3=new QLineEdit();
    annLabel3=new QLabel("Annata");
    ann3->setValidator( new QIntValidator(1000, 3000, this) );
    tip1=new QLineEdit();
    tipLabel1=new QLabel("Tipologia");
    tip2=new QLineEdit();
    tipLabel2=new QLabel("Tipologia");
    tip3=new QLineEdit();
    tipLabel3=new QLabel("Tipologia");
    tip4=new QLineEdit();
    tipLabel4=new QLabel("Tipologia");
    tip5=new QLineEdit();
    tipLabel5=new QLabel("Tipologia");
    col=new QLineEdit();
    colLabel=new QLabel("Colore");
    friz=new QCheckBox(tr("Frizzante"));

    l.push_back(grado);
    l.push_back(nome);
    l.push_back(pro);
    l.push_back(fer1);
    l.push_back(fer2);
    l.push_back(dis1);
    l.push_back(dis2);
    l.push_back(dis3);
    l.push_back(ann1);
    l.push_back(ann2);
    l.push_back(ann3);
    l.push_back(tip1);
    l.push_back(tip2);
    l.push_back(tip3);
    l.push_back(tip4);
    l.push_back(tip5);
    l.push_back(col);
    l.push_back(friz);

    vin=new QGroupBox();//gruppo vino
    QVBoxLayout* qvv=new QVBoxLayout();
    qvv->addWidget(ferlabel1);
    qvv->addWidget(fer1);
    qvv->addWidget(annLabel1);
    qvv->addWidget(ann1);
    qvv->addWidget(tipLabel1);
    qvv->addWidget(tip1);
    qvv->addWidget(friz);
    vin->setLayout(qvv);

    bir=new QGroupBox();//gruppo birra
    QVBoxLayout* qvb=new QVBoxLayout();
    qvb->addWidget(ferlabel2);
    qvb->addWidget(fer2);
    qvb->addWidget(colLabel);
    qvb->addWidget(col);
    qvb->addWidget(tipLabel2);
    qvb->addWidget(tip2);
    bir->setLayout(qvb);

    gin=new QGroupBox();//gruppo gin
    QVBoxLayout*qvg=new QVBoxLayout();
    qvg->addWidget(disLabel1);
    qvg->addWidget(dis1);
    qvg->addWidget(tipLabel3);
    qvg->addWidget(tip3);
    gin->setLayout(qvg);

    rum=new QGroupBox();//gruppo rum
    QVBoxLayout* qvr=new QVBoxLayout();
    qvr->addWidget(disLabel2);
    qvr->addWidget(dis2);
    qvr->addWidget(tipLabel4);
    qvr->addWidget(tip4);
    qvr->addWidget(annLabel2);
    qvr->addWidget(ann2);
    rum->setLayout(qvr);

    teq=new QGroupBox();//gruppo tequila
    QVBoxLayout* qvt=new QVBoxLayout();
    qvt->addWidget(disLabel3);
    qvt->addWidget(dis3);
    qvt->addWidget(tipLabel5);
    qvt->addWidget(tip5);
    qvt->addWidget(annLabel3);
    qvt->addWidget(ann3);
    teq->setLayout(qvt);

    groups=new QStackedLayout();
    groups->addWidget(vin);
    groups->addWidget(bir);
    groups->addWidget(gin);
    groups->addWidget(rum);
    groups->addWidget(teq);
    groups->setCurrentIndex(0);

    qv->addLayout(groups);


    connect(v,SIGNAL(clicked()),this,SLOT(onVChecked()));
    connect(b,SIGNAL(clicked()),this,SLOT(onBChecked()));
    connect(g,SIGNAL(clicked()),this,SLOT(onGChecked()));
    connect(r,SIGNAL(clicked()),this,SLOT(onRChecked()));
    connect(t,SIGNAL(clicked()),this,SLOT(onTChecked()));
    connect(add,SIGNAL(clicked()),this,SLOT(onAddClicked()));
    connect(clear,SIGNAL(clicked()),this,SLOT(onClearClicked()));

}

void PopUp::onVChecked(){
    groups->setCurrentIndex(0);
}

void PopUp::onBChecked(){
    groups->setCurrentIndex(1);
}

void PopUp::onGChecked(){
    groups->setCurrentIndex(2);
}

void PopUp::onRChecked(){
    groups->setCurrentIndex(3);
}

void PopUp::onTChecked(){
    groups->setCurrentIndex(4);
}

void PopUp::onClearClicked(){
    groups->setCurrentIndex(0);
    reset();
}

QLayout* PopUp::defaultLayout(){
    grado=new QSpinBox();//Elementi standard(per tutti gli alcolici
    grado->setRange(0,99);
    gr=new QLabel("Grado");
    nome=new QLineEdit();
    nomelabel=new QLabel("Nome");
    pro=new QLineEdit();
    provlabel=new QLabel("Provenienza");
    QHBoxLayout* qhs=new QHBoxLayout();
    QVBoxLayout* qvs1=new QVBoxLayout();
    QVBoxLayout* qvs2=new QVBoxLayout();
    QVBoxLayout* qvs3=new QVBoxLayout();
    qvs1->addWidget(gr);
    qvs2->addWidget(nomelabel);
    qvs3->addWidget(provlabel);
    qvs1->addWidget(grado);
    qvs2->addWidget(nome);
    qvs3->addWidget(pro);
    qhs->addLayout(qvs1);
    qhs->addLayout(qvs2);
    qhs->addLayout(qvs3);

    cat= new QGroupBox(tr("Seleziona la categoria"));//selezione gruppo esclusiva
    v=new QRadioButton(tr("Vino"));
    b=new QRadioButton(tr("Birra"));
    g=new QRadioButton(tr("Gin"));
    r=new QRadioButton(tr("Rum"));
    t=new QRadioButton(tr("Tequila"));
    v->setChecked(true);
    QHBoxLayout* qhg=new QHBoxLayout();
    qhg->addWidget(v);
    qhg->addWidget(b);
    qhg->addWidget(g);
    qhg->addWidget(r);
    qhg->addWidget(t);

    add=new QPushButton(tr("ADD"));//Bottoni principali finestra per inviare dati o resettarla
    clear=new QPushButton(tr("CLEAR"));
    QHBoxLayout* qhw=new QHBoxLayout();
    qhw->addWidget(add);
    qhw->addWidget(clear);

    qv=new QVBoxLayout();//composizione finestra
    qv->addLayout(qhs);
    qv->addLayout(qhg);
    qv->addLayout(qhw);

    return qv;
}

void PopUp::onAddClicked(){
    if(nome->text()==""||grado->text()==""||pro->text()==""){
        QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
        return;
    }
    QString nomeText=nome->text();
    int gradoText=grado->text().toInt();
    QString proText=pro->text();
    if(gradoText<1){
        QMessageBox::information(this,tr("Ma che oooooooh!"),tr("Il database riguarda solo gli  alcolici"));
        return;
    }
    int const current=groups->currentIndex();
    if(current==0){
        if(fer1->text()==""||ann1->text()==""||tip1->text()==""){
            QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
            return;
        }
        ritorno=new Vino(nomeText,gradoText,proText,fer1->text(),ann1->text().toInt(),tip1->text(),friz->isChecked());
    }else{
        if(current==1){
            if(fer2->text()==""||tip2->text()==""||col->text()==""){
                QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
                return;
            }
            ritorno=new Birra(nomeText,gradoText,proText,fer2->text(),tip2->text(),col->text());
        }else{
            if(current==2){
                if(dis1->text()==""||tip3->text()==""){
                    QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
                    return;
                }
                ritorno=new Gin(nomeText,gradoText,proText,dis1->text(),tip3->text());
            }else{
                if(current==3){
                    if(dis2->text()==""||tip4->text()==""||ann2->text()==""){
                        QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
                        return;
                    }
                    ritorno=new Rum(nomeText,gradoText,proText,dis2->text(),tip4->text(),ann2->text().toInt());
                }else{
                    if(current==4){
                        if(dis3->text()==""||tip5->text()==""||ann3->text()==""){
                            QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
                            return;
                        }
                        ritorno=new Tequila(nomeText,gradoText,proText,dis3->text(),tip5->text(),ann3->text().toInt());
                    }
                }
            }
        }
    }
    emit acceptedSignal();
    QMessageBox::information(this,tr("Oggetto aggiunto"),tr("L'oggetto è stato aggiunto con successo"));
    hide();
}

DeepPtr<Alcolico> PopUp::res(){
    return ritorno;
}

void PopUp::reset(){
    v->setChecked(true);
    QLineEdit* supl;
    QSpinBox* sups;
    QCheckBox* supc;
    std::list<QWidget*>::iterator i=l.begin();
    for(;i!=l.end();i++){
        if(dynamic_cast<QLineEdit*>(*i)){
            supl=dynamic_cast<QLineEdit*>(*i);
            supl->clear();
        }else{
            if(dynamic_cast<QSpinBox*>(*i)){
                sups=dynamic_cast<QSpinBox*>(*i);
                sups->setValue(0);
            }else{
                if(dynamic_cast<QCheckBox*>(*i)){
                    supc=dynamic_cast<QCheckBox*>(*i);
                    supc->setChecked(false);
                }
            }
        }
    }
}

void PopUp::setValues(DeepPtr<Alcolico>a){
    Vino* supv;
    Birra* supb;
    Gin* supg;
    Rum* supr;
    Tequila* supt;
    if(dynamic_cast<Vino*>(a.pointer)){
        groups->setCurrentIndex(0);
        v->setChecked(true);
        supv=dynamic_cast<Vino*>(a.pointer);
        nome->setText(supv->getNome());
        grado->setValue(supv->getGrado());
        pro->setText(supv->getProvenienza());
        ann1->setText(QString::number(supv->getAnnata()));
        friz->setChecked(supv->getFrizzante());
        tip1->setText(supv->getTipo());
        fer1->setText(supv->getFermentazione());
        show();
    }else{
        if(dynamic_cast<Birra*>(a.pointer)){
            groups->setCurrentIndex(1);
            b->setChecked(true);
            supb=dynamic_cast<Birra*>(a.pointer);
            nome->setText(supb->getNome());
            grado->setValue(supb->getGrado());
            pro->setText(supb->getProvenienza());
            tip2->setText(supb->getTipo());
            col->setText(supb->getColore());
            fer2->setText(supb->getFermentazione());
            show();
        }else{
            if(dynamic_cast<Gin*>(a.pointer)){
                groups->setCurrentIndex(2);
                g->setChecked(true);
                supg=dynamic_cast<Gin*>(a.pointer);
                nome->setText(supg->getNome());
                pro->setText(supg->getProvenienza());
                grado->setValue(supg->getGrado());
                tip3->setText(supg->getTipo());
                dis1->setText(supg->getMat());
            }else{
                if(dynamic_cast<Rum*>(a.pointer)){
                    groups->setCurrentIndex(3);
                    r->setChecked(true);
                    supr=dynamic_cast<Rum*>(a.pointer);
                    nome->setText(supr->getNome());
                    pro->setText(supr->getProvenienza());
                    grado->setValue(supr->getGrado());
                    tip4->setText(supr->getTipo());
                    ann2->setText(QString::number(supr->getAnnata()));
                    dis2->setText(supr->getMat());
                }else{
                    if(dynamic_cast<Tequila*>(a.pointer)){
                        groups->setCurrentIndex(4);
                        t->setChecked(true);
                        supt=dynamic_cast<Tequila*>(a.pointer);
                        nome->setText(supt->getNome());
                        pro->setText(supt->getProvenienza());
                        grado->setValue(supt->getGrado());
                        tip5->setText(supt->getTipo());
                        ann3->setText(QString::number(supt->getAnnata()));
                        dis3->setText(supt->getMat());
                    }
                }
            }
        }
    }
}
