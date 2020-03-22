#include "plante.h"
#include "ui_plante.h"

plante::plante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plante)
{
    ui->setupUi(this);
}

plante::~plante()
{
    delete ui;
}
