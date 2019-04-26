/*
 * Example of implemantation and usage of bubble sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <vector>

namespace sort {

void bubbleSort(std::vector<int> &array) {
  for (int i = 0; i < array.size() - 1; i++) {
    for (int j = 0; j < array.size() - i - 1; j++) {
      if (array.at(j) > array.at(j + 1)) {
        std::swap(array.at(j), array.at(j + 1));
      }
    }
  }
}

} // namespace sort