#ifndef SECONDSCREEN_H
#define SECONDSCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class secondscreen; }
QT_END_NAMESPACE

class QPushButton;
class QVBoxLayout;

class secondscreen : public QMainWindow
{
    Q_OBJECT

public:
    secondscreen(QWidget *parent = nullptr);
    ~secondscreen();

private slots:
    void onButton1Clicked();
    void onButton2Clicked();
    void onButton3Clicked();

private:
    Ui::secondscreen *ui;
    void setButtonStyle(QPushButton *button);
};

#endif // SECONDSCREEN_H
