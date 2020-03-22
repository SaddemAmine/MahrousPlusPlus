#include "animale.h"
#include "ui_animale.h"

animale::animale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::animale)
{
    ui->setupUi(this);
}

animale::~animale()
{
    delete ui;
}
