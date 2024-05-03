#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>

MainWindow* w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new MainWindow();
    w->start();
    return a.exec();
}
