#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

using namespace std;
CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
    initKeybored(); // 初始化按键对应的操作
    this->grabKeyboard();
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}

void CalculatorWindow::initKeybored()
{
    // 数字0~9按键部分
    connect(ui->pushButton_0, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("0");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_1, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("1");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_2, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("2");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_3, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("3");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_4, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("4");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_5, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("5");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_6, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("6");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_7, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("7");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_8, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("8");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_9, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("9");
                ui->textEdit->setFocus();
            });

    // 符号按键部分
    connect(ui->pushButton_dot, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText(".");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_plus, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("+");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_minus, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("-");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_multi, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("*");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_division, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("/");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_mod, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("%");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_pow, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("^");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_sqrt, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("&");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_leftbra, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText("(");
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_rightbra, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->insertPlainText(")");
                ui->textEdit->setFocus();
            });

    // 功能按键部分
    // 清空
    connect(ui->pushButton_clear, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->clear();
                ui->textEdit->setFocus();
            });
    connect(ui->pushButton_clear, &QAbstractButton::clicked,
            ui->textBrowser, &QTextBrowser::clear);
    // 退格
    connect(ui->pushButton_back, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->textCursor().deletePreviousChar();
                ui->textEdit->setFocus();
            });
    // 向左移动光标
    connect(ui->pushButton_left, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->moveCursor(QTextCursor::Left);
                ui->textEdit->setFocus();
            });
    // 向右移动光标
    connect(ui->pushButton_right, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                ui->textEdit->moveCursor(QTextCursor::Right);
                ui->textEdit->setFocus();
            });
    // 计算结果
    connect(ui->pushButton_equal, &QAbstractButton::clicked,
            ui->textEdit, [&]
            {
                string expression = ui->textEdit->toPlainText().toStdString();
                if (isLegal(expression) && !expression.empty())
                {
                    double result;
                    try
                    {
                        result = runExpression(expression);
                        ui->textBrowser->setTextColor("#000000");
                        ui->textBrowser->setText(to_string(result).c_str());
                    }
                    catch (const char *error)
                    {
                        ui->textBrowser->setTextColor("#ff0000");
                        ui->textBrowser->setText(QString(error));
                    }
                }
                else
                {
                    ui->textBrowser->setTextColor("#ff0000");
                    if (expression.empty())
                        ui->textBrowser->setText("表达式为空，请输入后重试...");
                    else
                        ui->textBrowser->setText("表达式错误！请检查后重试...");
                }
                ui->textBrowser->setFocus();
            });
}

void CalculatorWindow::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case Qt::Key_Enter:
        ui->pushButton_equal->click();
        break;
    case Qt::Key_Return:
        ui->pushButton_equal->click();
        break;
    case Qt::Key_0:
        ui->pushButton_0->click();
        break;
    case Qt::Key_1:
        ui->pushButton_1->click();
        break;
    case Qt::Key_2:
        ui->pushButton_2->click();
        break;
    case Qt::Key_3:
        ui->pushButton_3->click();
        break;
    case Qt::Key_4:
        ui->pushButton_4->click();
        break;
    case Qt::Key_5:
        ui->pushButton_5->click();
        break;
    case Qt::Key_6:
        ui->pushButton_6->click();
        break;
    case Qt::Key_7:
        ui->pushButton_7->click();
        break;
    case Qt::Key_8:
        ui->pushButton_8->click();
        break;
    case Qt::Key_9:
        ui->pushButton_9->click();
        break;
    case Qt::Key_Period:
        ui->pushButton_dot->click();
        break;
    case Qt::Key_Plus:
        ui->pushButton_plus->click();
        break;
    case Qt::Key_Minus:
        ui->pushButton_minus->click();
        break;
    case Qt::Key_Asterisk:
        ui->pushButton_multi->click();
        break;
    case Qt::Key_Slash:
        ui->pushButton_division->click();
        break;
    case Qt::Key_ParenLeft:
        ui->pushButton_leftbra->click();
        break;
    case Qt::Key_ParenRight:
        ui->pushButton_rightbra->click();
        break;
    case Qt::Key_AsciiCircum:
        ui->pushButton_pow->click();
        break;
    case Qt::Key_Ampersand:
        ui->pushButton_sqrt->click();
        break;
    case Qt::Key_Percent:
        ui->pushButton_mod->click();
        break;
    case Qt::Key_Left:
        ui->pushButton_left->click();
        break;
    case Qt::Key_Right:
        ui->pushButton_right->click();
        break;
    case Qt::Key_Backspace:
        ui->pushButton_back->click();
        break;
    case Qt::Key_Escape:
        ui->pushButton_clear->click();
        break;
    case Qt::Key_Space:
        ui->textEdit->insertPlainText(" ");
        break;
    default:
        break;
    }
}
