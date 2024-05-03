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
    ui->cityNameAddText->setPlaceholderText("City Name");
     ui->remove_text_error->setVisible(false);
     ui->remove_edge_text_error->setVisible(false);
      ui->add_text_error->setVisible(false);
     ui->add_edge_text_error->setVisible(false);
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

void MainWindow::start()
{
    QGridLayout *grid = ui->gridLayout_3;
    map = new Map();
    grid->addWidget(map, 1, 1);
    map->start();
    graph = new Graph();
    show();
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
        ui->add_text_error->setVisible(false);
    } // else output error message
    else
    ui->add_text_error->setVisible(true);
}

void MainWindow::on_addEdgeButton_clicked()
{
    City* c1 = graph->findCity(ui->city1AddEdgeText->text()),
        * c2 = graph->findCity(ui->cityAddEdgeText->text());
    int weight = ui->edgeAddEdgeText->text().toInt();
     if(c1 != NULL && c2 != NULL) {
    graph->addEdge(c1, c2, weight);
     ui->add_edge_text_error->setVisible(false);
    } // else we should output error
     else{
         ui->add_edge_text_error->setVisible(true);}
}


void MainWindow::on_remove_clicked()
{
    City* c = graph->findCity(ui->cityNameRemoveText->text());
    if(c==NULL)
    {
        ui->remove_text_error->setVisible(true);
    }
    else
    {ui->remove_text_error->setVisible(false);
        graph->removeCity(c);}
}


void MainWindow::on_removeEdgeButton_clicked()
{
    if(graph->isEdgeExist(graph->findCity(ui->removeEdge1->text()),graph->findCity(ui->removeEdge2->text())))
    {graph->removeEdge(graph->findCity(ui->removeEdge1->text()),graph->findCity(ui->removeEdge2->text()));
      ui->remove_edge_text_error->setVisible(false);
    }
    else
        ui->remove_edge_text_error->setVisible(true);
}

