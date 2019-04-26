/*
 * Example of implemantation and usage of cycle sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <vector>

namespace sort {

void cycleSort(std::vector<int> &arr) {
  for (int currentIndex = 0; currentIndex < arr.size() - 1; currentIndex++) {
    int item = arr.at(currentIndex);
    int currentIndexCopy = currentIndex;

    for (int i = currentIndex + 1; i < arr.size(); i++) {
      if (arr.at(i) < item) {
        currentIndexCopy++;
      }
    }

    if (currentIndexCopy == currentIndex) {
      continue;
    }

    while (item == arr.at(currentIndexCopy)) {
      currentIndexCopy++;
    }

    std::swap(item, arr.at(currentIndexCopy));

    while (currentIndexCopy != currentIndex) {
      currentIndexCopy = currentIndex;

      for (int i = currentIndex + 1; i < arr.size(); i++) {
        if (arr[i] < item) {
          currentIndexCopy++;
        }
      }

      while (item == arr[currentIndexCopy]) {
        currentIndexCopy++;
      }

      std::swap(item, arr.at(currentIndexCopy));
    }
  }
}

} // namespace sort