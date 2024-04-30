#include "edge.h"
#include <QPen>
#include <QFont>

// constructor
Edge::Edge(int x1, int y1, int x2, int y2, int w, bool b) {
    // colors
    QPen blackPen(Qt::black);
    blackPen.setWidth(2);
    QPen greenPen(Qt::green);
    greenPen.setWidth(4);
    weight = w;

    // manipulate x1, y1, x2, y2
    x1 += 45;
    x2 += 45;
    y1 += 45;
    y2 += 45;

    // draw the line
    setLine(x1, y1, x2, y2);
    setZValue(1);

    // set the text
    text = new QGraphicsTextItem(this);
    if(w != 0) {
        QFont font("times", 10);
        // font.setBold(true);
        text->setFont(font);
        text->setDefaultTextColor(Qt::black);
        text->setPlainText(QString::number(weight));

        int offset = 0;
        double textX = (x1+x2)/2.0 - 0, textY = (y1+y2)/2.0 - offset;

        text->setZValue(5);
        text->setPos(textX, textY);
        // rotate the text
        QLineF ln(QPointF(x1, y1), QPointF(x2, y2));
        double angle = -1 * ln.angle();
        if(x1 > x2) angle += 180;
        text->setRotation(angle);
    }


    if(!b)
        setPen(blackPen);
    else
        setPen(greenPen);

}


// getters
int Edge::getWeight() {return weight;}
QGraphicsTextItem* Edge::getText() {return text;}