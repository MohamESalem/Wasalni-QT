#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "city.h"

class Map : public QGraphicsView
{
private:
    QGraphicsScene* scene;
    City* firstPressed;
    bool finished;
public:
    Map();
    QGraphicsScene* getScene();
    void start();
    City* getFirstPressed();
    void setFirstPressed(City*);
    void restart();
    void setFinished(bool);
    bool getFinshed();
};

#endif // MAP_H
