/*
 * Example of implemantation and usage of insertion sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &array) {
  for (int i = 0; i < array.size() - 1; i++) {
    int tmp = array.at(i + 1);
    int j = i;
    while (j >= 0 && array.at(j) > tmp) {
      array.at(j + 1) = array.at(j);
      j--;
    }
    array.at(j + 1) = tmp;
  }
}

int main() {
  std::vector<int> array = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                            5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                            8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

  insertionSort(array);

  for (int i : array) {
    std::cout << i << ' ';
  }
  return 0;
}