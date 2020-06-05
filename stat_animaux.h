#ifndef STAT_ANIMAUX_H
#define STAT_ANIMAUX_H

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
class Stat_animaux;
class QPieSlice;
}

class Stat_animaux : public QDialog
{
    Q_OBJECT

public:
    explicit Stat_animaux(QWidget *parent = nullptr);
    ~Stat_animaux();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;

    void paintEvent(QPaintEvent *) ;
private:
    Ui::Stat_animaux *ui;
};

#endif // STAT_ANIMAUX_H
