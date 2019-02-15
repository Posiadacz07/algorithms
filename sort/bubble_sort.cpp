/*
 * Example of implemantation and usage of bubble sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &array) {
  for (int i = 0; i < array.size() - 1; i++) {
    for (int j = 0; j < array.size() - i - 1; j++) {
      if (array.at(j) > array.at(j + 1)) {
        std::swap(array.at(j), array.at(j + 1));
      }
    }
  }
}

int main() {
  std::vector<int> array = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                            5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                            8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

  bubbleSort(array);

  for (int i : array) {
    std::cout << i << ' ';
  }
  return 0;
}