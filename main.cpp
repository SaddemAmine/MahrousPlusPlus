#include "menu.h"
#include <QSplashScreen>
#include <QTimer>
#include <QApplication>
#include <QMediaPlayer>
#include<QDebug>
#include <QMessageBox>
#include "connexion.h"
#include <QMediaPlayer>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QSplashScreen *splash=new QSplashScreen ;
    splash->setPixmap(QPixmap("A:/PROJET QT/qt/logo.png"));
            splash->show();


    connexion c;

    QMessageBox msgBox;
    bool test=c.createconnect();
     Menu w;
    if(test)
    {
        QTimer::singleShot(10000,splash,SLOT(close()));
            QTimer::singleShot(2500,&w,SLOT(show()));

       // w.show();
//w.showFullScreen()
        /*QMessageBox::information(nullptr, QObject::tr("Database is opened"),
                    QObject::tr("Connection Successful.\n"
                                "Click OK to continue."), QMessageBox::Ok);*/
        QPixmap pix("A:/LOGO.png");

       msgBox.setText("Database is opened\nConnection Successful.\nClick OK to continue.");
       msgBox.setIconPixmap(pix);
        msgBox.exec();



}
    else
   {
    QPixmap pix("A:/LOGO.png");

   msgBox.setText("Connection Failed.\n"
                  "Click Cancel to exit.");
   msgBox.setIconPixmap(pix);
    msgBox.exec();
}
    return a.exec();
}
