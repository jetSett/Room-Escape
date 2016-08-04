#ifndef DIALOGCOMPTE_H
#define DIALOGCOMPTE_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class DialogCompte;
}

class DialogCompte : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCompte(QWidget *parent = 0);
    ~DialogCompte();
    void enleverminute(){
        minRestant --;
        update();
    }
    void update();

public slots:
    void time();

signals:
    void fini();

private:
    QTimer *compte;
    Ui::DialogCompte *ui;
    int secRestant = 20;
    int minRestant = 59;
};

#endif // DIALOGCOMPTE_H
