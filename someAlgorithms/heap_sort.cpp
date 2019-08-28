#include <vector>
#include "sort_algorithm.h"

using namespace std;

void heap_fix(vector<int> &arr, size_t arr_end, size_t f)
{
    for(; f <= (arr_end - 1)/2; )
    {
        if(arr_end < 2*f + 1) break;
        else if(arr_end < 2*f + 2)
        {
            if(arr[f] < arr[2*f + 1])
                std::swap(arr[f], arr[2*f + 1]);
            break;
        }
        auto left_child = arr[2*f + 1], right_child = arr[2*f + 2];
        if(arr[f] < left_child || arr[f] < right_child)
        {
            auto tmp = arr[f];
            if(left_child > right_child)
            {
                arr[f] = left_child;
                f = f*2 + 1;
            }
            else
            {
                arr[f] = right_child;
                f = f*2 + 2;
            }
            arr[f] = tmp;
        }
        else break;
    }
}

void build_heap(vector<int> &arr)
{
    if(arr.size() < 2) return;
    //auto arr_end = arr.size() - 1;
    for(int i = (arr.size()-2)/2; i >= 0; --i)
        heap_fix(arr, arr.size() - 1, i);
}

void heap_sort(vector<int> &arr)
{
    if(arr.size() < 2) return;
    build_heap(arr);
    for(int i=arr.size()-1; i>0; )
    {
        std::swap(arr[0], arr[i--]);
        heap_fix(arr, i, 0);
    }
}
