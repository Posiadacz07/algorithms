#include "../src/interface/strings.hpp"
#include "gtest/gtest.h"
#include <string>
#include <vector>

namespace strings
{
namespace test
{
namespace
{
std::string source = "caaavvaabaaaaafdcaacsasvaagaaa";
std::string pattern = "aaa";
std::vector<int> result = {1, 9, 10, 11, 27};
} // namespace

class stringTest : public ::testing::Test
{
public:
    virtual void SetUp() override;
    virtual void TearDown() override;
};

void stringTest::SetUp() {}
void stringTest::TearDown() {}

TEST_F(stringTest, emptySource)
{
    std::vector<int> expectedEmptyVector{};

    EXPECT_EQ(expectedEmptyVector, searchPatternBruteForce("", pattern));
    EXPECT_EQ(expectedEmptyVector, searchPatternMorrisPratt("", pattern));
    EXPECT_EQ(expectedEmptyVector, searchPatternKarpRabin("", pattern));
}

TEST_F(stringTest, emptyPattern)
{
    std::vector<int> expectedEmptyVector{};
    EXPECT_EQ(expectedEmptyVector, searchPatternBruteForce(source, ""));
    EXPECT_EQ(expectedEmptyVector, searchPatternMorrisPratt(source, ""));
    EXPECT_EQ(expectedEmptyVector, searchPatternKarpRabin(source, ""));
}

TEST_F(stringTest, searchPatternUsingBruteForceAlgorithm)
{
    EXPECT_EQ(result, searchPatternBruteForce(source, pattern));
}

TEST_F(stringTest, searchPatternUsingMorrisPrattAlgorithm)
{
    EXPECT_EQ(result, searchPatternMorrisPratt(source, pattern));
}

TEST_F(stringTest, searchPatternUsingKarpRabinAlgorithm)
{
    EXPECT_EQ(result, searchPatternKarpRabin(source, pattern));
}

} //namespace test
} // namespace strings