#include "besoinplante.h"
#include "ui_besoinplante.h"

besoinplante::besoinplante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::besoinplante)
{
    ui->setupUi(this);
}

besoinplante::~besoinplante()
{
    delete ui;
}
