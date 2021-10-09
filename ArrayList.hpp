#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

template<typename T>
class ArrayList
{
private:
    int curSize;
    int maxSize;
    T* data;
public:
    ArrayList()
        :curSize(0), maxSize(10), data(new T[maxSize]) { }

    void push_back(T val)
    {
        if (curSize == maxSize)
            resize(curSize * 2);
        data[curSize++] = val;
    }

    void pop_back()
    {
        data[--curSize].~T();
    }

    T& back()
    {
        return data[curSize - 1];
    }

    T const& back() const
    {
        return data[curSize - 1];
    }

    void resize(int newSize)
    {
        T* tmp = new T[newSize];
        for (int i = 0; i < curSize; i++)
        {
            tmp[i] = data[i];
            data[i].~T();
        }
        maxSize = newSize;
        delete[] data;
        data = tmp;
    }

    T& operator[](int idx)
    {
        return data[idx];
    }

    T const& operator[](int idx) const
    {
        return data[idx];
    }

    int size() const
    {
        return curSize;
    }
    
    bool empty() const
    {
        return curSize == 0;
    }
    
    void clear()
    {
        for (int i = 0; i < curSize; i++)
            data[i].~T();
        curSize = 0;
    }
};

#endif // ARRAYLIST_HPP
