#ifndef STAT_PRODUCTIONANIMAUX_H
#define STAT_PRODUCTIONANIMAUX_H

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
class Stat_productionanimaux;
class QPieSlice;
}

class Stat_productionanimaux : public QDialog
{
    Q_OBJECT

public:
    explicit Stat_productionanimaux(QWidget *parent = nullptr);
    ~Stat_productionanimaux();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;

    void paintEvent(QPaintEvent *) ;
private:
    Ui::Stat_productionanimaux *ui;
};

#endif // STAT_PRODUCTIONANIMAUX_H
