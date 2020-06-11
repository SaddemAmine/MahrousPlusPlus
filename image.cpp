#include "image.h"
#include "ui_image.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QWheelEvent>
#include <QDialog>
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QScrollBar>
image::image(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::image)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

image::~image()
{
    delete ui;
}
void image::setchemin(QString n )
{
    ui->chemin_2->setText(n);
    qApp->installEventFilter(this);

    //creiamo la scena
    scena = new QGraphicsScene(0,0, 500, 500);

    //aggiungiamo una bitmap da file alla scena
    immagine_gi = scena->addPixmap(QPixmap(ui->chemin_2->text()));


    //agganciamo la view, la `telecamera`, alla scena
    ui->graphicsView->setScene(scena);

    //`accendiamo` la telecamera, attiviamo cioè la view
    ui->graphicsView->show();

    ui->horizontalSlider->valueChanged( ui->horizontalSlider->value() );
    ui->dial->valueChanged( ui->dial->value() );
}
void image::on_actionZoomInOut_triggered()
{
     immagine_gi->setScale( ui->horizontalSlider->value()/10.0 );
}


void image::on_horizontalSlider_valueChanged(int value)
{
    ui->sliderValueLBL->setText( QString::number(value*10) + "%" );

    ui->actionZoomInOut->trigger();
}

void image::on_dial_valueChanged(int value)
{
    ui->dialValueLBL->setText( QString::number(value)  );

    ui->actionRotate->trigger();
}

void image::on_actionRotate_triggered()
{
     immagine_gi->setRotation( ui->dial->value() );
}
void image::mousePressEvent(QMouseEvent * event)
{//click->play();
    if(event->button() == Qt::RightButton)
    {
        right_down=true;
        ui->rigth_LBL->setText("Right Down");
        setCursor(Qt::ClosedHandCursor);

        inizio_pan_x = event->x();
        inizio_pan_y = event->y();
    }
    else
        if (event->button() == Qt::LeftButton)
        {
            left_down=true;
            ui->left_LBL->setText("Left Down");
        }
}

void image::mouseReleaseEvent(QMouseEvent * event)
{
    if(event->button() == Qt::RightButton)
    {
        right_down=false;
        ui->rigth_LBL->setText("Right Up");
        setCursor(Qt::ArrowCursor);
    }
    else
        if (event->button() == Qt::LeftButton)
        {
            left_down=false;
            ui->left_LBL->setText("Left Up");
        }
}

void image::wheelEvent(QWheelEvent *event)
{
    if (ctrl_down)
    {
        //ui->statusBar->showMessage(QString::number(debug_counter));

        if (event->angleDelta().y() >0 ) //zoom in
        {
            immagine_gi->setScale( immagine_gi->scale() + 0.1);
        }
        else
        {
            immagine_gi->setScale( immagine_gi->scale() - 0.1);
        }
    }
}


void image::mouseMoveEvent(QMouseEvent *event){
    if (right_down)
    {
        //di quanto si è spostato il mouse?
        int mouse_delta_x = event->x() - inizio_pan_x;
        int mouse_delta_y = event->y() - inizio_pan_y;

        //posizioni attuali delle scrollbar
        int posizione_attuale_scrollbar_H =
                ui->graphicsView->horizontalScrollBar()->value();
        int posizione_attuale_scrollbar_V =
                ui->graphicsView->verticalScrollBar()->value();

        //aggiorniamo in direzione opposta allo spostamento del mouse
        //la posizione delle scrollbaar
        ui->graphicsView->horizontalScrollBar()->
                setValue( posizione_attuale_scrollbar_H - mouse_delta_x);
        ui->graphicsView->verticalScrollBar()->
                setValue(posizione_attuale_scrollbar_V - mouse_delta_y);


        //aggiorniamo posizione del mouse per prossimo pan
        inizio_pan_x = event->x();
        inizio_pan_y = event->y();
    }
}

void image::keyPressEvent(QKeyEvent *k)
{
    if (k->key() == Qt::Key_Control) {ctrl_down = true;}
    ui->ctrl_LBL->setText("CTRL down");

}

void image::keyReleaseEvent(QKeyEvent *k)
{
    if (k->key() == Qt::Key_Control) {ctrl_down = false;}
    ui->ctrl_LBL->setText("CTRL up");

}
