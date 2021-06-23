#include <vector>
#include <iostream>
#include <algorithm>

void Bucket_Sort(std::vector<double> &v);

int main()
{
    std::vector<double> to_sort{0.23, 0.2334, 0.6, 0.1, 0.788, 0.34, 0.99, 0.4};
    Bucket_Sort(to_sort);
    for (auto &x : to_sort)
    {
        std::cout << x << "  ";
    }
}

void Bucket_Sort(std::vector<double> &v)
{
    std::vector<double> bucket[v.size()];

    for (int i = 0; i < v.size(); ++i)
    {
        int index = v.size() * v[i];
        bucket[index].push_back(v[i]);
    }

    for (int i = 0; i < v.size(); ++i)
    {
        std::sort(bucket[i].begin(), bucket[i].end());
    }

    int count = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < bucket[i].size(); ++j)
        {
            v[count++] = bucket[i][j];
        }
    }
}