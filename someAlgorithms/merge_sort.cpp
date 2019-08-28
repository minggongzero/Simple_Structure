#include <vector>
#include "sort_algorithm.h"

using namespace std;

void mg_merge(vector<int>& arr, size_t arr_beg, size_t arr_mid, size_t arr_end)
{
    if(arr_beg >= arr_end) return;
    auto beg = arr.begin();
    vector<int> first(beg + arr_beg, beg + arr_mid + 1), second(beg + arr_mid + 1, beg + arr_end + 1);
    if(!first.empty() || !second.empty())
    {
        auto itf = first.begin(), its = second.begin();
        int i = 0;
        for( ;itf != first.end() && its != second.end(); )
            arr[arr_beg + i++] = *itf < *its ? *itf++ : *its++;
        if(itf != first.end())
            for(; itf != first.end(); ) arr[arr_beg + i++] = *itf++;
        else for(; its != second.end(); ) arr[arr_beg + i++] = *its++;
    }
}

void merge_sort(vector<int>& arr, size_t arr_beg, size_t arr_end)
{
    if(arr_beg != arr_end)
    {
        size_t arr_mid = (arr_beg + arr_end) / 2;
        merge_sort(arr, arr_beg, arr_mid);
        merge_sort(arr, arr_mid + 1, arr_end);
        mg_merge(arr, arr_beg, arr_mid, arr_end);
    }
}

void merge_sort(vector<int>& arr)
{
    merge_sort(arr, 0, arr.size() - 1);
}
