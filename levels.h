#ifndef LEVELS_H
#define LEVELS_H

#include <QMainWindow>

namespace Ui {
class levels;
}

class levels : public QMainWindow
{
    Q_OBJECT

public:
    explicit levels(QWidget *parent = nullptr);
    ~levels();

private:
    Ui::levels *ui;
};

#endif // LEVELS_H
