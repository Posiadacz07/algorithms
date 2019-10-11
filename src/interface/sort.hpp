#ifndef SORT_HPP
#define SORT_HPP

#include <vector>

namespace sort {

//! \bref Function which sort integers using bubble sort.
//!
//! \param[in|out] array Collection of elements to sort.
void bubbleSort(std::vector<int> &array);

//! \bref Function which sort integers using bucket sort.
//!
//! \param[in|out] array Collection of elements to sort.
void bucketSort(std::vector<int> &array);

//! \bref Function which sort integers using counting sort.
//!
//! \param[in|out] array Collection of elements to sort.
//! \param[in]     range Range of specific kays using in counting sort
//! algorithm.
void countingSort(std::vector<int> &array, int range);

//! \bref Function which sort integers using cycle sort.
//!
//! \param[in|out] array Collection of elements to sort.
void cycleSort(std::vector<int> &array);

//! \bref Function which sort integers using heap sort.
//!
//! \param[in|out] array Collection of elements to sort.
void heapSort(std::vector<int> &array);

//! \bref Function which sort integers using intersection sort.
//!
//! \param[in|out] array Collection of elements to sort.
void insertionSort(std::vector<int> &array);

//! \bref Function which sort integers using merge sort.
//!
//! \param[in|out] array        Collection of elements to sort.
//! \param[in]     startIndex   Index of first element to sort.
//! \param[in]     endIndex     Index of last element to sort.
void mergeSort(std::vector<int> &array, int startIndex, int endIndex);

//! \bref Function which sort integers using odd-even sort.
//!
//! \param[in|out] array Collection of elements to sort.
void oddEvenSort(std::vector<int> &array);

//! \bref Function which sort integers using quick sort.
//!
//! \param[in|out] array        Collection of elements to sort.
//! \param[in]     leftIndex    Index of first element to sort.
//! \param[in]     rightIndex   Index of last element to sort.
void quickSort(std::vector<int> &array, int leftIndex, int rightIndex);

//! \bref Function which sort integers using radix sort.
//!
//! \param[in|out] array Collection of elements to sort.
void radixSort(std::vector<int> &array);

//! \bref Function which sort integers using selection sort.
//!
//! \param[in|out] array Collection of elements to sort.
void selectionSort(std::vector<int> &array);
} // namespace sort

#endif // SORT_HPP