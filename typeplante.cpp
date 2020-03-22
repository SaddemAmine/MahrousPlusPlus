#include "typeplante.h"
#include "ui_typeplante.h"

typeplante::typeplante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::typeplante)
{
    ui->setupUi(this);
}

typeplante::~typeplante()
{
    delete ui;
}
