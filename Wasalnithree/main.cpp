#include "mainwindow.h"
#include "menu.h"

#include <QApplication>
#include <QGraphicsView>

MainWindow* w;
Menu * m;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new MainWindow();
    m = new Menu(w);




    return a.exec();
}
