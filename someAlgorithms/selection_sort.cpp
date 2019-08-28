#include <vector>
#include "sort_algorithm.h"

using namespace std;

void selection_sort(vector<int>& arr)
{
    if(arr.size() < 2) return;
    for(size_t i=0; i<arr.size()-1; ++i)
    {
        auto arr_min = arr[i];
        for(size_t j=i+1; j<arr.size(); ++j)
            if(arr[j] < arr_min) std::swap(arr[j], arr_min);
        arr[i] = arr_min;
    }
}
