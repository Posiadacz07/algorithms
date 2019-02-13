/*
 * Example of implemantation and usage of heap sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <iostream>
#include <vector>

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

int main() {
  std::vector<int> array = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                            5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                            8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

  heapSort(array);

  for (int i : array) {
    std::cout << i << ' ';
  }
  return 0;
}