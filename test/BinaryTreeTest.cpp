#include "../src/interface/BinaryTree.hpp"
#include "gtest/gtest.h"
#include <vector>

namespace trees {
namespace test {

class BinaryTreeTest : public ::testing::Test {
public:
  virtual void SetUp() override;
  virtual void TearDown() override;
};

void BinaryTreeTest::SetUp() {}

void BinaryTreeTest::TearDown() {}

TEST_F(BinaryTreeTest, SanityCheck) {
  EXPECT_TRUE(true);
}
} // namespace test
} // namespace trees