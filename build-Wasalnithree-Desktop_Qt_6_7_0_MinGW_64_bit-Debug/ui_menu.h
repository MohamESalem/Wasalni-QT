/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QPushButton *pushButton;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(1105, 583);
        Menu->setMinimumSize(QSize(1105, 583));
        Menu->setMaximumSize(QSize(1105, 583));
        Menu->setStyleSheet(QString::fromUtf8("#Menu {\n"
"image: url(:/images/images/Main.png);\n"
"border-image: url(:/images/images/Main.png);\n"
"}\n"
"\n"
"QGridLayout {\n"
"border-image: url(:/images/images/Main.png);\n"
"image: url(:/images/images/Main.png);\n"
"background-image: url(:/images/images/Main.png);\n"
"background: url(:/images/images/Main.png);\n"
"\n"
"\n"
"}\n"
"\n"
"QWidget {\n"
"border-image: url(:/images/images/Main.png);\n"
"image: url(:/images/images/Main.png);\n"
"background-image: url(:/images/images/Main.png);\n"
"background: url(:/images/images/Main.png);\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton {\n"
"  color: #FFFFFF;\n"
"  background: #b7d8db none;\n"
"}\n"
"\n"
"QPushButton {\n"
"  color: #FFFFFF;\n"
"  background: #b7d8db none;\n"
"}"));
        gridLayoutWidget = new QWidget(Menu);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 1107, 585));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(1105, 583));
        widget->setMaximumSize(QSize(1105, 583));
        widget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  color: #FFFFFF;\n"
"  background: #b7d8db none;\n"
"}"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 370, 431, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Semilight")});
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background:none;\n"
"background-image: none;\n"
"image: none;\n"
"border-image: none;\n"
"  color: #FFFFFF;\n"
"  background: #b7d8db;\n"
"  border: 1px solid #5c7080;\n"
"  border-radius: 20px;\n"
"  padding: 8px 16px;\n"
"  font-size: 24px;\n"
"  font-weight: bold;\n"
"  text-transform: uppercase;\n"
"  text-align: center;\n"
"  cursor: pointer;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background: #dbb7c7;\n"
"}\n"
"\n"
"\n"
"QPushButton:focus {\n"
"  outline: none;\n"
"  box-shadow: #dbb7c7; \n"
"}\n"
""));

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Menu", nullptr));
        pushButton->setText(QCoreApplication::translate("Menu", "GET MOVING, START NOW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
