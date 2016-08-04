#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    QFile file("questions.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this, "Erreur", "Le fichier questions.txt n'a pas pu être trouvé");
        exit(0);
    }
    try{
        QString ns = file.readLine();
        unsigned n = ns.toInt();
        enigmes.resize(n);
        std::cout << n << std::endl;
        for(unsigned k =0; k<n; ++k){
            QString q = "";

            QString r = "";
            q = file.readLine();
            q.chop(1);
            r = file.readLine();
            r.chop(1);
            std::cout << q.toStdString() << std::endl;
            std::cout << r.toStdString() << std::endl;

            enigmes[k] = Enigme(q, r);
        }
    }catch(...){
        QMessageBox::critical(this, "Erreur", "Le fichier questions.txt n'a pas pu lu correctement");
        exit(0);
    }

    diag = new DialogCompte(this);
    diag->show();
    connect(diag, SIGNAL(fini()), this, SLOT(perdu()));

    ui->label_2->setText(QString::number(i+1) + QString("/") + QString::number(enigmes.size()));
    ui->label->setText(enigmes[i].texte);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_bouton_pressed(){
    QString t = ui->reponse->text();
    if(t == enigmes[i].response){
        continuer();
        ui->reponse->clear();
    }else{
        diag->enleverminute();
        QMessageBox::critical(this, "Erreur", "Erreur... une minute de moins...");
    }
}

void Widget::continuer(){
    i += 1;
    if(i < enigmes.size()){
        ui->label_2->setText(QString::number(i+1) + QString("/") + QString::number(enigmes.size()));
        ui->label->setText(enigmes[i].texte);
    }else{
        QMessageBox::information(this, "Bravo", "Félicitation, la porte est maintenant ouverte");
        exit(0);
    }
}

void Widget::perdu(){
    diag->close();
    QMessageBox::critical(this, "Perdu", "Vous avez perdu");
    exit(0);
}
