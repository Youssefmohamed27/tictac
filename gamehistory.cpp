#include "gamehistory.h"
#include "secondscreen.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QFont>

gamehistory::gamehistory(QWidget *parent)
    : QWidget(parent), mainLayout(new QVBoxLayout(this)), backButton(new QPushButton("Back", this))
{
    setFixedSize(500, 600); // Set fixed size for the window

    // Set background color to black
    setStyleSheet("background-color: black; color: white;");

    // Configure back button
    QFont buttonFont("Arial", 16);
    backButton->setFont(buttonFont);
    backButton->setStyleSheet("QPushButton {"
                              "background-color: #4CAF50;"
                              "border: none;"
                              "color: white;"
                              "padding: 10px 24px;"
                              "text-align: center;"
                              "text-decoration: none;"
                              "display: inline-block;"
                              "font-size: 16px;"
                              "margin: 4px 2px;"
                              "cursor: pointer;"
                              "border-radius: 8px;"
                              "}"
                              "QPushButton:hover {"
                              "background-color: #45a049;"
                              "}"
                              "QPushButton:pressed {"
                              "background-color: #367533;"
                              "}");

    connect(backButton, &QPushButton::clicked, this, &gamehistory::goBackToSecondScreen);

    // Add spacer to adjust button position
    mainLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)); // Adjust the height of the spacer item

    // Add back button to layout
    mainLayout->addWidget(backButton, 0, Qt::AlignCenter);

    // Set layout for the widget
    setLayout(mainLayout);
}

void gamehistory::goBackToSecondScreen()
{
    // Create and show the secondscreen window
    secondscreen *secondScreen = new secondscreen;
    secondScreen->show();

    // Close the current gamehistory window
    this->close();
}
