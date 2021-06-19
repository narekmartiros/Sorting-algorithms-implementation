#include <vector>
#include <algorithm>
#include <iostream>

int Partition(std::vector<int>&, int p, int r );
void QuickSort(std::vector<int>&, int p, int r);

int main() {
    std::vector<int> v{33, 33, 234, 634, 275257, 224, 4};
    int r = v.size()-1;
    int p = 0;

    QuickSort(v, p, r);

    for(auto& x: v){
        std::cout << x << " ";
    }
}

int Paritition( std::vector<int>& v, int p, int r){
    int pivot = v[r];
    int i = p-1;
    for(int j = p; j < r; ++j){
        if( v[j] > pivot){
            ++i;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i+1], v[r]);
    return i+1;
}

void QuickSort(std::vector<int>& v, int p, int r){
    if(p<r){
        int q = Paritition(v, p, r);
        QuickSort(v, p, q-1);
        QuickSort(v, q+1, r);
    }
}