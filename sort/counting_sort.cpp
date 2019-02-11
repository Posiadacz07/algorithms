/*
 * Example of implemantation and usage of counting sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <iostream>
#include <vector>

void countingSort(std::vector<int> &array, int range) {
  std::vector<int> count(range);
  std::vector<int> output(array.size());

  for (int i : array) {
    ++count.at(i);
  }

  for (int i = 1; i < count.size(); i++) {
    count.at(i) += count.at(i - 1);
  }

  for (auto i = array.rbegin(); i != array.rend(); ++i) {
    output.at(count.at(*i) - 1) = *i;
    --count.at(*i);
  }

  for (int i = 0; i < array.size(); i++) {
    array.at(i) = output.at(i);
  }
}

int main() {
  std::vector<int> array = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                            5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                            8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

  countingSort(array, 35);

  for (int i : array) {
    std::cout << i << ' ';
  }

  return 0;
}