/********************************************************************************
** Form generated from reading UI file 'gameframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFRAME_H
#define UI_GAMEFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameframe
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gameframe)
    {
        if (gameframe->objectName().isEmpty())
            gameframe->setObjectName("gameframe");
        gameframe->resize(800, 600);
        centralwidget = new QWidget(gameframe);
        centralwidget->setObjectName("centralwidget");
        gameframe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gameframe);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        gameframe->setMenuBar(menubar);
        statusbar = new QStatusBar(gameframe);
        statusbar->setObjectName("statusbar");
        gameframe->setStatusBar(statusbar);

        retranslateUi(gameframe);

        QMetaObject::connectSlotsByName(gameframe);
    } // setupUi

    void retranslateUi(QMainWindow *gameframe)
    {
        gameframe->setWindowTitle(QCoreApplication::translate("gameframe", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameframe: public Ui_gameframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFRAME_H
