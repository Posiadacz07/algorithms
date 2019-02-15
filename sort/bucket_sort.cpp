/*
 * Example of implemantation and usage of bucket sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <iostream>
#include <vector>

void bucketSort(std::vector<int> &array) {
  int minValue = array.at(0);
  int maxValue = array.at(0);

  for (int i : array) {
    if (i > maxValue) {
      maxValue = i;
    }
    else if (i < minValue) {
      minValue = i;
    }
  }

  int bucketLength = maxValue - minValue + 1;
  std::vector<std::vector<int>> bucket;
  bucket.resize(bucketLength);

  for (auto& i : bucket) {
    i = std::vector<int>();
  }

  for (int i : array) {
    bucket.at(i - minValue).push_back(i);
  }

  int k = 0;
  for (const auto& i : bucket) {
    int bucketSize = i.size();
    if (bucketSize > 0) {
      for (int j = 0; j < bucketSize; j++, k++) {
        array.at(k) = i.at(j);
      }
    }
  }
}

int main() {
  std::vector<int> array = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                            5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                            8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

  bucketSort(array);

  for (int i : array) {
    std::cout << i << ' ';
  }
  return 0;
}