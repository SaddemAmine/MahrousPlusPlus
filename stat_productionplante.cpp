#include "stat_productionplante.h"
#include "ui_stat_productionplante.h"

stat_productionplante::stat_productionplante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_productionplante)
{
    ui->setupUi(this);
}

stat_productionplante::~stat_productionplante()
{
    delete ui;
}
int stat_productionplante::Stat_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PRODUCTIONPLANTE where PRIXPRODUITPLANTE BETWEEN '10' AND '50'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int stat_productionplante::Stat_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PRODUCTIONPLANTE where PRIXPRODUITPLANTE BETWEEN '51' AND '70'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int stat_productionplante::Stat_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PRODUCTIONPLANTE where PRIXPRODUITPLANTE BETWEEN '71' AND '100'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void stat_productionplante::paintEvent(QPaintEvent *)
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
    ui->label_2->setText("10-50") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("51-70") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("71-100") ;

}
