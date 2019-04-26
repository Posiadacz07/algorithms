/*
 * Example of implemantation and usage of odd-even sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <vector>

namespace sort {

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

} // namespace sort
