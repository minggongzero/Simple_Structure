#include <vector>
#include "sort_algorithm.h"

using namespace std;

void quick_sort(vector<int>& arr, size_t arr_beg, size_t arr_end)
{
    if(arr_beg >= arr_end) return;
    auto flag = arr[arr_beg];
    size_t i = arr_beg, j = arr_beg + 1;
    for( ; j <= arr_end; ++j)
    {
        if(arr[j] < flag)
        {
            auto tmp = arr[j];
            arr[j] = arr[++i];
            arr[i] = tmp;
        }
    }
    arr[arr_beg] = arr[i];
    arr[i] = flag;
    quick_sort(arr, arr_beg, i>0 ? i - 1 : 0);
    quick_sort(arr, i + 1, arr_end);
}

void quick_sort(vector<int>& arr)
{
    quick_sort(arr, 0, arr.size() - 1);
}
