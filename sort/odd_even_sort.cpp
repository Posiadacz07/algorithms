/*
 * Example of implemantation and usage of odd-even sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <iostream>
#include <vector>

void oddEvenSort(std::vector<int> &array) {
  bool isSorted = false;

  while (!isSorted) {
    isSorted = true;

    for (int i = 1; i <= array.size() - 2; i += 2) {
      if (array.at(i) > array.at(i + 1)) {
        std::swap(array.at(i), array.at(i + 1));
        isSorted = false;
      }
    }

    for (int i = 0; i <= array.size() - 2; i += 2) {
      if (array.at(i) > array.at(i + 1)) {
        std::swap(array.at(i), array.at(i + 1));
        isSorted = false;
      }
    }
  }
}

int main() {
  std::vector<int> array = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                            5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                            8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

  oddEvenSort(array);

  for (int i : array) {
    std::cout << i << ' ';
  }
  return 0;
}