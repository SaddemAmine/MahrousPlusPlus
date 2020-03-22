#include "produitanimal.h"
#include "ui_produitanimal.h"

produitanimal::produitanimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produitanimal)
{
    ui->setupUi(this);
}

produitanimal::~produitanimal()
{
    delete ui;
}
