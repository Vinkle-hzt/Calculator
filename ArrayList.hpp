#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

/**
 * @brief 基于数组的可增长线性表
 * 
 * @tparam T 线性表类型
 */
template <typename T>
class ArrayList
{
private:
    int curSize; ///< 线性表当前大小
    int maxSize; ///< 线性表最大大小
    T *data;     ///< 线性表数据指针

public:
    ArrayList()
        : curSize(0), maxSize(10), data(new T[maxSize]) {}

    /**
     * @brief 在尾部插入元素
     * 
     * @param val 元素值
     */
    void push_back(T val)
    {
        if (curSize == maxSize)
            resize(curSize * 2);
        data[curSize++] = val;
    }

    /**
     * @brief 删除尾部元素
     * 
     */
    void pop_back()
    {
        if (curSize == 0)
            throw "不能对空列表删除元素";
        data[--curSize].~T();
    }

    /**
     * @brief 获取尾部元素
     * 
     * @return T& 尾部元素
     */
    T &back()
    {
        return data[curSize - 1];
    }

    /**
     * @brief 获取尾部元素
     * 
     * @return T& 尾部元素
     */
    T const &back() const
    {
        return data[curSize - 1];
    }

    /**
     * @brief 更改存储元素数组的大小
     * 
     * @param newSize 新的大小
     */
    void resize(int newSize)
    {
        if (newSize <= maxSize)
            throw "新的大小需要大于原先的大小";

        T *tmp = new T[newSize];
        for (int i = 0; i < curSize; i++)
        {
            tmp[i] = data[i];
            data[i].~T();
        }
        maxSize = newSize;
        delete[] data;
        data = tmp;
    }

    /**
     * @brief 通过[]访问线性表元素
     * 
     * @param idx 下标值
     * @return T& 元素
     */
    T &operator[](int idx)
    {
        if (idx < 0 || idx >= curSize)
            throw "无效的下标";
        return data[idx];
    }

    /**
     * @brief 通过[]访问线性表元素
     * 
     * @param idx 下标值
     * @return T& 元素
     */
    T const &operator[](int idx) const
    {
        if (idx < 0 || idx >= curSize)
            throw "无效的下标";
        return data[idx];
    }

    /**
     * @brief 获取线性表大小
     * 
     * @return int 线性表大小
     */
    int size() const
    {
        return curSize;
    }

    /**
     * @brief 检查线性表是否为空
     * 
     * @return true 空
     * @return false 非空
     */
    bool empty() const
    {
        return curSize == 0;
    }

    /**
     * @brief 清空线性表
     * 
     */
    void clear()
    {
        for (int i = 0; i < curSize; i++)
            data[i].~T();
        curSize = 0;
    }
};

#endif // ARRAYLIST_HPP
