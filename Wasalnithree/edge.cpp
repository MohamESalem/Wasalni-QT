#include "edge.h"
#include <QPen>
#include <QFont>

// constructor
Edge::Edge(int x1, int y1, int x2, int y2, int w) {

    //intializing cords
    weight = w;
    xi = x1;
    xe = x2;
    yi = y1;
    ye = y2;
    // qDebug() << "xi = " << xi << '\n';

    // manipulate x1, y1, x2, y2
    x1 += 35;
    x2 += 35;
    y1 += 35;
    y2 += 35;


    // draw the line
    setLine(x1, y1, x2, y2);
    changeToBlack();
    setZValue(1);

    // set the text
    text = new QGraphicsTextItem(this);

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

void Edge::changeToGreen()
{
    QPen greenPen(Qt::green);
    greenPen.setWidth(4);
    setPen(greenPen);
    isGreen = true;
}

void Edge::changeToBlack()
{
    QPen blackPen(Qt::black);
    blackPen.setWidth(2);
    setPen(blackPen);
    isGreen = false;
}

// getters
int Edge::getWeight() {return weight;}
QGraphicsTextItem* Edge::getText() {return text;}
bool Edge::isLineGreen() {return isGreen;}
int Edge::getXi() {return xi;}
int Edge::getYi() {return yi;}
int Edge::getXe() {return xe;}
int Edge::getYe() {return ye;}
