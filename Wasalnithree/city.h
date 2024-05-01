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
    QString cityName;
    QGraphicsTextItem* text;
public:
    City(QString name,int x,int y);
    void setCityPos(int x,int y);
    QGraphicsTextItem* getText();
    QString getName();
    void boldText();
    int getX();
    int getY();
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    bool operator<(const City &other);
    bool operator==(const City &other);
    bool operator!=(const City &other);
};

#endif // CITY_H
