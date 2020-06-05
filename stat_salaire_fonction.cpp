#include "stat_salaire_fonction.h"
#include "ui_stat_salaire_fonction.h"

stat_salaire_fonction::stat_salaire_fonction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_salaire_fonction)
{
    ui->setupUi(this);
}

stat_salaire_fonction::~stat_salaire_fonction()
{
    delete ui;
}
int stat_salaire_fonction::Stat_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from fonctions where SALAIRE BETWEEN '10' AND '100'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int stat_salaire_fonction::Stat_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from fonctions where salaire BETWEEN '101' AND '500'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int stat_salaire_fonction::Stat_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from fonctions where salaire BETWEEN '501' AND '999'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void stat_salaire_fonction::paintEvent(QPaintEvent *)
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
    ui->label_2->setText("10-100") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("101-500") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("501-999") ;

}
