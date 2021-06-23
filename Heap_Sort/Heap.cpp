#include "Heapifier.h"
#include <iostream>
#include <vector>
#include <string>

template <typename T>
void Heap_Sort(Heapifier<T> &heapified);

int main()
{
    std::vector<int> v{5, 4, 45, 2, 66, 87};
    int arr[5] = {5, 555, 7, 2, 78};

    Heapifier<std::vector<int>> heapster(v);
    Heapifier<int *> array(arr, 5);
    
    Heap_Sort(heapster);
    Heap_Sort(array);
   
    for (auto &x : v)
    {
        std::cout << x << " ";
    }

    for (auto &x : arr)
    {
        std::cout << x << " ";
    }
    
}

template <typename T>
void Heap_Sort(Heapifier<T> &heapified)
{
    heapified.Build_Max_Heapify();
    for (int i = heapified.get_lenght(); i > 0; --i)
    {
        heapified.swap(0, i);
        heapified.size_decrement();
        heapified.Max_Heapify(0);
    }
}