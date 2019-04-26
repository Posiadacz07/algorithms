/*
 * Example of implemantation and usage of selection sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <vector>

namespace sort {

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

} // namespace sort