#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double lambdaOne = 0.5;
    double lambdaTwo = 0.25;
    double r_constant = 2;
    double gLambda = 0.333333;
    double initial_value = 0.015;
    double maxNIndex = 12;

private:
    Ui::MainWindow *ui;
    QLineSeries *regularSeries = new QLineSeries();
    QLineSeries *lambdaSeriesOne = new QLineSeries();
    QLineSeries *lambdaSeriesTwo = new QLineSeries();
    QChart *displayChart = new QChart();
    QChartView *chartViewer = new QChartView(displayChart);

    void displayGraph();
    void generateRegularSeries();
    void generateLambdaSeriesOne();
    void generateLambdaSeriesTwo();
    void generateGLambdaSeries(QLineSeries *targetSeries);
    double lambdaEquationOne(double value);
    double lambdaEquationTwo(double value);
    double regularEquation(double value);
    double genericLambdaEquation(double value);

};
#endif // MAINWINDOW_H
