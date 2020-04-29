#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"categorie_plante.h"
#include"plante.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_categorie_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    categorie_plante *cat;
    plante *pl;
};
#endif // MAINWINDOW_H
