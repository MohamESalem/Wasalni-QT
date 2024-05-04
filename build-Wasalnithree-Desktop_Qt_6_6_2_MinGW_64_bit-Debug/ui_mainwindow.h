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
#include <QtWidgets/QLabel>
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
    QLineEdit *city1AddEdgeText;
    QLineEdit *cityAddEdgeText;
    QLineEdit *edgeAddEdgeText;
    QPushButton *addEdgeButton;
    QFrame *line_3;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *cityNameAddText;
    QLineEdit *xAddText;
    QLineEdit *yAddText;
    QFrame *line_4;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *removeEdge1;
    QLineEdit *removeEdge2;
    QPushButton *removeEdgeButton;
    QLabel *add_text_error;
    QLabel *remove_text_error;
    QLabel *add_edge_text_error;
    QLabel *remove_edge_text_error;
    QPushButton *saveButton;
    QPushButton *LoadCitiesButton;
    QPushButton *LoadEdgesButton;
    QPushButton *clearButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(811, 820);
        MainWindow->setMinimumSize(QSize(804, 820));
        MainWindow->setMaximumSize(QSize(900, 842));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(804, 820));
        centralwidget->setMaximumSize(QSize(804, 820));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, 640, 811, 171));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        addButton = new QPushButton(frame);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 110, 111, 24));
        remove = new QPushButton(frame);
        remove->setObjectName("remove");
        remove->setGeometry(QRect(169, 110, 111, 24));
        line = new QFrame(frame);
        line->setObjectName("line");
        line->setGeometry(QRect(150, 0, 16, 171));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        cityNameRemoveText = new QLineEdit(frame);
        cityNameRemoveText->setObjectName("cityNameRemoveText");
        cityNameRemoveText->setGeometry(QRect(170, 20, 108, 24));
        line_2 = new QFrame(frame);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(280, 0, 16, 171));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(300, 10, 110, 100));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        city1AddEdgeText = new QLineEdit(layoutWidget);
        city1AddEdgeText->setObjectName("city1AddEdgeText");

        verticalLayout_2->addWidget(city1AddEdgeText);

        cityAddEdgeText = new QLineEdit(layoutWidget);
        cityAddEdgeText->setObjectName("cityAddEdgeText");

        verticalLayout_2->addWidget(cityAddEdgeText);

        edgeAddEdgeText = new QLineEdit(layoutWidget);
        edgeAddEdgeText->setObjectName("edgeAddEdgeText");

        verticalLayout_2->addWidget(edgeAddEdgeText);

        addEdgeButton = new QPushButton(frame);
        addEdgeButton->setObjectName("addEdgeButton");
        addEdgeButton->setGeometry(QRect(299, 110, 111, 24));
        line_3 = new QFrame(frame);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(420, 0, 16, 171));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        layoutWidget_2 = new QWidget(frame);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 10, 111, 100));
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

        line_4 = new QFrame(frame);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(570, 0, 16, 171));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        layoutWidget_4 = new QWidget(frame);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(450, 20, 110, 65));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        removeEdge1 = new QLineEdit(layoutWidget_4);
        removeEdge1->setObjectName("removeEdge1");

        verticalLayout_4->addWidget(removeEdge1);

        removeEdge2 = new QLineEdit(layoutWidget_4);
        removeEdge2->setObjectName("removeEdge2");

        verticalLayout_4->addWidget(removeEdge2);

        removeEdgeButton = new QPushButton(frame);
        removeEdgeButton->setObjectName("removeEdgeButton");
        removeEdgeButton->setGeometry(QRect(450, 110, 111, 24));
        add_text_error = new QLabel(frame);
        add_text_error->setObjectName("add_text_error");
        add_text_error->setGeometry(QRect(10, 140, 141, 31));
        add_text_error->setStyleSheet(QString::fromUtf8("color: red;\n"
""));
        remove_text_error = new QLabel(frame);
        remove_text_error->setObjectName("remove_text_error");
        remove_text_error->setGeometry(QRect(160, 140, 141, 31));
        remove_text_error->setStyleSheet(QString::fromUtf8("color: red;\n"
""));
        add_edge_text_error = new QLabel(frame);
        add_edge_text_error->setObjectName("add_edge_text_error");
        add_edge_text_error->setGeometry(QRect(290, 140, 141, 31));
        add_edge_text_error->setStyleSheet(QString::fromUtf8("color: red;\n"
""));
        remove_edge_text_error = new QLabel(frame);
        remove_edge_text_error->setObjectName("remove_edge_text_error");
        remove_edge_text_error->setGeometry(QRect(430, 140, 141, 31));
        remove_edge_text_error->setStyleSheet(QString::fromUtf8("color: red;\n"
""));
        saveButton = new QPushButton(frame);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(580, 120, 83, 29));
        LoadCitiesButton = new QPushButton(frame);
        LoadCitiesButton->setObjectName("LoadCitiesButton");
        LoadCitiesButton->setGeometry(QRect(660, 120, 83, 29));
        LoadEdgesButton = new QPushButton(frame);
        LoadEdgesButton->setObjectName("LoadEdgesButton");
        LoadEdgesButton->setGeometry(QRect(742, 120, 61, 29));
        clearButton = new QPushButton(frame);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(650, 60, 80, 20));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, -10, 791, 631));
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
        cityNameRemoveText->setText(QString());
        cityNameRemoveText->setPlaceholderText(QCoreApplication::translate("MainWindow", "City Name", nullptr));
        city1AddEdgeText->setText(QString());
        city1AddEdgeText->setPlaceholderText(QCoreApplication::translate("MainWindow", "City 1", nullptr));
        cityAddEdgeText->setText(QString());
        cityAddEdgeText->setPlaceholderText(QCoreApplication::translate("MainWindow", "City 2", nullptr));
        edgeAddEdgeText->setText(QString());
        edgeAddEdgeText->setPlaceholderText(QCoreApplication::translate("MainWindow", "Weight", nullptr));
        addEdgeButton->setText(QCoreApplication::translate("MainWindow", "Add Edge", nullptr));
        cityNameAddText->setText(QString());
        cityNameAddText->setPlaceholderText(QCoreApplication::translate("MainWindow", "City Name", nullptr));
        xAddText->setText(QString());
        xAddText->setPlaceholderText(QCoreApplication::translate("MainWindow", "X-coordinate", nullptr));
        yAddText->setText(QString());
        yAddText->setPlaceholderText(QCoreApplication::translate("MainWindow", "Y-coordinate", nullptr));
        removeEdge1->setText(QString());
        removeEdge1->setPlaceholderText(QCoreApplication::translate("MainWindow", "City 1", nullptr));
        removeEdge2->setText(QString());
        removeEdge2->setPlaceholderText(QCoreApplication::translate("MainWindow", "City 2", nullptr));
        removeEdgeButton->setText(QCoreApplication::translate("MainWindow", "Remove Edge", nullptr));
        add_text_error->setText(QCoreApplication::translate("MainWindow", "*Change Name or Position", nullptr));
        remove_text_error->setText(QCoreApplication::translate("MainWindow", "*This City doesn't exist", nullptr));
        add_edge_text_error->setText(QCoreApplication::translate("MainWindow", "*Wrong Cities or Weight", nullptr));
        remove_edge_text_error->setText(QCoreApplication::translate("MainWindow", "*Wrong Cities", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        LoadCitiesButton->setText(QCoreApplication::translate("MainWindow", "Load Cities", nullptr));
        LoadEdgesButton->setText(QCoreApplication::translate("MainWindow", "Load Edges", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
