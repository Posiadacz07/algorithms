/*
 * Example of implemantation and usage of quick sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <vector>

namespace sort {

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

} // namespace sort
