/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *addButton;
    QLineEdit *cityNameRemoveText;
    QPushButton *LoadCitiesButton;
    QPushButton *LoadEdgesButton;
    QPushButton *saveButton;
    QPushButton *homeViewButton;
    QLineEdit *yAddText;
    QLineEdit *removeEdge2;
    QLineEdit *xAddText;
    QPushButton *addEdgeButton;
    QLineEdit *removeEdge1;
    QLineEdit *cityAddEdgeText;
    QLineEdit *edgeAddEdgeText;
    QPushButton *remove;
    QLineEdit *city1AddEdgeText;
    QPushButton *removeEdgeButton;
    QPushButton *clearButton;
    QLineEdit *cityNameAddText;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1100, 630);
        MainWindow->setMinimumSize(QSize(1100, 630));
        MainWindow->setMaximumSize(QSize(1100, 630));
        MainWindow->setStyleSheet(QString::fromUtf8("/* Set image as background for main window */\n"
"#MainWindow{\n"
"\n"
"}\n"
"\n"
"/* Set style for function widget */\n"
"#widget {\n"
"background-color: #343155;\n"
"border-radius: 5px;\n"
"\n"
"}\n"
"\n"
"/* Set style for Qlabel */\n"
"QLabel {\n"
"color: #fff;\n"
"}\n"
"/* Set style for QLineEdit */\n"
"QLineEdit {\n"
"background-color: #5b586e;\n"
"border-radius: 16px;\n"
"padding: 5px 0;\n"
"border: 1px solid #5b586e;\n"
"color: #fff;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"border: 1px solid #8b86aa;\n"
"background-color: #343155;\n"
"}\n"
"\n"
"/* Set style for QPushButton */\n"
"QPushButton {\n"
"background-color: #FBDFDF;\n"
"border: 1px solid #343155;\n"
"color: #2E0606;\n"
"border-radius: 16px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:clicked {\n"
"background-color: #F7C9C9;\n"
"border: 1px solid #9ac3fe;\n"
"\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(1100, 630));
        centralwidget->setMaximumSize(QSize(1100, 630));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, -10, 791, 631));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(820, 89, 250, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(9);
        font.setBold(false);
        addButton->setFont(font);
        cityNameRemoveText = new QLineEdit(centralwidget);
        cityNameRemoveText->setObjectName("cityNameRemoveText");
        cityNameRemoveText->setGeometry(QRect(820, 129, 250, 30));
        cityNameRemoveText->setFont(font);
        LoadCitiesButton = new QPushButton(centralwidget);
        LoadCitiesButton->setObjectName("LoadCitiesButton");
        LoadCitiesButton->setGeometry(QRect(822, 530, 79, 30));
        LoadCitiesButton->setMinimumSize(QSize(0, 30));
        LoadCitiesButton->setFont(font);
        LoadEdgesButton = new QPushButton(centralwidget);
        LoadEdgesButton->setObjectName("LoadEdgesButton");
        LoadEdgesButton->setGeometry(QRect(907, 530, 79, 30));
        LoadEdgesButton->setMinimumSize(QSize(0, 30));
        LoadEdgesButton->setFont(font);
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(820, 489, 250, 30));
        saveButton->setFont(font);
        homeViewButton = new QPushButton(centralwidget);
        homeViewButton->setObjectName("homeViewButton");
        homeViewButton->setGeometry(QRect(820, 569, 250, 30));
        homeViewButton->setFont(font);
        yAddText = new QLineEdit(centralwidget);
        yAddText->setObjectName("yAddText");
        yAddText->setGeometry(QRect(948, 49, 121, 30));
        yAddText->setFont(font);
        removeEdge2 = new QLineEdit(centralwidget);
        removeEdge2->setObjectName("removeEdge2");
        removeEdge2->setGeometry(QRect(820, 409, 250, 30));
        removeEdge2->setFont(font);
        xAddText = new QLineEdit(centralwidget);
        xAddText->setObjectName("xAddText");
        xAddText->setGeometry(QRect(820, 49, 121, 30));
        xAddText->setFont(font);
        addEdgeButton = new QPushButton(centralwidget);
        addEdgeButton->setObjectName("addEdgeButton");
        addEdgeButton->setGeometry(QRect(820, 329, 250, 30));
        addEdgeButton->setFont(font);
        removeEdge1 = new QLineEdit(centralwidget);
        removeEdge1->setObjectName("removeEdge1");
        removeEdge1->setGeometry(QRect(820, 369, 250, 30));
        removeEdge1->setFont(font);
        cityAddEdgeText = new QLineEdit(centralwidget);
        cityAddEdgeText->setObjectName("cityAddEdgeText");
        cityAddEdgeText->setGeometry(QRect(820, 249, 250, 30));
        cityAddEdgeText->setFont(font);
        edgeAddEdgeText = new QLineEdit(centralwidget);
        edgeAddEdgeText->setObjectName("edgeAddEdgeText");
        edgeAddEdgeText->setGeometry(QRect(820, 289, 250, 30));
        edgeAddEdgeText->setFont(font);
        remove = new QPushButton(centralwidget);
        remove->setObjectName("remove");
        remove->setGeometry(QRect(820, 169, 250, 30));
        remove->setFont(font);
        city1AddEdgeText = new QLineEdit(centralwidget);
        city1AddEdgeText->setObjectName("city1AddEdgeText");
        city1AddEdgeText->setGeometry(QRect(820, 209, 250, 30));
        city1AddEdgeText->setFont(font);
        removeEdgeButton = new QPushButton(centralwidget);
        removeEdgeButton->setObjectName("removeEdgeButton");
        removeEdgeButton->setGeometry(QRect(820, 449, 250, 30));
        removeEdgeButton->setFont(font);
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(992, 530, 79, 30));
        clearButton->setMinimumSize(QSize(0, 30));
        clearButton->setFont(font);
        cityNameAddText = new QLineEdit(centralwidget);
        cityNameAddText->setObjectName("cityNameAddText");
        cityNameAddText->setGeometry(QRect(820, 9, 250, 30));
        cityNameAddText->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        homeViewButton->raise();
        yAddText->raise();
        removeEdge2->raise();
        xAddText->raise();
        addEdgeButton->raise();
        removeEdge1->raise();
        cityAddEdgeText->raise();
        edgeAddEdgeText->raise();
        remove->raise();
        city1AddEdgeText->raise();
        removeEdgeButton->raise();
        clearButton->raise();
        gridLayoutWidget->raise();
        addButton->raise();
        cityNameRemoveText->raise();
        LoadCitiesButton->raise();
        LoadEdgesButton->raise();
        saveButton->raise();
        cityNameAddText->raise();
        QWidget::setTabOrder(cityNameAddText, xAddText);
        QWidget::setTabOrder(xAddText, yAddText);
        QWidget::setTabOrder(yAddText, addButton);
        QWidget::setTabOrder(addButton, cityNameRemoveText);
        QWidget::setTabOrder(cityNameRemoveText, remove);
        QWidget::setTabOrder(remove, city1AddEdgeText);
        QWidget::setTabOrder(city1AddEdgeText, cityAddEdgeText);
        QWidget::setTabOrder(cityAddEdgeText, edgeAddEdgeText);
        QWidget::setTabOrder(edgeAddEdgeText, addEdgeButton);
        QWidget::setTabOrder(addEdgeButton, removeEdge1);
        QWidget::setTabOrder(removeEdge1, removeEdge2);
        QWidget::setTabOrder(removeEdge2, removeEdgeButton);
        QWidget::setTabOrder(removeEdgeButton, saveButton);
        QWidget::setTabOrder(saveButton, LoadCitiesButton);
        QWidget::setTabOrder(LoadCitiesButton, LoadEdgesButton);
        QWidget::setTabOrder(LoadEdgesButton, clearButton);
        QWidget::setTabOrder(clearButton, homeViewButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Wasalni", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        cityNameRemoveText->setText(QString());
        cityNameRemoveText->setPlaceholderText(QCoreApplication::translate("MainWindow", "City Name", nullptr));
        LoadCitiesButton->setText(QCoreApplication::translate("MainWindow", "Load Cities", nullptr));
        LoadEdgesButton->setText(QCoreApplication::translate("MainWindow", "Load Edges", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        homeViewButton->setText(QCoreApplication::translate("MainWindow", "Home View", nullptr));
        yAddText->setText(QString());
        yAddText->setPlaceholderText(QCoreApplication::translate("MainWindow", "Y-coordinate", nullptr));
        removeEdge2->setText(QString());
        removeEdge2->setPlaceholderText(QCoreApplication::translate("MainWindow", "City 2", nullptr));
        xAddText->setText(QString());
        xAddText->setPlaceholderText(QCoreApplication::translate("MainWindow", "X-coordinate", nullptr));
        addEdgeButton->setText(QCoreApplication::translate("MainWindow", "Add Edge", nullptr));
        removeEdge1->setText(QString());
        removeEdge1->setPlaceholderText(QCoreApplication::translate("MainWindow", "City 1", nullptr));
        cityAddEdgeText->setText(QString());
        cityAddEdgeText->setPlaceholderText(QCoreApplication::translate("MainWindow", "City 2", nullptr));
        edgeAddEdgeText->setText(QString());
        edgeAddEdgeText->setPlaceholderText(QCoreApplication::translate("MainWindow", "Weight", nullptr));
        remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        city1AddEdgeText->setText(QString());
        city1AddEdgeText->setPlaceholderText(QCoreApplication::translate("MainWindow", "City 1", nullptr));
        removeEdgeButton->setText(QCoreApplication::translate("MainWindow", "Remove Edge", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        cityNameAddText->setText(QString());
        cityNameAddText->setPlaceholderText(QCoreApplication::translate("MainWindow", "City Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
