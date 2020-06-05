#include "stat_plante.h"
#include "ui_stat_plante.h"

Stat_plante::Stat_plante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stat_plante)
{
    ui->setupUi(this);

}

Stat_plante::~Stat_plante()
{
    delete ui;
}
int Stat_plante::Stat_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PLANTES where QUANTITE BETWEEN '1' AND '99'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Stat_plante::Stat_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PLANTES where QUANTITE BETWEEN '100' AND '999'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Stat_plante::Stat_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PLANTES where QUANTITE BETWEEN '1000' AND '9999'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void Stat_plante::paintEvent(QPaintEvent *)
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
    ui->label_2->setText("1-99") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("100-999") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("1000-9999") ;

}
