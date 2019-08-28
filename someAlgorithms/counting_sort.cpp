#include <iostream>
#include <vector>

using namespace std;

/**
* arr_a' s range: [0, k)
**/
vector<int> counting_sort(vector<int>& arr_a, size_t k)
{
    //vector<int> arr_c{0};
    if(arr_a.size() < 2) return arr_a;
    int arr_c[k] = {0};
    vector<int> arr_b(arr_a.size(), 0);
    int i;
    for(i=0; i<arr_a.size(); ++i)
        arr_c[arr_a[i]] += 1;
    for(i=1; i<k; ++i)
        arr_c[i] += arr_c[i-1];
    for(i=arr_a.size()-1; i>=0; --i)
    {
        arr_b[arr_c[arr_a[i]]-1] = arr_a[i];
        arr_c[arr_a[i]] -= 1;
    }
    return arr_b;
}
