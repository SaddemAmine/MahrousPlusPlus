#ifndef STAT_BESOINPLANTES_H
#define STAT_BESOINPLANTES_H
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
#include <QDialog>

namespace Ui {
class stat_besoinplantes;
}

class stat_besoinplantes : public QDialog
{
    Q_OBJECT

public:
    explicit stat_besoinplantes(QWidget *parent = nullptr);
    ~stat_besoinplantes();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;

    void paintEvent(QPaintEvent *) ;
private:
    Ui::stat_besoinplantes *ui;
};

#endif // STAT_BESOINPLANTES_H
