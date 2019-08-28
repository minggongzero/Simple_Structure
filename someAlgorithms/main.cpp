#include <iostream>
#include <vector>
#include "sort_algorithm.h"

using namespace std;

int main()
{
    vector<int> a{1, 3, 2, 5, 9, 2, 4, 6, 8, 10, 12, 14};
    //merge_sort(a);
    //quick_sort(a);
    //heap_sort(a);
    //insertion_sort(a);
    //selection_sort(a);
    //counting_sort(a, 14);
    for(auto re : counting_sort(a, 15))
    {
        cout << re << ' ';
    }
    cout << endl;
    cout << "Hello world!" << endl;
    return 0;
}
