#ifndef LOGIN_H
#define LOGIN_H
#include"menu.h"
#include <QMainWindow>
#include <QStateMachine>
#include <QEventTransition>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include "parametre.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_3_clicked();

private:
    Ui::Login *ui;

parametre *p;
    QPropertyAnimation *animation;
   QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;


    QParallelAnimationGroup *animationGroup;
Menu *m;

};
#endif // LOGIN_H
