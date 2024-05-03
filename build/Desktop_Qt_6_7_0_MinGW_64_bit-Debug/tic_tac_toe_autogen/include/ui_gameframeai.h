/********************************************************************************
** Form generated from reading UI file 'gameframeai.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFRAMEAI_H
#define UI_GAMEFRAMEAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameframeai
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gameframeai)
    {
        if (gameframeai->objectName().isEmpty())
            gameframeai->setObjectName("gameframeai");
        gameframeai->resize(800, 600);
        centralwidget = new QWidget(gameframeai);
        centralwidget->setObjectName("centralwidget");
        gameframeai->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gameframeai);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        gameframeai->setMenuBar(menubar);
        statusbar = new QStatusBar(gameframeai);
        statusbar->setObjectName("statusbar");
        gameframeai->setStatusBar(statusbar);

        retranslateUi(gameframeai);

        QMetaObject::connectSlotsByName(gameframeai);
    } // setupUi

    void retranslateUi(QMainWindow *gameframeai)
    {
        gameframeai->setWindowTitle(QCoreApplication::translate("gameframeai", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameframeai: public Ui_gameframeai {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFRAMEAI_H
