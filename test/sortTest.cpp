#include "../src/interface/sort.hpp"
#include "gtest/gtest.h"
#include <vector>

namespace sort {
namespace test {

namespace {
const std::vector<int> unsortedArray = {30, 29, 28, 27, 26, 25, 1,  2,  3,  4,
                                        5,  6,  7,  24, 23, 22, 21, 20, 19, 18,
                                        8,  9,  10, 11, 17, 16, 15, 13, 14, 12};

const std::vector<int> sortedArray = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                                      11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                      21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
} // namespace

class sortTest : public ::testing::Test {
public:
  virtual void SetUp() override;
  virtual void TearDown() override;

  std::vector<int> unsortedTestArray;
};

void sortTest::SetUp() { unsortedTestArray = unsortedArray; }

void sortTest::TearDown() {}

TEST_F(sortTest, bubbleSortTest) {
  sort::bubbleSort(unsortedTestArray);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, bucketSortTest) {
  sort::bucketSort(unsortedTestArray);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, countingSortTest) {
  sort::countingSort(unsortedTestArray, 35);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, cycleSortTest) {
  sort::cycleSort(unsortedTestArray);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, heapSortTest) {
  sort::heapSort(unsortedTestArray);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, intersectionSortTest) {
  sort::insertionSort(unsortedTestArray);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, mergeSortTest) {
  sort::mergeSort(unsortedTestArray, 0, unsortedTestArray.size() - 1);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, oddEvenSortTest) {
  sort::oddEvenSort(unsortedTestArray);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, quickSortTest) {
  sort::quickSort(unsortedTestArray, 0, unsortedTestArray.size() - 1);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, radixSortTest) {
  sort::radixSort(unsortedTestArray);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}

TEST_F(sortTest, selectionSortTest) {
  sort::selectionSort(unsortedTestArray);
  EXPECT_EQ(sortedArray, unsortedTestArray);
}
} // namespace test
} // namespace sort