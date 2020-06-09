#pragma once
#include <iostream>
#define SIZE 10
using namespace std;
template <typename Data>
class DoubleSideQueue
{
private:
    Data* data;
    int m_size;
    int m_count;
public:
    DoubleSideQueue()
    {
        m_size = SIZE;
        data = new Data[m_size];
        m_count = 0;
    }
    DoubleSideQueue(int const capacity_in)
    {
        m_size = capacity_in;
        data = new Data[m_size];
        m_count = 0;
    }
    DoubleSideQueue(DoubleSideQueue const& a_q)
    {
        m_size = a_q.m_size;
        data = new Data[m_size];
        for (m_count = 0; m_count < a_q.m_count; ++m_count)
            data[m_count] = a_q.data[m_count];
    }
    void pushBack(Data const new_Data)
    {
        if (m_count == m_size)
        {
            m_size += 10;
            Data* tmpdata = new Data[m_size];
            for (int i = 0; i < m_count; ++i)
                tmpdata[i] = data[i];
            delete[]data;
            data = tmpdata;
        }
        data[m_count++] = new_Data;
    }
    void pushFront(Data const new_Data)
    {
        if (m_count == m_size)
        {
            m_size += 10;
            Data* tmpdata = new Data[m_size];
            for (int i = 0; i < m_count; ++i)
                tmpdata[i] = data[i];
            delete[]data;
            data = tmpdata;
        }
        for (int i = m_count++; i > 0; --i)
            data[i] = data[i - 1];
        data[0] = new_Data;
    }
    Data const popBack()
    {
        if (isEmpty())
            return 0;
        Data tmpdata = data[--m_count];
        data[m_count] = 0;
        return tmpdata;
    }
    Data const popFront()
    {
        if (isEmpty())
            return 0;
        Data tmpdata = data[0];
        --m_count;
        for (int i = 0; i < m_count; ++i)
            data[i] = data[i + 1];
        data[m_count] = 0;
        return tmpdata;
    }
    Data const topBack() const
    {
        if (isEmpty())
            return 0;
        return data[m_count - 1];
    }
    Data const topFront() const
    {
        if (isEmpty())
            return 0;
        return data[0];
    }
    void clear()
    {
        delete[]data;
        m_size = SIZE;
        m_count = 0;
        data = new Data[m_size];
    }
    bool const isEmpty() const
    {
        if (m_count == 0)
            return true;
        return false;
    }
    int const Size() const
    {
        return m_count;
    }
    void print() const
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty" << endl;
        }
        else {
            for (int i = 0; i < m_count;)
                cout << "\t" << data[i++];
        }
    }
    DoubleSideQueue& operator = (DoubleSideQueue const& any_queue)
    {
        delete[] data;
        m_size = any_queue.m_size;
        data = new Data[m_size];
        for (m_count = 0; m_count < any_queue.m_count; ++m_count)
            data[m_count] = any_queue.data[m_count];
        return *this;
    }
    ~DoubleSideQueue()
    {
        delete[] data;
        m_count = 0;
        m_size = 0;
    }
};
