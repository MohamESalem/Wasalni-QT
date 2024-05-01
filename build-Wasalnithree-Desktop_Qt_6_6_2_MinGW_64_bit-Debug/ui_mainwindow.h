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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *addButton;
    QPushButton *remove;
    QFrame *line;
    QLineEdit *cityNameRemoveText;
    QFrame *line_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *edgeAddEdgeText;
    QLineEdit *city1AddEdgeText;
    QLineEdit *cityAddEdgeText;
    QPushButton *addEdgeButton;
    QFrame *line_3;
    QPushButton *findShortestPathButton;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *cityNameAddText;
    QLineEdit *xAddText;
    QLineEdit *yAddText;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *cityOnePathText;
    QLineEdit *cityTwoPathText;
    QFrame *line_4;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *edgeRemoveEdgeText;
    QLineEdit *cityRemoveEdgeText;
    QPushButton *removeEdgeButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(815, 780);
        MainWindow->setMinimumSize(QSize(804, 780));
        MainWindow->setMaximumSize(QSize(900, 900));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(804, 780));
        centralwidget->setMaximumSize(QSize(804, 780));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, 640, 821, 131));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        addButton = new QPushButton(frame);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 100, 111, 24));
        remove = new QPushButton(frame);
        remove->setObjectName("remove");
        remove->setGeometry(QRect(169, 90, 111, 24));
        line = new QFrame(frame);
        line->setObjectName("line");
        line->setGeometry(QRect(150, 0, 16, 131));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        cityNameRemoveText = new QLineEdit(frame);
        cityNameRemoveText->setObjectName("cityNameRemoveText");
        cityNameRemoveText->setGeometry(QRect(170, 20, 108, 24));
        line_2 = new QFrame(frame);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(280, 0, 16, 131));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(300, 10, 110, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        edgeAddEdgeText = new QLineEdit(layoutWidget);
        edgeAddEdgeText->setObjectName("edgeAddEdgeText");

        verticalLayout_2->addWidget(edgeAddEdgeText);

        city1AddEdgeText = new QLineEdit(layoutWidget);
        city1AddEdgeText->setObjectName("city1AddEdgeText");

        verticalLayout_2->addWidget(city1AddEdgeText);

        cityAddEdgeText = new QLineEdit(layoutWidget);
        cityAddEdgeText->setObjectName("cityAddEdgeText");

        verticalLayout_2->addWidget(cityAddEdgeText);

        addEdgeButton = new QPushButton(frame);
        addEdgeButton->setObjectName("addEdgeButton");
        addEdgeButton->setGeometry(QRect(299, 90, 111, 24));
        line_3 = new QFrame(frame);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(420, 0, 16, 131));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        findShortestPathButton = new QPushButton(frame);
        findShortestPathButton->setObjectName("findShortestPathButton");
        findShortestPathButton->setGeometry(QRect(590, 90, 191, 24));
        layoutWidget_2 = new QWidget(frame);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 10, 111, 94));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cityNameAddText = new QLineEdit(layoutWidget_2);
        cityNameAddText->setObjectName("cityNameAddText");

        verticalLayout->addWidget(cityNameAddText);

        xAddText = new QLineEdit(layoutWidget_2);
        xAddText->setObjectName("xAddText");

        verticalLayout->addWidget(xAddText);

        yAddText = new QLineEdit(layoutWidget_2);
        yAddText->setObjectName("yAddText");

        verticalLayout->addWidget(yAddText);

        layoutWidget_3 = new QWidget(frame);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(590, 20, 191, 64));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        cityOnePathText = new QLineEdit(layoutWidget_3);
        cityOnePathText->setObjectName("cityOnePathText");

        verticalLayout_3->addWidget(cityOnePathText);

        cityTwoPathText = new QLineEdit(layoutWidget_3);
        cityTwoPathText->setObjectName("cityTwoPathText");

        verticalLayout_3->addWidget(cityTwoPathText);

        line_4 = new QFrame(frame);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(570, 0, 16, 131));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        layoutWidget_4 = new QWidget(frame);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(450, 20, 110, 96));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        edgeRemoveEdgeText = new QLineEdit(layoutWidget_4);
        edgeRemoveEdgeText->setObjectName("edgeRemoveEdgeText");

        verticalLayout_4->addWidget(edgeRemoveEdgeText);

        cityRemoveEdgeText = new QLineEdit(layoutWidget_4);
        cityRemoveEdgeText->setObjectName("cityRemoveEdgeText");

        verticalLayout_4->addWidget(cityRemoveEdgeText);

        removeEdgeButton = new QPushButton(frame);
        removeEdgeButton->setObjectName("removeEdgeButton");
        removeEdgeButton->setGeometry(QRect(450, 90, 111, 24));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 0, 801, 631));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Wasalni", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        cityNameRemoveText->setText(QCoreApplication::translate("MainWindow", "City Name", nullptr));
        edgeAddEdgeText->setText(QCoreApplication::translate("MainWindow", "Weight", nullptr));
        city1AddEdgeText->setText(QCoreApplication::translate("MainWindow", "City1", nullptr));
        cityAddEdgeText->setText(QCoreApplication::translate("MainWindow", "City2", nullptr));
        addEdgeButton->setText(QCoreApplication::translate("MainWindow", "Add Edge", nullptr));
        findShortestPathButton->setText(QCoreApplication::translate("MainWindow", "Find Shortest Path", nullptr));
        cityNameAddText->setText(QCoreApplication::translate("MainWindow", "City Name", nullptr));
        xAddText->setText(QCoreApplication::translate("MainWindow", "X coordinate", nullptr));
        yAddText->setText(QCoreApplication::translate("MainWindow", "Y coordinate", nullptr));
        cityOnePathText->setText(QCoreApplication::translate("MainWindow", "City 1", nullptr));
        cityTwoPathText->setText(QCoreApplication::translate("MainWindow", "City 2", nullptr));
        edgeRemoveEdgeText->setText(QCoreApplication::translate("MainWindow", "Edge", nullptr));
        cityRemoveEdgeText->setText(QCoreApplication::translate("MainWindow", "City", nullptr));
        removeEdgeButton->setText(QCoreApplication::translate("MainWindow", "Remove Edge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
