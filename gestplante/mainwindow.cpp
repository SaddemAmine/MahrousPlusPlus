#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_categorie_clicked()
{
    cat=new categorie_plante(this);
    cat->show();
}

void MainWindow::on_pushButton_clicked()
{
    pl = new plante(this);
    pl->show();
}
