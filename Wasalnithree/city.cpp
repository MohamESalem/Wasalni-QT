#include "city.h"
#include "mainwindow.h"
#include <QFont>
#include "edge.h"

extern MainWindow* w;

City::City(QString name,int x,int y)
{
    // initialize data members
    this->x = x;
    this->y = y;
    cityName=name;
    // set the text
    text = new QGraphicsTextItem(this);
    text->setFont(QFont("times",12));
    text->setDefaultTextColor(Qt::black);
    text->setPlainText(name);
    // set the city's image
    setPixmap(QPixmap(":/images/images/blue.png").scaled(90,90));
    setZValue(3);
    // set the city position
    setCityPos(this->x, this->y);
}

void City::setCityPos(int x, int y)
{
    setPos(x,y);
    int offsetX = 3, textX = 90/2.0 - text->boundingRect().width()/2.0 - offsetX, // center the text horizontally
        offsetY = 80;

    text->setPos(textX, offsetY);
}

void City::mousePressEvent(QGraphicsSceneMouseEvent*event) {
    if(event->button() == Qt::LeftButton) {
        // if(w->getMap()->getFirstPressed() != this) w->getMap()->incrementClicks();
        if(!w->getMap()->getFinshed()) {
            if(w->getMap()->getFirstPressed() == NULL) {
                setPixmap(QPixmap(":/images/images/orange.png").scaled(90,90));
                boldText();
                w->getMap()->setFirstPressed(this);
            } else {
                setPixmap(QPixmap(":/images/images/green.png").scaled(90,90));
                boldText();
                w->getMap()->setFinished(true);
                // We should hanlde the case if no path exists
                if(!w->getGraph()->isPathExist(w->getMap()->getFirstPressed(), this)) {
                    qDebug() << "Not Found!\n";
                } else {
                    std::vector<City*> path = w->getGraph()->dijkstra(w->getMap()->getFirstPressed(), this).second;
                    for(size_t i = 0; i < path.size() - 1; i++) {
                        Edge* e = new Edge(path[i]->getX(), path[i]->getY(), path[i+1]->getX(), path[i+1]->getY(), 0, true);
                        scene()->addItem(e);
                        if(i + 1 != path.size() - 1) path[i+1]->boldText();
                    }
                }
            }
        }
    }
}

void City::boldText()
{
    QFont font("times", 12);
    font.setBold(true);
    text->setFont(font);
}

// getters
QGraphicsTextItem *City::getText() {return text;}

QString City::getName()
{
    return cityName;
}
int City::getX() {return x;}
int City::getY() {return y;}

// overloaded functions

bool City::operator<(const City &other)
{
    City* temp = this;
    return (temp->text->toPlainText() < other.text->toPlainText());
}

bool City::operator==(const City &other)
{
    City* temp = this;
    return (temp->text->toPlainText() == other.text->toPlainText());
}
bool City::operator!=(const City &other)
{
    City* temp = this;
    return (temp->text->toPlainText() != other.text->toPlainText());
}

