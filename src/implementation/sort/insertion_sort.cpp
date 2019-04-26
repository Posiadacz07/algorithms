// Example of implemantation of insertion sort algorithm for integers.
//
// Made by: Posiadacz07

#include <vector>

namespace sort {

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

} // namespace sort