#ifndef STATISQTIQUE_MATERIEL_H
#define STATISQTIQUE_MATERIEL_H

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
class Statisqtique_materiel;
class QPieSlice;
}

class Statisqtique_materiel : public QDialog
{
    Q_OBJECT

public:
    explicit Statisqtique_materiel(QWidget *parent = nullptr);
    ~Statisqtique_materiel();
    int Statistique_partie2() ;
    int Statistique_partie3() ;
    int Statistique_partie4() ;

    void paintEvent(QPaintEvent *) ;
private:
    Ui::Statisqtique_materiel *ui;
};

#endif // STATISQTIQUE_MATERIEL_H
