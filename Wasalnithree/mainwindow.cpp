#include "mainwindow.h"
#include <QFileDialog>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QMessageBox>
#include <QtGui>
#include "city.h"
#include "ui_mainwindow.h"
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

void MainWindow::on_saveButton_clicked()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyy-MM-dd-hh-mm-ss");
    QString currentDir = QDir::currentPath();

    // Save city data
    QString cityFileName = "City-" + dateTimeString + ".txt";
    QFile cityFile(cityFileName);
    if (cityFile.open(QIODevice::WriteOnly)) {
        QTextStream out(&cityFile);
        for (const auto &entry : graph->getAdjList()) {
            out << entry.first->getName() << " " << entry.first->getX() << " "
                << entry.first->getY() << "\n";
        }
        cityFile.close();
        QMessageBox::information(this,
                                 "Success",
                                 "City data saved to " + cityFileName + " in " + currentDir);
    } else {
        QMessageBox::critical(this, "Error", "Failed to save city data");
    }

    // Save edge data
    QString edgeFileName = "Edge-" + dateTimeString + ".txt";
    QFile edgeFile(edgeFileName);
    if (edgeFile.open(QIODevice::WriteOnly)) {
        QTextStream out(&edgeFile);
        QSet<QString> writtenEdges; // Keep track of written edges
        for (const auto &entry : graph->getAdjList()) {
            QString vertexName = entry.first->getName();
            for (const auto &edge : entry.second) {
                QString adjacentVertexName = edge.first->getName();
                QString edgeKey = vertexName < adjacentVertexName
                                      ? vertexName + " " + adjacentVertexName
                                      : adjacentVertexName + " " + vertexName;
                if (!writtenEdges.contains(edgeKey)) {
                    out << vertexName << " " << adjacentVertexName << " " << edge.second << "\n";
                    writtenEdges.insert(edgeKey);
                }
            }
        }
        edgeFile.close();
        QMessageBox::information(this,
                                 "Success",
                                 "Edge data saved to " + edgeFileName + " in " + currentDir);
    } else {
        QMessageBox::critical(this, "Error", "Failed to save edge data");
    }
}

void MainWindow::on_LoadCitiesButton_clicked()
{
    // Clear existing city data from the graph
    // graph.clearCities();

    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Load Data",
                                                    QDir::currentPath(),
                                                    "Text files (*.txt)");
    if (filePath.isEmpty()) {
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open file for reading");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() >= 3) {
            QString cityName = parts[0];
            int x = parts[1].toInt();
            int y = parts[2].toInt();
            City *city = new City(cityName, x, y);
            graph->addCity(city);
        }
    }

    file.close();
    QMessageBox::information(this, "Success", "Data loaded successfully from " + filePath);
}

void MainWindow::on_LoadEdgesButton_clicked()
{
    // Clear existing edge data from the graph
    // graph.clearEdges();

    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Load Edge Data",
                                                    QDir::currentPath(),
                                                    "Text files (*.txt)");
    if (filePath.isEmpty()) {
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open file for reading");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() >= 3) {
            QString city1Name = parts[0];
            QString city2Name = parts[1];
            int weight = parts[2].toInt();
            City *city1 = graph->findCity(city1Name);
            City *city2 = graph->findCity(city2Name);
            if (city1 && city2) {
                graph->addEdge(city1, city2, weight);
            } else {
                qDebug() << "One or both cities not found while loading edge data";
            }
        }
    }

    file.close();
    QMessageBox::information(this, "Success", "Edge data loaded successfully from " + filePath);
}
