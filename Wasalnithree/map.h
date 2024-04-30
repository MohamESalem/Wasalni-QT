#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "city.h"

class Map : public QGraphicsView
{
private:
    QGraphicsScene* scene;
    City* firstPressed;
    int clicks;
    void readCityFile();
    void readEdgeFile();
public:
    Map();
    QGraphicsScene* getScene();
    void start();
    int getClicks();
    void incrementClicks();
    City* getFirstPressed();
    void setFirstPressed(City*);
    void restart();
    void readData();
    // FOR TESTING PURPOSES
    City* c1;
    City* c2;
    City* c3;
};

#endif // MAP_H
