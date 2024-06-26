#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QWidget>

class QPushButton;
class QVBoxLayout;

class gamehistory : public QWidget
{
    Q_OBJECT

public:
    explicit gamehistory(QWidget *parent = nullptr);

private slots:
    void goBackToSecondScreen();

private:
    QVBoxLayout *mainLayout;
    QPushButton *backButton;
};

#endif // GAMEHISTORY_H
