#include "stat_productionanimaux.h"
#include "ui_stat_productionanimaux.h"

Stat_productionanimaux::Stat_productionanimaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stat_productionanimaux)
{
    ui->setupUi(this);

}

Stat_productionanimaux::~Stat_productionanimaux()
{
    delete ui;
}
int Stat_productionanimaux::Stat_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PRODUCTIONANIMAUX where PRIXPRODUCTIONANIMAUX BETWEEN '1' AND '20'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Stat_productionanimaux::Stat_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PRODUCTIONANIMAUX where PRIXPRODUCTIONANIMAUX BETWEEN '21' AND '50'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Stat_productionanimaux::Stat_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PRODUCTIONANIMAUX where PRIXPRODUCTIONANIMAUX BETWEEN '51' AND '9999'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void Stat_productionanimaux::paintEvent(QPaintEvent *)
{

    int b=Stat_partie2();
    //cout<<b<<endl ;
    int c=Stat_partie3();
   // cout<<c<<endl ;
    int d=Stat_partie4();
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

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("1-4") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("4-6") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("6-..") ;

}
