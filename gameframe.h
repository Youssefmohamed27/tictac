#ifndef GAMEFRAME_H
#define GAMEFRAME_H

#include <QMainWindow>
#include <QPushButton>

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

private:
    Ui::gameframe *ui;
    QPushButton *cellButtons[3][3];
    char currentPlayer;
    int xWins;
    int oWins;

    bool checkWin(int row, int col);
    bool checkDraw();
    void resetGame();
};

#endif // GAMEFRAME_H
