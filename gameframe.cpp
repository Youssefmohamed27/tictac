#include "gameframe.h"
#include "ui_gameframe.h"
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QFont> // Include QFont for setting font properties

gameframe::gameframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gameframe)
    , currentPlayer('X')
    , xWins(0)
    , oWins(0)
{
    setFixedSize(500, 600);
    ui->setupUi(this);

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
            connect(cellButton, &QPushButton::clicked, this, &gameframe::cellClicked);

            // Add the cell button to the grid layout
            gridLayout->addWidget(cellButton, row, col);

            // Store the cell button in the 2D array for easy access later
            cellButtons[row][col] = cellButton;
        }
    }
}

// Rest of the code remains the same...


gameframe::~gameframe()
{
    delete ui;
}

void gameframe::cellClicked()
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

    // Set the current player's symbol (X or O) on the clicked cell
    clickedButton->setText(QString(currentPlayer));

    // Check for a winner or a draw
    if (checkWin(row, col))
    {
        QMessageBox::information(this, "Winner", QString("Player %1 wins!").arg(currentPlayer));
        if (currentPlayer == 'X')
            xWins++;
        else
            oWins++;
        resetGame();
    }
    else if (checkDraw())
    {
        QMessageBox::information(this, "Draw", "It's a draw!");
        resetGame();
    }
    else
    {
        // Switch to the next player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

bool gameframe::checkWin(int row, int col)
{
    QString symbol = QString(currentPlayer);

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

bool gameframe::checkDraw()
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

void gameframe::resetGame()
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

