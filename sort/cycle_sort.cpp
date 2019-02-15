/*
 * Example of implemantation and usage of cycle sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <iostream>
#include <vector>

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

int main() {
  std::vector<int> array = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                            5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                            8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

  cycleSort(array);

  for (int i : array) {
    std::cout << i << ' ';
  }
  return 0;
}