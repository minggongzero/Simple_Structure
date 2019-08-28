#include <vector>
#include "sort_algorithm.h"

using namespace std;

vector<int> radix_sort(vector<int>& arr, size_t d)
{
    vector<int> result = counting_sort(arr, 10);
    for(size_t i=0; i<d; ++i)
    {
        result = counting_sort(result, 10);
    }
    return result;
}
