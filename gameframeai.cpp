// gameframeai.cpp

#include "gameframeai.h"
#include "ui_gameframeai.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include "gameframeai.h"
#include "ui_gameframeai.h"
#include <QPushButton>
#include <QGridLayout>

gameframeai::gameframeai(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameframeai)
{
    ui->setupUi(this);
    setFixedSize(500, 600);

    // Create a grid layout to arrange the cells
    QGridLayout *gridLayout = new QGridLayout(ui->centralwidget);

    // Create buttons for each cell of the Tic Tac Toe board
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            // Create a clickable button for each cell
            QPushButton *cellButton = new QPushButton;
            cellButton->setFixedSize(100, 100); // Adjust the size of each cell
            cellButton->setProperty("row", row);
            cellButton->setProperty("col", col);
            // Set the font size of the button text
            QFont font = cellButton->font();
            font.setPointSize(36); // Set font size to 36 (adjust as needed)
            cellButton->setFont(font);

            // Connect the button to a slot for handling clicks
            connect(cellButton, &QPushButton::clicked, this, &gameframeai::cellClicked);

            // Add the cell button to the grid layout
            gridLayout->addWidget(cellButton, row, col);

            // Store the cell button in the 2D array for easy access later
            cellButtons[row][col] = cellButton;
        }
    }
}

gameframeai::~gameframeai()
{
    delete ui;
}

void gameframeai::cellClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton)
        return;

    int row = clickedButton->property("row").toInt();
    int col = clickedButton->property("col").toInt();

    // Check if the cell is already occupied
    if (!clickedButton->text().isEmpty())
    {
        QMessageBox::warning(this, "Invalid Move", "This cell is already occupied.");
        return;
    }

    // Set the player's symbol (X) on the clicked cell
    clickedButton->setText("X");

    // Check for a player win or draw
    if (checkWin(row, col, "Player"))
    {
        QMessageBox::information(this, "Winner", "Player wins!");
        resetGame();
        return;
    }
    else if (checkDraw())
    {
        QMessageBox::information(this, "Draw", "It's a draw!");
        resetGame();
        return;
    }

    // AI's turn
    aiMakeMove();

    // Check for an AI win or draw
    if (checkWin(lastAIMove.row, lastAIMove.col, "AI"))
    {
        QMessageBox::information(this, "Winner", "AI wins!");
        resetGame();
        return;
    }
    else if (checkDraw())
    {
        QMessageBox::information(this, "Draw", "It's a draw!");
        resetGame();
        return;
    }
}

bool gameframeai::checkWin(int row, int col, const QString& player)
{
    QString symbol = (player == "Player") ? "X" : "O";

    // Check row
    if (cellButtons[row][0]->text() == symbol &&
        cellButtons[row][1]->text() == symbol &&
        cellButtons[row][2]->text() == symbol)
        return true;

    // Check column
    if (cellButtons[0][col]->text() == symbol &&
        cellButtons[1][col]->text() == symbol &&
        cellButtons[2][col]->text() == symbol)
        return true;

    // Check diagonals
    if ((cellButtons[0][0]->text() == symbol &&
         cellButtons[1][1]->text() == symbol &&
         cellButtons[2][2]->text() == symbol) ||
        (cellButtons[0][2]->text() == symbol &&
         cellButtons[1][1]->text() == symbol &&
         cellButtons[2][0]->text() == symbol))
        return true;

    return false;
}

bool gameframeai::checkDraw()
{
    // Check if all cells are filled
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if (cellButtons[row][col]->text().isEmpty())
                return false;
        }
    }
    return true;
}

void gameframeai::resetGame()
{
    // Clear all cell buttons
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            cellButtons[row][col]->setText("");
        }
    }
}

void gameframeai::aiMakeMove()
{
    int bestScore = INT_MIN;
    Move bestMove;

    // Iterate through all empty cells
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if (cellButtons[row][col]->text().isEmpty())
            {
                cellButtons[row][col]->setText("O");
                int score = minimax(0, false);
                cellButtons[row][col]->setText("");

                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove.row = row;
                    bestMove.col = col;
                }
            }
        }
    }

    // Set the AI's move
    cellButtons[bestMove.row][bestMove.col]->setText("O");
    lastAIMove = bestMove;
}

int gameframeai::minimax(int depth, bool isMax)
{
    int score = evaluateBoard();

    // Check if the game is over or if the maximum depth is reached
    if (score == 10 || score == -10 || checkDraw() || depth >= 9)
        return score;

    // If it's the maximizing player's turn (AI)
    if (isMax)
    {
        int bestScore = INT_MIN;
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                if (cellButtons[row][col]->text().isEmpty())
                {
                    cellButtons[row][col]->setText("O");
                    bestScore = qMax(bestScore, minimax(depth + 1, !isMax));
                    cellButtons[row][col]->setText("");
                }
            }
        }
        return bestScore;
    }
    // If it's the minimizing player's turn (Player)
    else
    {
        int bestScore = INT_MAX;
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                if (cellButtons[row][col]->text().isEmpty())
                {
                    cellButtons[row][col]->setText("X");
                    bestScore = qMin(bestScore, minimax(depth + 1, !isMax));
                    cellButtons[row][col]->setText("");
                }
            }
        }
        return bestScore;
    }
}

int gameframeai::evaluateBoard()
{
    // Evaluate the board and return a score
    // +10 for AI win, -10 for Player win, 0 for draw
    // The evaluation is based on the current state of the board
    // You can implement more sophisticated evaluation if needed

    for (int row = 0; row < 3; ++row)
    {
        if (cellButtons[row][0]->text() == cellButtons[row][1]->text() &&
            cellButtons[row][1]->text() == cellButtons[row][2]->text())
        {
            if (cellButtons[row][0]->text() == "O")
                return 10;
            else if (cellButtons[row][0]->text() == "X")
                return -10;
        }
    }

    for (int col = 0; col < 3; ++col)
    {
        if (cellButtons[0][col]->text() == cellButtons[1][col]->text() &&
            cellButtons[1][col]->text() == cellButtons[2][col]->text())
        {
            if (cellButtons[0][col]->text() == "O")
                return 10;
            else if (cellButtons[0][col]->text() == "X")
                return -10;
        }
    }

    if ((cellButtons[0][0]->text() == cellButtons[1][1]->text() &&
         cellButtons[1][1]->text() == cellButtons[2][2]->text()) ||
        (cellButtons[0][2]->text() == cellButtons[1][1]->text() &&
         cellButtons[1][1]->text() == cellButtons[2][0]->text()))
    {
        if (cellButtons[1][1]->text() == "O")
            return 10;
        else if (cellButtons[1][1]->text() == "X")
            return -10;
    }

    return 0; // No winner
}
