#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsLineItem>
#include <QGraphicsTextItem>

class Edge  : public QGraphicsLineItem {
private:
    int weight;
    QGraphicsTextItem* text;
    bool isGreen;
    int xi,xe,yi,ye;
public:
    Edge(int,int,int,int,int);
    void changeToGreen();
    void changeToBlack();
    int getWeight();
    QGraphicsTextItem* getText();
    bool isLineGreen();
    int getXi();
    int getXe();
    int getYi();
    int getYe();
};

#endif // EDGE_H
