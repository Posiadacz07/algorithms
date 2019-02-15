/*
 * Example of implemantation and usage of selection sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &array) {
  int minIndex;
  for (int i = 0; i < array.size() - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < array.size(); j++) {
      if (array.at(minIndex) > array.at(j)) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      std::swap(array.at(i), array.at(minIndex));
    }
  }
}

int main() {
  std::vector<int> array = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                            5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                            8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

  selectionSort(array);

  for (int i : array) {
    std::cout << i << ' ';
  }
  return 0;
}