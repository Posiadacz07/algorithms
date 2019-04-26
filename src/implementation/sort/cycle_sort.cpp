// Example of implemantation of cycle sort algorithm for integers.
//
// Made by: Posiadacz07

#include <algorithm>
#include <vector>

namespace sort {

void cycleSort(std::vector<int> &array) {
  for (int currentIndex = 0; currentIndex < array.size() - 1; currentIndex++) {
    int item = array.at(currentIndex);
    int currentIndexCopy = currentIndex;

    for (int i = currentIndex + 1; i < array.size(); i++) {
      if (array.at(i) < item) {
        currentIndexCopy++;
      }
    }

    if (currentIndexCopy == currentIndex) {
      continue;
    }

    while (item == array.at(currentIndexCopy)) {
      currentIndexCopy++;
    }

    std::swap(item, array.at(currentIndexCopy));

    while (currentIndexCopy != currentIndex) {
      currentIndexCopy = currentIndex;

      for (int i = currentIndex + 1; i < array.size(); i++) {
        if (array[i] < item) {
          currentIndexCopy++;
        }
      }

      while (item == array[currentIndexCopy]) {
        currentIndexCopy++;
      }

      std::swap(item, array.at(currentIndexCopy));
    }
  }
}

} // namespace sort