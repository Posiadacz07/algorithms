#ifndef SORT_H
#define SORT_H

#include <vector>

// TODO: add documentation
namespace sort {
void bubbleSort(std::vector<int> &array);
void bucketSort(std::vector<int> &array);
void countingSort(std::vector<int> &array, int range);
void cycleSort(std::vector<int> &arr);
void heapSort(std::vector<int> &array);
void insertionSort(std::vector<int> &array);
void mergeSort(std::vector<int> &array, int startIndex, int endIndex);
void oddEvenSort(std::vector<int> &array);
void quickSort(std::vector<int> &array, int leftIndex, int rightIndex);
void radixSort(std::vector<int> &array);
void selectionSort(std::vector<int> &array);
} // namespace sort

#endif // SORT_H