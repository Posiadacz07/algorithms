// Example of implemantation of counting sort algorithm for integers.
//
// Made by: Posiadacz07

#include <vector>

namespace sort {

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

} // namespace sort
