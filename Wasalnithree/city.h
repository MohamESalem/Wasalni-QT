#ifndef CITY_H
#define CITY_H

#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class City : public QGraphicsPixmapItem {
private:
    int x;
    int y;
    QGraphicsTextItem* text;
public:
    City(QString name,int x,int y);
    void setCityPos(int x,int y);
    QGraphicsTextItem* getText();
    void boldText();
    int getX();
    int getY();
    void mousePressEvent(QGraphicsSceneMouseEvent*);
};

#endif // CITY_H