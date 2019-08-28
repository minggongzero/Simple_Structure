#include <vector>
#include "sort_algorithm.h"

using namespace std;

void insertion_sort(vector<int>& arr)
{
    if(arr.size() < 2) return;
    int i, j;
    for(i=1; i<arr.size(); ++i)
    {
        auto tmp = arr[i];
        for(j = i - 1; j>=0; --j)
            if(arr[j] > tmp) arr[j + 1] = arr[j];
            else
            {
                arr[j + 1] = tmp;
                break;
            }
    }
}
