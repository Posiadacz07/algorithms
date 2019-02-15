/*
 * Example of implemantation and usage of quick sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <iostream>
#include <vector>

void quickSort(std::vector<int> &array, int leftIndex, int rightIndex) {
  int i = leftIndex;
  int j = rightIndex;
  int middleIndex = array.at((leftIndex + rightIndex) / 2);

  while (i <= j) {
    while (array.at(i) < middleIndex)
      i++;
    while (array.at(j) > middleIndex)
      j--;

    if (i <= j) {
      std::swap(array.at(i), array.at(j));
      i++;
      j--;
    }
  }

  if (leftIndex < j)
    quickSort(array, leftIndex, j);

  if (rightIndex > i)
    quickSort(array, i, rightIndex);
}

int main() {
  std::vector<int> array = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                            5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                            8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

  quickSort(array, 0, array.size() - 1);

  for (int i : array) {
    std::cout << i << ' ';
  }
  return 0;
}
