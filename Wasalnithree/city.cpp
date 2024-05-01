#include "city.h"
#include <QFont>
City::City(QString name,int x,int y)
{
    text=new QGraphicsTextItem;
    text->setFont(QFont("times",16));
    text->setDefaultTextColor(Qt::black);
    text->setPlainText(name);
    image=new QGraphicsPixmapItem;
    image->setPixmap(QPixmap(":/images/images/location.png").scaled(70,70));
    setCityPos(x,y);
}
City::City(){};
void City::setCityPos(int x, int y)
{
    image->setPos(x,y);
    text->setPos(x+10,y+60);
}

QGraphicsTextItem *City::getText() const
{
    return text;
}

QGraphicsPixmapItem *City::getImage()
{
    return image;
}

bool City::operator<(const City &other) const
{
    City temp = *this;
    return (temp.getText()->toPlainText() < other.getText()->toPlainText());
}
bool City::operator==(const City &other) const
{
    City temp = *this;
    return (temp.getText()->toPlainText() == other.getText()->toPlainText());
}
bool City::operator!=(const City &other) const
{
    City temp = *this;
    return (temp.getText()->toPlainText() != other.getText()->toPlainText());
}
