/*
 * Example of implemantation and usage of marge sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <vector>

namespace sort {

void merge(std::vector<int> &array, int startIndex, int middleIndex,
           int endIndex) {
  std::vector<int> tmp(array);
  int i = startIndex, j = middleIndex + 1, k = startIndex;
  while (i <= middleIndex && j <= endIndex) {
    array.at(k++) = tmp.at(i) < tmp.at(j) ? tmp.at(i++) : tmp.at(j++);
  }
  while (i <= middleIndex) {
    array.at(k++) = tmp.at(i++);
  }
  while (j <= endIndex) {
    array.at(k++) = tmp.at(j++);
  }
}

void mergeSort(std::vector<int> &array, int startIndex, int endIndex) {
  if (startIndex < endIndex) {
    int middleIndex = (startIndex + endIndex) / 2;

    mergeSort(array, startIndex, middleIndex);
    mergeSort(array, middleIndex + 1, endIndex);

    merge(array, startIndex, middleIndex, endIndex);
  }
}

} // namespace sort
