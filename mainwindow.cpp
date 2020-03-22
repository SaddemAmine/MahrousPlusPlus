#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
qApp->setStyle(QStyleFactory::create("Fusion"));
    QPixmap pix("F:/Esprit/year_2/qt/projects/crud/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->status->setText("Connected...");
  timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
  timer->start(1000);

  click = new QMediaPlayer();
  click->setMedia(QUrl::fromLocalFile("A:/PROJET QT/crud/click.mp3"));

}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::myfunction()
{
    QTime time = QTime::currentTime();
QString time_text = time.toString ("hh : mm : ss");
if ((time.second()%2) == 0){
    time_text[3] = ' ';
    time_text[8] = ' ';
}
ui->time_label->setText(time_text);
}



/*void MainWindow::on_pushButton_4_clicked()
{
//hide();
 m= new materielle(this);
 m->show();

}

void MainWindow::on_pushButton_5_clicked()
{
    f =new fonction(this);
    f->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    p=new personnel (this);
    p->show();
}*/

void MainWindow::on_pushButton_clicked()
{
  /* QPixmap pixl("A:/PROJET QT/qt/certificatauthentification.png");
   int w =ui->picc->width();
   int h =ui->picc->height();
     ui->picc->setPixmap(pixl.scaled(w,h,Qt::KeepAspectRatio));*/
    QString res = ui->cx_login->text() ;
    QString res1 = ui->cx_mdp->text() ;
    if (res=="plante" && res1=="plante")
    {

        p = new plantes(this) ;
        p->show() ;
    }
    else if (res=="resh" && res1=="resh")
    {

        r = new resh(this) ;
        r->show() ;
    }
    else if (res=="animaux" && res1=="animaux")
    {
        a =new animaux(this);
        a->show();
    }
    else if (res=="materiaux" && res1=="materiaux")
    {
        m=new materiaux(this );
        m->show();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur d'authentification"),
                    QObject::tr("Information incorrecte .\n"
                                "Click Close to exit."), QMessageBox::Close);
    }
}
