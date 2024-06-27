#include <QtTest/QtTest>
#include "mainwindow.h"

class TestMainWindow : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();     // Called before the first test function
    void cleanupTestCase();  // Called after the last test function
    void init();             // Called before each test function
    void cleanup();          // Called after each test function

    // Add your test functions here
    void testLoginSuccess();
    void testLoginFailure();
    void testSignupSuccess();
    void testSignupFailure();

private:
    MainWindow *mainWindow;
};

void TestMainWindow::initTestCase()
{
    mainWindow = new MainWindow();
}

void TestMainWindow::cleanupTestCase()
{
    delete mainWindow;
}

void TestMainWindow::init()
{
    // Runs before each test case
}

void TestMainWindow::cleanup()
{
    // Runs after each test case
}

void TestMainWindow::testLoginSuccess()
{
    // Simulate user input
    mainWindow->getUsernameLineEdit()->setText("correctUsername");
    mainWindow->getPasswordLineEdit()->setText("correctPassword");

    // Call the login function using QMetaObject::invokeMethod
    QMetaObject::invokeMethod(mainWindow, "loginClicked", Qt::DirectConnection);

    // Check if the login was successful
    // Add a method or use signals to verify this
    // For example:
    //QCOMPARE(mainWindow->isLoggedIn(), true);
}

void TestMainWindow::testLoginFailure()
{
    // Simulate user input
    mainWindow->getUsernameLineEdit()->setText("wrongUsername");
    mainWindow->getPasswordLineEdit()->setText("wrongPassword");

    // Call the login function using QMetaObject::invokeMethod
    QMetaObject::invokeMethod(mainWindow, "loginClicked", Qt::DirectConnection);

    // Check if the login failed
    // QCOMPARE(mainWindow->isLoggedIn(), false);
}

void TestMainWindow::testSignupSuccess()
{
    // Simulate user input
    mainWindow->getUsernameLineEdit()->setText("newUser");
    mainWindow->getPasswordLineEdit()->setText("newPassword");

    // Call the signup function using QMetaObject::invokeMethod
    QMetaObject::invokeMethod(mainWindow, "signupClicked", Qt::DirectConnection);

    // Check if the signup was successful
    // QCOMPARE(mainWindow->isSignedUp(), true);
}

void TestMainWindow::testSignupFailure()
{
    // Simulate user input with existing username
    mainWindow->getUsernameLineEdit()->setText("existingUser");
    mainWindow->getPasswordLineEdit()->setText("password");

    // Call the signup function using QMetaObject::invokeMethod
    QMetaObject::invokeMethod(mainWindow, "signupClicked", Qt::DirectConnection);

    // Check if the signup failed
    // QCOMPARE(mainWindow->isSignedUp(), false);
}


