#ifndef GAMEFRAME_H
#define GAMEFRAME_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include "secondscreen.h" // Include your secondscreen header file here

QT_BEGIN_NAMESPACE
namespace Ui { class gameframe; }
QT_END_NAMESPACE

class gameframe : public QMainWindow
{
    Q_OBJECT


public:
    gameframe(QWidget *parent = nullptr);
    ~gameframe();

private slots:
    void cellClicked();
    void goBack();
    void resetGame(); // Added to reset the game board


private:
    Ui::gameframe *ui;
    QGridLayout *gridLayout;
    QPushButton *cellButtons[3][3];
    QPushButton *backButton;
    QPushButton *restartButton; // Added restart button
    char currentPlayer;
    int xWins;
    int oWins;
    int draws;

    // Instance of secondscreen
    secondscreen *secondScreen;

    void updateScores();
    bool checkWin(int row, int col);
    bool checkDraw();
};

#endif // GAMEFRAME_H

