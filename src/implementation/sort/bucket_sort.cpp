/*
 * Example of implemantation and usage of bucket sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <vector>

namespace sort {

void bucketSort(std::vector<int> &array) {
  int minValue = array.at(0);
  int maxValue = array.at(0);

  for (int i : array) {
    if (i > maxValue) {
      maxValue = i;
    } else if (i < minValue) {
      minValue = i;
    }
  }

  int bucketLength = maxValue - minValue + 1;
  std::vector<std::vector<int>> bucket;
  bucket.resize(bucketLength);

  for (auto &i : bucket) {
    i = std::vector<int>();
  }

  for (int i : array) {
    bucket.at(i - minValue).push_back(i);
  }

  int k = 0;
  for (const auto &i : bucket) {
    int bucketSize = i.size();
    if (bucketSize > 0) {
      for (int j = 0; j < bucketSize; j++, k++) {
        array.at(k) = i.at(j);
      }
    }
  }
}

} // namespace sort