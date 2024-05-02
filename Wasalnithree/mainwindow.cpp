#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QtGui>
#include "city.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGridLayout *grid = ui->gridLayout_3;
    graph = new Graph();
    map = new Map();
    grid->addWidget(map, 1, 1);
    map->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

Map *MainWindow::getMap()
{
    return map;
}

Graph *MainWindow::getGraph()
{
    return graph;
}

void MainWindow::on_addButton_clicked()
{
    int x = ui->xAddText->text().toInt();
    int y = ui->yAddText->text().toInt();
    QString cityName = ui->cityNameAddText->text();
    // check if x and y are valid coordinates
    if((x >= 0 && x <= 800) && (y >= 0 && y <= 630)) {
        City* c=new City(cityName, x, y);
        graph->addCity(c);
        map->getScene()->addItem(c);
        map->getScene()->addItem(c->getText());
    }
}


void MainWindow::on_addEdgeButton_clicked()
{
    City* c1 = graph->findCity(ui->city1AddEdgeText->text()),
        * c2 = graph->findCity(ui->cityAddEdgeText->text());
    int weight = ui->edgeAddEdgeText->text().toInt();
    if(c1 != NULL && c2 != NULL) {
        graph->addEdge(c1, c2, weight);
    } // else we should output error

}


void MainWindow::on_remove_clicked()
{
    graph->removeCity(graph->findCity(ui->cityNameRemoveText->text()));

}


void MainWindow::on_removeEdgeButton_clicked()
{
    graph->removeEdge(graph->findCity(ui->removeEdge1->text()),graph->findCity(ui->removeEdge2->text()));
}

