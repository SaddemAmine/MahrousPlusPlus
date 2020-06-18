#include "reclamations_rh.h"
#include "ui_reclamations_rh.h"
#include <QDebug>

reclamations_rh::reclamations_rh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reclamations_rh)
{
    ui->setupUi(this);
    reclamations r;
    ui->comboBox->setModel(r.preplist());
}

reclamations_rh::~reclamations_rh(){
    delete ui;
}

void reclamations_rh::on_comboBox_currentIndexChanged(){
    QString whereClause = ui->comboBox->model()->data(ui->comboBox->model()->index(ui->comboBox->currentIndex(),1)).toString();
    reclamations r;
    QSqlQueryModel * model = r.loadreclamation(whereClause);
    ui->textBrowser->setText(model->data(model->index(0,0)).toString());
    ui->textEdit->setText(model->data(model->index(0,1)).toString());
}

void reclamations_rh::on_pushButton_2_clicked(){
    reclamations r;
    QString whereClause = ui->comboBox->model()->data(ui->comboBox->model()->index(ui->comboBox->currentIndex(),1)).toString();
    r.updatereclamation(whereClause,ui->textEdit->toPlainText(),ui->checkBox->isChecked() ? 1 : 0);
    //list refresh if the checkbox is checked
    if(ui->checkBox->isChecked())
       ui->comboBox->setModel(r.preplist());
}
