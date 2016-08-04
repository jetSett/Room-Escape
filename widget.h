#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include <QWidget>
#include <QMessageBox>
#include <QVector>
#include <QFile>
#include "dialogcompte.h"

struct Enigme{
    Enigme(QString t, QString r) : texte(t), response(r){

    }
    Enigme(){

    }

    QString texte;
    QString response;
};

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void continuer();

public slots:
    void on_bouton_pressed();
    void perdu();
private:
    DialogCompte* diag;
    Ui::Widget *ui;
    int i = 0;
    QVector<Enigme> enigmes;
};

#endif // WIDGET_H
