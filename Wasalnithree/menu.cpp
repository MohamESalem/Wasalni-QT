#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"


Menu::Menu(MainWindow *w, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->show();
    this->w =w;

}

Menu::~Menu()
{
    delete ui;
}




void Menu::on_pushButton_clicked()
{

    this->close();
    w->start();
}

