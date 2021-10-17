#ifndef STACK_HPP
#define STACK_HPP

#include "ArrayList.hpp"

/**
 * @brief 栈类
 * 
 * @tparam T 栈元素的数据类型
 * @tparam Container 存储栈元素的容器，默认ArrayList<T>
 */
template <typename T, typename Container = ArrayList<T>>
class Stack
{
private:
    Container data; ///< 存储元素的容器

public:
    Stack() {}
    ~Stack() {}

    /**
     * @brief 弹出栈元素
     * 
     */
    void pop()
    {
        data.pop_back();
    }

    /**
     * @brief 把元素添加到栈中
     * 
     * @param val 元素值
     */
    void push(T val)
    {
        data.push_back(val);
    }

    /**
     * @brief 获取栈顶元素
     * 
     * @return T& 栈顶元素
     */
    T &top()
    {
        return data.back();
    }

    /**
     * @brief 获取栈顶元素
     * 
     * @return T& 栈顶元素
     */
    T const &top() const
    {
        return data.back();
    }

    /**
     * @brief 清空栈
     * 
     */
    void clear()
    {
        data.clear();
    }

    /**
     * @brief 获取栈当前大小
     * 
     * @return int 栈的大小
     */
    int size() const
    {
        return data.size();
    }

    /**
     * @brief 检查栈是否为空
     * 
     * @return true 空
     * @return false 非空
     */
    bool empty() const
    {
        return data.empty();
    }
};

#endif // STACK_HPP
