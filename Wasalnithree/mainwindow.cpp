#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QtGui>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    QGraphicsRectItem *rect = new QGraphicsRectItem(0,0,798,628);
    scene->addItem(rect);
    QGridLayout *grid = ui->gridLayout_3;
    Map = new QGraphicsView(scene);
    grid->addWidget(Map, 1, 1);



}

MainWindow::~MainWindow()
{


    delete ui;
}
