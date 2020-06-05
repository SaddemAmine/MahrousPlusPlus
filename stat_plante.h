#ifndef STAT_PLANTE_H
#define STAT_PLANTE_H

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
class Stat_plante;
class QPieSlice;
}

class Stat_plante : public QDialog
{
    Q_OBJECT

public:
    explicit Stat_plante(QWidget *parent = nullptr);
    ~Stat_plante();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;

    void paintEvent(QPaintEvent *) ;
private:
    Ui::Stat_plante *ui;
};

#endif // STAT_PLANTE_H
