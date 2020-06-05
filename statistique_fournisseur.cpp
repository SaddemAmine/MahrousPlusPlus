#include "statistique_fournisseur.h"
#include "ui_statistique_fournisseur.h"

Statistique_fournisseur::Statistique_fournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique_fournisseur)
{
    ui->setupUi(this);
}

Statistique_fournisseur::~Statistique_fournisseur()
{
    delete ui;
}
int Statistique_fournisseur::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from fournisseurmateriaux where AGE BETWEEN '20' AND '30'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Statistique_fournisseur::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from fournisseurmateriaux where age BETWEEN '31' AND '40'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Statistique_fournisseur::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from fournisseurmateriaux where age BETWEEN '41' AND '50'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}

void Statistique_fournisseur::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    //cout<<b<<endl ;
    int c=Statistique_partie3();
   // cout<<c<<endl ;
    int d=Statistique_partie4();
    //cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::gray);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("20-30") ;
    painter.setBrush(Qt::magenta);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("31-40") ;
    painter.setBrush(Qt::cyan);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("41-50") ;

}
