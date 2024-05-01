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
    City();
    void setCityPos(int x,int y);
    QGraphicsTextItem *getText() const; // to add them to scene
    QGraphicsPixmapItem* getImage();
    bool operator<(const City &other) const;
    bool operator==(const City &other) const;
    bool operator!=(const City &other) const;
};

#endif // CITY_H
