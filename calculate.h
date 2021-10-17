#ifndef CALCULATE_H
#define CALCULATE_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cctype>
#include <cmath>
#include <algorithm>
#include "Stack.hpp"

constexpr int DOUBLE_MOD = 1;
constexpr int DIVISION_BY_ZERO = 2;
constexpr int IMAGINARY_NUM = 3;

/**
 * @brief 计算表达式
 * 
 * @param str 表达式
 * @return double 表达式结果
 * @exception const char* 错误信息
 */
double runExpression(const std::string &str);

#endif // CALCULATE_H
