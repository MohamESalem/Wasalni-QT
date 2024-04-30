#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsLineItem>
#include <QGraphicsTextItem>

class Edge  : public QGraphicsLineItem {
private:
    int weight;
    QGraphicsTextItem* text;
public:
    Edge(int,int,int,int,int,bool=false);
    int getWeight();
    QGraphicsTextItem* getText();
};

#endif // EDGE_H
