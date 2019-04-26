// Example of implemantation of heap sort algorithm for integers.
//
// Made by: Posiadacz07

#include <algorithm>
#include <vector>

namespace sort {

//! NOTE: helper function for heap sort
void heapify(std::vector<int> &array, int length, int index) {
  int largest = index;
  int leftIndex = 2 * index + 1;
  int rightIndex = 2 * index + 2;

  if (leftIndex < length && array.at(leftIndex) > array.at(largest)) {
    largest = leftIndex;
  }
  if (rightIndex < length && array.at(rightIndex) > array.at(largest)) {
    largest = rightIndex;
  }

  if (largest != index) {
    std::swap(array.at(index), array.at(largest));
    heapify(array, length, largest);
  }
}

void heapSort(std::vector<int> &array) {
  for (int i = array.size() / 2 - 1; i >= 0; i--) {
    heapify(array, array.size(), i);
  }

  for (int i = array.size() - 1; i >= 0; i--) {
    std::swap(array.at(0), array.at(i));
    heapify(array, i, 0);
  }
}

} // namespace sort
