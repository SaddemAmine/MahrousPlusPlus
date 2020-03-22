#include "productionpalnte.h"
#include "ui_productionpalnte.h"

productionpalnte::productionpalnte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::productionpalnte)
{
    ui->setupUi(this);
}

productionpalnte::~productionpalnte()
{
    delete ui;
}
