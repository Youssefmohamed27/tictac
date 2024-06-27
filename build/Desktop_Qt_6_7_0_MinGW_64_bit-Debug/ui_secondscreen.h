/********************************************************************************
** Form generated from reading UI file 'secondscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDSCREEN_H
#define UI_SECONDSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondscreen
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *secondscreen)
    {
        if (secondscreen->objectName().isEmpty())
            secondscreen->setObjectName("secondscreen");
        secondscreen->resize(800, 600);
        centralwidget = new QWidget(secondscreen);
        centralwidget->setObjectName("centralwidget");
        secondscreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(secondscreen);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        secondscreen->setMenuBar(menubar);
        statusbar = new QStatusBar(secondscreen);
        statusbar->setObjectName("statusbar");
        secondscreen->setStatusBar(statusbar);

        retranslateUi(secondscreen);

        QMetaObject::connectSlotsByName(secondscreen);
    } // setupUi

    void retranslateUi(QMainWindow *secondscreen)
    {
        secondscreen->setWindowTitle(QCoreApplication::translate("secondscreen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondscreen: public Ui_secondscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDSCREEN_H
