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
    cityName = name;
    selected = false;
    // set the text
    text = new QGraphicsTextItem(this);
    text->setFont(QFont("times",10));
    isBold = false;
    text->setDefaultTextColor(Qt::black);
    text->setPlainText(name);
    // set the city's image
    setPixmap(QPixmap(":/images/images/blue.png").scaled(70,70));
    setZValue(3);
    // set the city position
    setCityPos(this->x, this->y);
}

void City::setCityPos(int x, int y)
{
    setPos(x,y);
    int offsetX = 3, textX = 75/2.0 - text->boundingRect().width()/2.0 - offsetX, // center the text horizontally
        offsetY = 60;

    text->setPos(textX, offsetY);
}

void City::mousePressEvent(QGraphicsSceneMouseEvent*event) {
    if(event->button() == Qt::LeftButton) {
        // if(w->getMap()->getFirstPressed() != this) w->getMap()->incrementClicks();
        if(!w->getMap()->getFinshed()) {
            selected = true;
            if(w->getMap()->getFirstPressed() == NULL) {
                setPixmap(QPixmap(":/images/images/orange.png").scaled(70,70));
                boldText();
                w->getMap()->setFirstPressed(this);
            } else {
                setPixmap(QPixmap(":/images/images/green.png").scaled(70,70));
                boldText();
                w->getMap()->setFinished(true);
                // We should hanlde the case if no path exists
                if(!w->getGraph()->isPathExist(w->getMap()->getFirstPressed(), this)) {
                    // output message to the user
                    w->showNoPathMsg();
                    // qDebug() << "Not Found!\n";
                } else {
                    std::vector<City*> path = w->getGraph()->dijkstra(w->getMap()->getFirstPressed(), this).second;
                    for(size_t i = 0; i < path.size() - 1; i++) {
                        Edge* e = w->getGraph()->findEdge(path[i]->getX(), path[i]->getY(), path[i+1]->getX(), path[i+1]->getY());
                        e->changeToGreen();
                        if(i + 1 != path.size() - 1) path[i+1]->boldText();
                    }
                }
            }
        } else {
            w->showPressRMsg();
            // qDebug() << "Test is working!\n";
        }
    }
}

void City::boldText()
{
    QFont font("times", 10);
    font.setBold(true);
    text->setFont(font);
    isBold = true;
}

void City::unBoldText()
{
    QFont font("times", 10);
    font.setBold(false);
    text->setFont(font);
    isBold = false;
}

void City::useBlueImg()
{
    setPixmap(QPixmap(":/images/images/blue.png").scaled(70,70));
}

// getters
QGraphicsTextItem *City::getText() {return text;}
QString City::getName() {return cityName;}
int City::getX() {return x;}
int City::getY() {return y;}
bool City::isTextBold() {return isBold;}
bool City::isSelected() {return selected;}

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

