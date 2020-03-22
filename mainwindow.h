#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
#include "materiaux.h"
#include "fonction.h"
#include "plantes.h"
#include "resh.h"
#include "animaux.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void myfunction();

    /*void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();




    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();*/

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    QMediaPlayer *click;
    materiaux *m;
    plantes *p;
    resh *r;
    animaux *a;

};

#endif // MAINWINDOW_H
