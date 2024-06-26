// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loginClicked();
    void signupClicked();

private:
    Ui::MainWindow *ui;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
};

#endif // MAINWINDOW_H

