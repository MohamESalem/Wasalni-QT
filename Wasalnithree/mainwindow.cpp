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
    currCityFile = NULL;
    currEdgeFile = NULL;
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

void MainWindow::showNoPathMsg()
{
    QMessageBox::critical(this, "No Path", "Sorry! No path exists between these two cities");
}

void MainWindow::showPressRMsg()
{
    QMessageBox::critical(this, "Clear The Effect First", "Press R to find the shortest path between other cities!");
}

void MainWindow::saveNewCityFile()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyy-MM-dd-hh-mm-ss");
    QString currentDir = QDir::currentPath();

    // Save city data
    QString cityFileName = "City-" + dateTimeString + ".txt";
    QFile cityFile("../" + cityFileName);
    if (cityFile.open(QIODevice::WriteOnly)) {
        QTextStream out(&cityFile);
        for (const auto &entry : graph->getAdjList()) {
            out << entry.first->getName() << " " << entry.first->getX() << " "
                << entry.first->getY() << "\n";
        }
        cityFile.flush();
        cityFile.close();
        QMessageBox::information(this,
                                 "Success",
                                 "City data saved to " + cityFileName + " in " + currentDir);
    } else {
        QMessageBox::critical(this, "Error", "Failed to save city data");
    }
}

void MainWindow::saveCurrCityFile()
{
    if(currCityFile->open(QIODevice::WriteOnly)) {
        QTextStream out(currCityFile);
        for (const auto &entry : graph->getAdjList()) {
            out << entry.first->getName() << " " << entry.first->getX() << " "
                << entry.first->getY() << "\n";
        }
        currCityFile->flush();
        currCityFile->close();
        QMessageBox::information(this, "Success", "City data saved in " + currCityFile->fileName());
    } else {
        QMessageBox::critical(this, "Error", "Failed to save city data");
    }
}

void MainWindow::saveNewEdgeFile()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyy-MM-dd-hh-mm-ss");
    QString currentDir = QDir::currentPath();

    // Save edge data
    QString edgeFileName = "Edge-" + dateTimeString + ".txt";
    QFile edgeFile("../" + edgeFileName);
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
        edgeFile.flush();
        edgeFile.close();
        QMessageBox::information(this,
                                 "Success",
                                 "Edge data saved to " + edgeFileName + " in " + currentDir);
    } else {
        QMessageBox::critical(this, "Error", "Failed to save edge data");
    }
}

void MainWindow::saveCurrEdgeFile()
{
    if(currEdgeFile->open(QIODevice::WriteOnly)) {
        QTextStream out(currEdgeFile);
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
        currEdgeFile->flush();
        currEdgeFile->close();
        QMessageBox::information(this, "Success", "Edge data saved to " + currEdgeFile->fileName());
    } else {
        QMessageBox::critical(this, "Error", "Failed to save edge data");
    }
}

void MainWindow::on_addButton_clicked()
{
    QLineEdit* xL = ui->xAddText,
        * yL = ui->yAddText,
                  * cityL = ui->cityNameAddText;
    int x = xL->text().toInt();
    int y = yL->text().toInt();
    QString cityName = cityL->text();
    // check if x and y are valid coordinates

    if((!xL->text().isEmpty() && !yL->text().isEmpty() && !cityL->text().isEmpty())
        && (x >= 0 && x <= 800) && (y >= 0 && y <= 630))
    {
        City* c=new City(cityName, x, y);
        if(graph->findCity(c->getName())) {
            ui->add_text_error->setVisible(true);
        } else {
            graph->addCity(c);
            ui->add_text_error->setVisible(false);
            ui->cityNameAddText->clear();
            ui->xAddText->clear();
            ui->yAddText->clear();
        }
    } // else output error message
    else
    {
        ui->add_text_error->setVisible(true);
    }
}

void MainWindow::on_addEdgeButton_clicked()
{
    QLineEdit* c1L = ui->city1AddEdgeText,
             * c2L = ui->cityAddEdgeText,
             * wL = ui->edgeAddEdgeText;
    City* c1 = graph->findCity(c1L->text()),
        * c2 = graph->findCity(c2L->text());
    int weight = wL->text().toInt();

    if(!wL->text().isEmpty() && c1 != NULL && c2 != NULL && !graph->isEdgeExist(c1,c2)) {
        graph->addEdge(c1, c2, weight);
        ui->add_edge_text_error->setVisible(false);
        ui->cityAddEdgeText->clear();
        ui->city1AddEdgeText->clear();
        ui->edgeAddEdgeText->clear();
    } else {
        ui->add_edge_text_error->setVisible(true);
    }
}

void MainWindow::on_remove_clicked()
{
    City* c = graph->findCity(ui->cityNameRemoveText->text());
    if(c==NULL && !ui->cityNameRemoveText->text().isEmpty())
    {
        ui->remove_text_error->setVisible(true);
    }
    else
    {
        ui->remove_text_error->setVisible(false);
        graph->removeCity(c);
        ui->cityNameRemoveText->clear();
    }
}

void MainWindow::on_removeEdgeButton_clicked()
{
    QLineEdit* c1L = ui->removeEdge1,
        * c2L = ui->removeEdge2;
    if(!c1L->text().isEmpty() && !c2L->text().isEmpty() &&
        graph->isEdgeExist(graph->findCity(c1L->text()), graph->findCity(c2L->text())))
    {
        graph->removeEdge(graph->findCity(ui->removeEdge1->text()), graph->findCity(ui->removeEdge2->text()));
        ui->remove_edge_text_error->setVisible(false);
        ui->removeEdge1->clear();
        ui->removeEdge2->clear();
    } else {
        ui->remove_edge_text_error->setVisible(true);
    }
}

void MainWindow::on_saveButton_clicked()
{
    if(currCityFile == NULL && currEdgeFile == NULL) {
        // Create the message box
        saveNewCityFile();
        saveNewEdgeFile();
    } else {
        // QString cityFilePath = currCityFile ? currCityFile->fileName() : "",
        //     edgeFilePath = currEdgeFile ? currEdgeFile->fileName() : "";
        QMessageBox msgBox;
        msgBox.setWindowTitle("Save Your Changes");
        msgBox.setText("Do you want to save the changes in the same loaded files or in new files?");
        msgBox.addButton("Same Files", QMessageBox::YesRole);
        msgBox.addButton("New Files", QMessageBox::NoRole);

        // Execute the message box and process the result
        int result = msgBox.exec();

        // Check which button was clicked
        if (result == 0) {
            // User clicked "Same Files"
            if(currCityFile == NULL)
                saveNewCityFile();
            else
                saveCurrCityFile();

            if(currEdgeFile == NULL)
                saveNewEdgeFile();
            else
                saveCurrEdgeFile();

        } else {
            // User clicked "New Files"
            saveNewCityFile();
            saveNewEdgeFile();
        }
    }
}

void MainWindow::on_LoadCitiesButton_clicked()
{

    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Load Data",
                                                    QDir::currentPath(),
                                                    "Text files (*.txt)");
    if (filePath.isEmpty()) {
        return;
    }

    // set the currCityFile to the one pointed to by filePath
    currCityFile = new QFile(filePath);
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open file for reading");
        return;
    }

    // clear the current map
    map->restart();
    graph->clearAdjList();
    currCityFile = currEdgeFile = NULL;

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

    // set the currEdgeFile to the one pointed to by filePath
    currEdgeFile = new QFile(filePath);

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

void MainWindow::on_clearButton_clicked()
{
    map->restart();
    graph->clearAdjList();
    currCityFile = currEdgeFile = NULL;
}


void MainWindow::on_homeViewButton_clicked()
{
    map->resetView();
}

