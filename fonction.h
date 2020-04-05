#ifndef FONCTION_H
#define FONCTION_H
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QDialog>
#include "materielle.h"
namespace Ui {
class fonction;
}

class fonction : public QDialog
{
    Q_OBJECT

public:
    explicit fonction(QWidget *parent = nullptr);
    ~fonction();

private slots:
    //void on_pushButton_clicked();

   // void on_pushButton_f_clicked();

    //void on_pushButton_2_f_clicked();



   // void on_modifier_f_clicked();

   // void on_supprimer_f_clicked();

    void on_pushButton_f_clicked();

    void on_pushButton_2_f_clicked();

    void on_comboBox_modif_currentIndexChanged();

    void on_modifier_f_clicked();

    void on_supprimer_f_clicked();

private:
    Ui::fonction *ui;
    QTimer *timer;
QMediaPlayer *click;
};

#endif // FONCTION_H
