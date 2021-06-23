#ifndef HEAPIFIER_H
#define HEAPIFIER_H

#include <iostream>
#include <algorithm>


template<typename T>
class Heapifier {
public:
    
    Heapifier(T& container);
    Heapifier(T container, int size);
    Heapifier(T &container, int size, int range_begin, int range_end);
    Heapifier(T &container, int range_begin, int range_end);
    ~Heapifier()=default;
    int Parent (int i);
    int Left(int i);
    int Right(int i);
    void Max_Heapify(int i);
    void Build_Max_Heapify();
    int get_lenght();
    void swap(int index1, int index2);
    int get_size();
    int size_decrement();

private:
    int m_heap_size;
    int m_heap_lenght;
    T& m_container;
};

template <typename T>
Heapifier<T>::Heapifier(T &container) 
    : m_container{container}
    , m_heap_size{container.size()-1}
    , m_heap_lenght{container.size()-1} {}

template <typename T>
Heapifier<T>::Heapifier(T container, int size) 
    : m_container{container}
    , m_heap_size{size}
    , m_heap_lenght{size} {}

template <typename T>
Heapifier<T>::Heapifier(T &container, int size, int range_begin, int range_end) 
    : m_container{container}
    , m_heap_size{range_end-range_begin+1}
    , m_heap_lenght{size} {}

template <typename T>
Heapifier<T>::Heapifier(T &container, int range_begin, int range_end) 
    : m_container{container}
    , m_heap_size{range_end-range_begin+1}
    , m_heap_lenght{container.size()} {}

template <typename T>
int Heapifier<T>::Parent(int i)
{
    return i / 2;
}

template <typename T>
int Heapifier<T>::Left(int i)
{
    return 2 * i;
}

template <typename T>
int Heapifier<T>::Right(int i)
{
    return 2 * i + 1;
}

template <typename T>
void Heapifier<T>::Max_Heapify(int i)
{
    int l;
    int r;
    if (i == 0)
    {
        l = Left(i) + 1;
        r = Right(i) + 1;
    }
    else
    {
        l = Left(i);
        r = Right(i);
    }

    int largest;
    if (l <= m_heap_size && m_container[l] > m_container[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r <= m_heap_size && m_container[r] > m_container[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        std::swap(m_container[i], m_container[largest]);
        Max_Heapify(largest);
    }
}

template <typename T>
void Heapifier<T>::Build_Max_Heapify()
{
    m_heap_size = m_heap_lenght;
    for (int i = (m_heap_lenght / 2); i >= 0; --i)
    {
        Max_Heapify(i);
    }
}

template <typename T>
int Heapifier<T>::get_lenght()
{
    return m_heap_lenght;
}

template <typename T>
int Heapifier<T>::size_decrement()
{
    m_heap_size--;
    return m_heap_size;
}

template <typename T>
void Heapifier<T>::swap(int index1, int index2)
{
    std::swap(m_container[index1], m_container[index2]);
}

template <typename T>
int Heapifier<T>::get_size()
{
    return m_heap_size;
}

#endif // HEAPIFIER