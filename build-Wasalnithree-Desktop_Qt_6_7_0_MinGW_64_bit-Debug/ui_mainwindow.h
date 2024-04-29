/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
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
    QLineEdit *cityRemoveText;
    QFrame *line_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *edgeRemoveEdgeText;
    QLineEdit *cityRemoveEdgeText;
    QPushButton *removeEdgeButton;
    QFrame *line_3;
    QPushButton *findShortestPathButton;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *edgeText;
    QLineEdit *cityAddText;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *cityOnePathText;
    QLineEdit *cityTwoPathText;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 440, 801, 131));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        addButton = new QPushButton(frame);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(10, 90, 80, 24));
        remove = new QPushButton(frame);
        remove->setObjectName("remove");
        remove->setGeometry(QRect(170, 90, 80, 24));
        line = new QFrame(frame);
        line->setObjectName("line");
        line->setGeometry(QRect(150, 0, 16, 131));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        cityRemoveText = new QLineEdit(frame);
        cityRemoveText->setObjectName("cityRemoveText");
        cityRemoveText->setGeometry(QRect(170, 20, 108, 24));
        line_2 = new QFrame(frame);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(280, 0, 16, 131));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(300, 20, 110, 56));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        edgeRemoveEdgeText = new QLineEdit(layoutWidget);
        edgeRemoveEdgeText->setObjectName("edgeRemoveEdgeText");

        verticalLayout_2->addWidget(edgeRemoveEdgeText);

        cityRemoveEdgeText = new QLineEdit(layoutWidget);
        cityRemoveEdgeText->setObjectName("cityRemoveEdgeText");

        verticalLayout_2->addWidget(cityRemoveEdgeText);

        removeEdgeButton = new QPushButton(frame);
        removeEdgeButton->setObjectName("removeEdgeButton");
        removeEdgeButton->setGeometry(QRect(300, 90, 80, 24));
        line_3 = new QFrame(frame);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(420, 0, 16, 131));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        findShortestPathButton = new QPushButton(frame);
        findShortestPathButton->setObjectName("findShortestPathButton");
        findShortestPathButton->setGeometry(QRect(520, 90, 191, 24));
        layoutWidget_2 = new QWidget(frame);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 20, 110, 56));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        edgeText = new QLineEdit(layoutWidget_2);
        edgeText->setObjectName("edgeText");

        verticalLayout->addWidget(edgeText);

        cityAddText = new QLineEdit(layoutWidget_2);
        cityAddText->setObjectName("cityAddText");

        verticalLayout->addWidget(cityAddText);

        layoutWidget_3 = new QWidget(frame);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(520, 20, 191, 56));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        cityOnePathText = new QLineEdit(layoutWidget_3);
        cityOnePathText->setObjectName("cityOnePathText");

        verticalLayout_3->addWidget(cityOnePathText);

        cityTwoPathText = new QLineEdit(layoutWidget_3);
        cityTwoPathText->setObjectName("cityTwoPathText");

        verticalLayout_3->addWidget(cityTwoPathText);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        cityRemoveText->setText(QCoreApplication::translate("MainWindow", "City", nullptr));
        edgeRemoveEdgeText->setText(QCoreApplication::translate("MainWindow", "Edge", nullptr));
        cityRemoveEdgeText->setText(QCoreApplication::translate("MainWindow", "City", nullptr));
        removeEdgeButton->setText(QCoreApplication::translate("MainWindow", "Remove Edge", nullptr));
        findShortestPathButton->setText(QCoreApplication::translate("MainWindow", "Find Shortest Path", nullptr));
        edgeText->setText(QCoreApplication::translate("MainWindow", "Edge", nullptr));
        cityAddText->setText(QCoreApplication::translate("MainWindow", "City", nullptr));
        cityOnePathText->setText(QCoreApplication::translate("MainWindow", "City 1", nullptr));
        cityTwoPathText->setText(QCoreApplication::translate("MainWindow", "City 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
