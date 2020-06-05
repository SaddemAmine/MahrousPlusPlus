#ifndef STAT_PRODUCTIONPLANTE_H
#define STAT_PRODUCTIONPLANTE_H

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
class stat_productionplante;
}

class stat_productionplante : public QDialog
{
    Q_OBJECT

public:
    explicit stat_productionplante(QWidget *parent = nullptr);
    ~stat_productionplante();

    int Stat_partie2();
    int Stat_partie3();
    int Stat_partie4();
    void paintEvent(QPaintEvent *);
private:
    Ui::stat_productionplante *ui;
};

#endif // STAT_PRODUCTIONPLANTE_H
