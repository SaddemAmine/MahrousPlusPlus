#include "photo.h"
#include "ui_photo.h"

photo::photo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::photo)
{
    ui->setupUi(this);
}

photo::~photo()
{
    delete ui;
}
void photo::setchemin(QString n )
{
    ui->chemin->setText(n);
    qApp->installEventFilter(this);

    //creiamo la scena
    scena = new QGraphicsScene(0,0, 500, 500);

    //aggiungiamo una bitmap da file alla scena
    immagine_gi = scena->addPixmap(QPixmap(ui->chemin->text()));


    //agganciamo la view, la `telecamera`, alla scena
    ui->graphicsView->setScene(scena);

    //`accendiamo` la telecamera, attiviamo cioè la view
    ui->graphicsView->show();
}
