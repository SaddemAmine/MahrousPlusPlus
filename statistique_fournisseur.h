#ifndef STATISTIQUE_FOURNISSEUR_H
#define STATISTIQUE_FOURNISSEUR_H


#include <QDialog>
#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
namespace Ui {
class Statistique_fournisseur;
}

class Statistique_fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique_fournisseur(QWidget *parent = nullptr);
    ~Statistique_fournisseur();
    int Statistique_partie2() ;
    int Statistique_partie3() ;
    int Statistique_partie4() ;

    void paintEvent(QPaintEvent *) ;
private:
    Ui::Statistique_fournisseur *ui;
};

#endif // STATISTIQUE_FOURNISSEUR_H
