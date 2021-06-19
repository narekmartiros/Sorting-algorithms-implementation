#include <iostream>
#include <vector>

void MergeSort( std::vector<int>& v, int p, int r);
void Merge(std::vector<int>& v, int p, int q, int r);

int main() {
    std::vector<int> v {234,65,2,8756,45242,24,45};
    int r = v.size();
    MergeSort(v, 0, r-1);
    for(auto& x: v){
        std::cout<<x<<" ";
    }  
}

void MergeSort(std::vector<int>& v, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        MergeSort(v, p, q);
        MergeSort(v, q+1, r);
        Merge(v, p, q, r);
    }
}

void Merge(std::vector<int>& v, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; ++i){
        L[i] = v[p+i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = v[q+j+1];
    }

    int j = 0;
    int i = 0;
    int k = p;

    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}
    
