#include "besoinanimal.h"
#include "ui_besoinanimal.h"

besoinanimal::besoinanimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::besoinanimal)
{
    ui->setupUi(this);
}

besoinanimal::~besoinanimal()
{
    delete ui;
}
