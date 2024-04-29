#ifndef CITY_H
#define CITY_H

#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
class City {
private:
    QGraphicsTextItem* text;
    QGraphicsPixmapItem* image;
public:
    City(QString name,int x,int y);
    void setCityPos(int x,int y);
    QGraphicsTextItem* getText();// to add them to scene
    QGraphicsPixmapItem* getImage();
};

#endif // CITY_H
