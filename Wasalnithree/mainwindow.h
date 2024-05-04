#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "graph.h"
#include "map.h"
#include <QFile>

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
    QFile* currCityFile;
    QFile* currEdgeFile;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Map* getMap();
    Graph* getGraph();
    void start();
    void showNoPathMsg();
    void showPressRMsg();
    void saveNewCityFile();
    void saveCurrCityFile();
    void saveNewEdgeFile();
    void saveCurrEdgeFile();

private slots:
    void on_addButton_clicked();

    void on_addEdgeButton_clicked();

    void on_remove_clicked();

    void on_removeEdgeButton_clicked();

    void on_saveButton_clicked();

    void on_LoadCitiesButton_clicked();

    void on_LoadEdgesButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
