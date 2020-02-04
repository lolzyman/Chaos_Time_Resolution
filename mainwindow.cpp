#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayGraph(){
    generateRegularSeries();
    generateLambdaSeriesOne();
    generateLambdaSeriesTwo();
    QLineSeries * weirdLambdaSeries = new QLineSeries();
    generateGLambdaSeries(weirdLambdaSeries);

    displayChart->legend()->hide();
    displayChart->addSeries(regularSeries);
    displayChart->addSeries(lambdaSeriesOne);
    displayChart->addSeries(lambdaSeriesTwo);
    displayChart->addSeries(weirdLambdaSeries);
    displayChart->createDefaultAxes();
    displayChart->setTitle("Time exploration of Chaos Theory");

    chartViewer->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartViewer);
    this->show();
}

void MainWindow::generateRegularSeries(){
    double current_value = initial_value;
    for(int i = 0; i < maxNIndex; i++){
        regularSeries->append(i, current_value);
        current_value = regularEquation(current_value);
    }
}

void MainWindow::generateLambdaSeriesOne(){
    double current_value = initial_value;
    for(double i = 0; i < maxNIndex; i += lambdaOne){
        lambdaSeriesOne->append(i, current_value);
        current_value = lambdaEquationOne(current_value);
    }
}

void MainWindow::generateLambdaSeriesTwo(){
    double current_value = initial_value;
    for(double i = 0; i < maxNIndex; i += lambdaTwo){
        lambdaSeriesTwo->append(i, current_value);
        current_value = lambdaEquationTwo(current_value);
    }
}

void MainWindow::generateGLambdaSeries(QLineSeries *targetSeries){
    double current_value = initial_value;
    for(double i = 0; i < maxNIndex; i += gLambda){
        targetSeries->append(i, current_value);
        current_value = genericLambdaEquation(current_value);
    }
}

double MainWindow::regularEquation(double value){
    return r_constant * (value - value * value);
}

double MainWindow::lambdaEquationOne(double value){
    return lambdaOne * (r_constant * (value - value * value) + value);
}

double MainWindow::lambdaEquationTwo(double value){
    return lambdaTwo * r_constant * (value - value * value) + 3 * lambdaTwo * value;
}

double MainWindow::genericLambdaEquation(double value){
    return gLambda * r_constant * (value - value * value) + (1 - gLambda) * value;
}
