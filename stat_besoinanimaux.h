#ifndef STAT_BESOINANIMAUX_H
#define STAT_BESOINANIMAUX_H

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
class stat_besoinanimaux;
class QPieSlice;
}

class stat_besoinanimaux : public QDialog
{
    Q_OBJECT

public:
    explicit stat_besoinanimaux(QWidget *parent = nullptr);
    ~stat_besoinanimaux();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;

    void paintEvent(QPaintEvent *) ;
private:
    Ui::stat_besoinanimaux *ui;
};

#endif // STAT_BESOINANIMAUX_H
