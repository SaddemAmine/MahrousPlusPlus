#include "typeanimal.h"
#include "ui_typeanimal.h"

typeanimal::typeanimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::typeanimal)
{
    ui->setupUi(this);
}

typeanimal::~typeanimal()
{
    delete ui;
}
