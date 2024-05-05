#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "mainwindow.h"
namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(MainWindow *w,QWidget *parent = nullptr);
    ~Menu();

public slots:
    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
    MainWindow *w;
};

#endif // MENU_H
