#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "calculate.h"
#include "legal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorWindow; }
QT_END_NAMESPACE

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

protected:
    void keyPressEvent(QKeyEvent *ev);

private:
    Ui::CalculatorWindow *ui;
    void initKeybored();
};
#endif // CALCULATORWINDOW_H
