#include "dialogcompte.h"
#include "ui_dialogcompte.h"

DialogCompte::DialogCompte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCompte)
{
    ui->setupUi(this);
    compte = new QTimer();
    compte->start(0);
    connect(compte, SIGNAL(timeout()), this, SLOT(time()));
    compte->start(1000);
}

DialogCompte::~DialogCompte()
{
    delete ui;
}

void DialogCompte::update(){
    if(secRestant > 9)
        ui->label->setText(QString::number(minRestant) + QString(":") + QString::number(secRestant));
    else
        ui->label->setText(QString::number(minRestant) + QString(":0") + QString::number(secRestant));
}

void DialogCompte::time(){
    if(secRestant == 0){
        secRestant = 59;
        minRestant --;
    }else{
        secRestant --;
    }
    if(minRestant == 0){
        emit fini();
    }
    update();
}
