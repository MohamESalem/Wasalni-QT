#include "map.h"
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QCoreApplication>
#include "mainwindow.h"

extern MainWindow* w;

Map::Map() {
    // initialize the view's properties
    setFixedSize(800, 630);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle("Map");
}

void Map::start() {
    // initialize data members
    finished = false;
    firstPressed = NULL;
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 630);

    // set the scene
    setScene(scene);

    // set background image
    setBackgroundBrush(QPixmap(":/images/images/bg2.jpg").scaled(800,630));

    // show the view
    show();
}

void Map::setFirstPressed(City* c) {
    firstPressed = c;
}


void Map::restart()
{
    foreach(QGraphicsItem *item, scene->items()) {
        scene->removeItem(item);
        delete item;
    }
    scene->clear();

    start();
}

void Map::setFinished(bool b)
{
    finished = b;
}

// getters
bool Map::getFinshed() {return finished;}


QGraphicsScene *Map::getScene() {return scene;}
City *Map::getFirstPressed() {return firstPressed;}
