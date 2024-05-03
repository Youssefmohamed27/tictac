#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondscreen.h" // Include secondscreen.h
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set fixed size for the main window
    setFixedSize(500, 600);

    // Create layout for registration form
    QVBoxLayout *registrationLayout = new QVBoxLayout;
    registrationLayout->setAlignment(Qt::AlignCenter);
    registrationLayout->setSpacing(20);
    registrationLayout->setContentsMargins(30, 30, 30, 30);

    // Add labels and line edits for username and password
    QLabel *usernameLabel = new QLabel("Username:");
    QLineEdit *usernameLineEdit = new QLineEdit;
    usernameLineEdit->setStyleSheet("QLineEdit { margin: 0; padding: 10px; font-size: 14px; }");
    QLabel *passwordLabel = new QLabel("Password:");
    QLineEdit *passwordLineEdit = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setStyleSheet("QLineEdit { margin: 0; padding: 10px; font-size: 14px; }");

    registrationLayout->addWidget(usernameLabel);
    registrationLayout->addWidget(usernameLineEdit);
    registrationLayout->addWidget(passwordLabel);
    registrationLayout->addWidget(passwordLineEdit);

    // Create layout for login and signup buttons
    QHBoxLayout *buttonsLayout = new QHBoxLayout;

    // Add login and signup buttons with styling
    QPushButton *loginButton = new QPushButton("Login");
    loginButton->setStyleSheet("QPushButton {"
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
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::loginClicked);
    buttonsLayout->addWidget(loginButton);

    QPushButton *signupButton = new QPushButton("Signup");
    signupButton->setStyleSheet("QPushButton {"
                                "background-color: #008CBA;"
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
                                "background-color: #45a7d5;"
                                "}"
                                "QPushButton:pressed {"
                                "background-color: #005f75;"
                                "}");
    connect(signupButton, &QPushButton::clicked, this, &MainWindow::signupClicked);
    buttonsLayout->addWidget(signupButton);

    // Add the buttons layout to the main registration layout
    registrationLayout->addLayout(buttonsLayout);

    // Create widget to hold registration form
    QWidget *registrationWidget = new QWidget;
    registrationWidget->setLayout(registrationLayout);

    // Add registration form widget to main window
    setCentralWidget(registrationWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginClicked()
{
    // Open the "secondscreen" window
    secondscreen *secondScreen = new secondscreen();
    secondScreen->show();
}

void MainWindow::signupClicked()
{
    // Open the "secondscreen" window
    secondscreen *secondScreen = new secondscreen();
    secondScreen->show();
}
