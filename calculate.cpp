#include "calculate.h"
using namespace std;

constexpr double eps = 1e-6; ///< 浮点数的差值

// 初始化栈内和栈外优先级
static map<char, int> inPriority =
    {{'+', 3}, {'-', 3}, {'*', 5}, {'/', 5}, {'%', 5}, {'(', 1}, {')', 8}, {'^', 7}, {'&', 7}};
static map<char, int> outPriority =
    {{'+', 2}, {'-', 2}, {'*', 4}, {'/', 4}, {'%', 4}, {'(', 8}, {')', 1}, {'^', 6}, {'&', 6}};

// 检查是否能取余
static bool canDoMod(const double n1, const double n2)
{
    return (abs(n1 - round(n1)) < eps) && (abs(n2 - round(n2)) < eps);
}

// 计算 n1 op n2
static double calNum(const double n1, const double n2, const char op)
{
    switch (op)
    {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
    {
        if (n2 == 0)
            throw "除数不能为0，请检查后重试...";
        return n1 / n2;
    }

    case '%':
    {
        if (canDoMod(n1, n2))
            return (int)(n1 + 0.5) % (int)(n2 + 0.5);
        throw "只能对整数取余，请检查后重试...";
    }
    case '^':
    {
        double ans = pow(n1, n2);
        if (isnan(ans))
            throw "不能对负数开方，请检查后重试...";
        return ans;
    }
    case '&':
    {
        double ans = pow(n1, 1 / n2);
        if (isnan(ans))
            throw "不能对负数开方，请检查后重试...";
        return ans;
    }
    }
    return 0;
}

// 计算当前栈顶的数字和运算符的结果
static void calculate(Stack<double> &numbers, Stack<char> &operands)
{
    double n1, n2;
    char op = operands.top();
    operands.pop();
    n2 = numbers.top();
    numbers.pop();
    n1 = numbers.top();
    numbers.pop();
    // cout << n1 << op << n2 << "=" << calNum(n1, n2, op) << endl;
    numbers.push(calNum(n1, n2, op));
}

double runExpression(const string &str)
{
    istringstream inStream(str); // 将参数转换成字符流
    Stack<double> numbers;       // 存储数据
    Stack<char> operands;        // 存储操作符
    char op;                     // 当前操作符
    bool minusFlag = true;       // 开头默认将减号识别为负号
    while (inStream >> op)
    {
        if (isdigit(op))
        {
            inStream.putback(op);
            double number;
            inStream >> number;
            numbers.push(number);
            // cout <<"push number " << number << endl;

            // 遇见数字，则将减号视为运算符s
            minusFlag = false;
        }
        else
        {
            // 如果开头遇见负号,则先压入0,视作0-该数
            if (op == '-' && minusFlag)
                numbers.push(0);
            // 如果遇见左括号，重置minusFlag
            if (op == '(')
                minusFlag = true;
            else
                minusFlag = false;

            // 每次将栈内优先级大于当前运算符栈外优先级的计算完成
            while (!operands.empty())
            {
                // cout << op << outPriority[op] << " " << operands.top() <<inPriority[operands.top()] << endl;
                if (outPriority[op] < inPriority[operands.top()])
                    calculate(numbers, operands);
                else if (outPriority[op] == inPriority[operands.top()])
                {
                    operands.pop();
                    // 右括号遇到左括号后退出循环
                    break;
                }
                else
                    break;
            }
            // 如果不是右括号则插入运算符
            if (op != ')')
            {
                // cout << "push operands " << op << endl;
                operands.push(op);
            }
        }
    }
    // 计算剩余的所有运算
    while (!operands.empty())
        calculate(numbers, operands);
    return numbers.top();
}
