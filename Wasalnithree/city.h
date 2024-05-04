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
    bool isBold;
    bool selected;
public:
    City(QString,int,int);
    void setCityPos(int,int);
    QGraphicsTextItem* getText();
    QString getName();
    void boldText();
    void unBoldText();
    int getX();
    int getY();
    bool isTextBold();
    bool isSelected();
    void useBlueImg();
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    bool operator<(const City &other);
    bool operator==(const City &other);
    bool operator!=(const City &other);
};

#endif // CITY_H
