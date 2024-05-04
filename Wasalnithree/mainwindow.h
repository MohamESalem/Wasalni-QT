#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "graph.h"
#include "map.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Map* map;
    Graph* graph;
public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Map* getMap();
    Graph* getGraph();
    void start();

private slots:
    void on_addButton_clicked();

    void on_addEdgeButton_clicked();

    void on_remove_clicked();

    void on_removeEdgeButton_clicked();

    void on_saveButton_clicked();

    void on_LoadCitiesButton_clicked();

    void on_LoadEdgesButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
