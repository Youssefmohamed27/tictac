// gameframeai.h

#ifndef GAMEFRAMEAI_H
#define GAMEFRAMEAI_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class gameframeai; }
QT_END_NAMESPACE

class gameframeai : public QMainWindow
{
    Q_OBJECT

public:
    gameframeai(QWidget *parent = nullptr);
    ~gameframeai();

private slots:
    void cellClicked();

private:
    Ui::gameframeai *ui;
    QPushButton *cellButtons[3][3];
    struct Move {
        int row, col;
    } lastAIMove;

    void aiMakeMove();
    bool checkWin(int row, int col, const QString& player);
    bool checkDraw();
    void resetGame();
    int minimax(int depth, bool isMax);
    int evaluateBoard();
};

#endif // GAMEFRAMEAI_H
