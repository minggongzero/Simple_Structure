#ifndef SORT_ALGORITHM_H_INCLUDED
#define SORT_ALGORITHM_H_INCLUDED

void merge_sort(std::vector<int>& arr);
void quick_sort(std::vector<int>& arr);
void heap_sort(std::vector<int> &arr);
void insertion_sort(std::vector<int>& arr);
void selection_sort(std::vector<int>& arr);
std::vector<int> counting_sort(std::vector<int>& arr, size_t k);
std::vector<int> radix_sort(std::vector<int>& arr, size_t d);

#endif // SORT_ALGORITHM_H_INCLUDED
