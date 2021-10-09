#ifndef STACK_HPP
#define STACK_HPP

#include "ArrayList.hpp"

template<typename T, typename Container = ArrayList<T>>
class Stack
{
private:
    Container data;
public:
    Stack(){}
    ~Stack(){}

    void pop()
    {
        data.pop_back();
    }

    void push(T val)
    {
        data.push_back(val);
    }

    T& top()
    {
        return data.back();
    }

    T const& top() const
    {
        return data.back();
    }

    void clear()
    {
        data.clear();
    }

    int size() const
    {
        return data.size();
    }

    bool empty() const
    {
        return data.empty();
    }
};

#endif // STACK_HPP
