#include <vector>
#include <algorithm>   
#include <iostream>  
#include <iterator>    

int main() {

std::vector<int> v{554555,14134,466146,131,123,466,131,6464};
int key;
int i;
for(int j = 1; j < v.size(); ++j) {
    key = v[j];
    i = j-1;
    while(i> = 0 && v[i] > key) {
        v[i+1] = v[i];
        --i;
    }
    v[i+1] = key;
}
std::copy(v.begin(),v.end(), std::ostream_iterator<int>(std::cout, " "));
    
}