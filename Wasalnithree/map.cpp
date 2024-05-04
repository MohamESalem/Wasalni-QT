#include "map.h"
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QCoreApplication>
#include <QTransform>
#include "mainwindow.h"
#include <QWheelEvent>

extern MainWindow* w;

Map::Map() {
    // initialize the view's properties
    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle("Map");
}

void Map::start() {
    // initialize data members
    finished = false;
    firstPressed = NULL;
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    // set the scene
    setScene(scene);

    // set background image
    setBackgroundBrush(QPixmap(":/images/images/bg1.jpg").scaled(800,600));

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

void Map::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_R) {
        finished = false;
        firstPressed = NULL;
        w->getGraph()->removeDijkstraEffects();
    }
}

void Map::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.05;
    if(event->angleDelta().y() > 0) {
        // Zoom in
        scale(scaleFactor, scaleFactor);
    } else {
        // Zooming out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }
}

void Map::resetView()
{
    setTransform(QTransform());
}

// getters
bool Map::getFinshed() {return finished;}
QGraphicsScene *Map::getScene() {return scene;}
City *Map::getFirstPressed() {return firstPressed;}
