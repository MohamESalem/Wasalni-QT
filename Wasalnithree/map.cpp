#include "map.h"
#include "edge.h"
#include <QFile>
#include <QTextStream>

Map::Map() {
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 630);
    // initialize the view's properties
    setFixedSize(800, 630);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle("Map");
}

void Map::readCityFile()
{
    QFile file(":/files/files/city.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString name;
    int x, y;
    while(!in.atEnd()) {
        in >> name >> x >> y;
        if(!name.isEmpty()) {
            City* c = new City(name,x,y);
            scene->addItem(c);
        }
    }
    file.close();
}

void Map::readEdgeFile()
{
    QFile file(":/files/files/edge.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    int x1, y1, x2, y2, w;
    while(!in.atEnd()) {
        in >> x1 >> y1 >> x2 >> y2 >> w;
        if(x1 || y1 || x2 || y2) { // if at least one value is not zero, then this a valid edge
            Edge* e = new Edge(x1,y1,x2,y2,w);
            scene->addItem(e);
        }
    }
}

void Map::start() {
    // initialize data members
    clicks = 0;
    firstPressed = NULL;
    // set the scene
    setScene(scene);

    // tests
    c1 = new City("Alexandria", 10, 10);
    // scene->addItem(c1);
    // scene->addItem(c1->getText());

    c2 = new City("Cairo", 180, 170);
    // scene->addItem(c2);
    // scene->addItem(c2->getText());

    c3 = new City("Ismailia", 10 * 3 + 100 * 2 + 60 * 2, 10);
    // scene->addItem(c3);

    // Edge* e1 = new Edge(c1->getX(), c1->getY(), c2->getX(), c2->getY(), 2);
    // scene->addItem(e1);

    // Edge* e2 = new Edge(c1->getX(), c1->getY(), c3->getX(), c3->getY(), 7);
    // scene->addItem(e2);

    // Edge* e3 = new Edge(c3->getX(), c3->getY(), c2->getX(), c2->getY(), 3);
    // scene->addItem(e3);

    // read data from city and edge files
    readData();

    // show the view
    show();
}

void Map::incrementClicks() {
    clicks++;
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

void Map::readData()
{
    readCityFile();
    readEdgeFile();
}

// getters
int Map::getClicks() {return clicks;}
QGraphicsScene *Map::getScene() {return scene;}
City *Map::getFirstPressed() {return firstPressed;}
