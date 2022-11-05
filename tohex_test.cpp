
#include "tohex.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(ToHexTest, zero) {
  auto s = to_hex(0);
  EXPECT_EQ(s, "0x00000000");
}

class ToHexTestSuite : public ::testing::Test {
protected:
  void SetUp() override { std::cout << "Before Test" << std::endl; }
  void TearDown() override { std::cout << "After Test" << std::endl; }
};

TEST_F(ToHexTestSuite, a5) {
  auto s = to_hex(0xa5a55a5a);
  EXPECT_EQ(s, "0xA5A55A5A");
  std::cout << s << std::endl;
}

struct ToHexTestdata {
  uint32_t in;
  std::string ans;
};

class ToHexParameterSuite : public ::testing::TestWithParam<ToHexTestdata> {};

TEST_P(ToHexParameterSuite, ParameterTest) {
  auto param = GetParam();
  auto s = to_hex(param.in);
  EXPECT_EQ(s, param.ans);
}

INSTANTIATE_TEST_SUITE_P(TableInstantiation, ToHexParameterSuite,
                         ::testing::Values(ToHexTestdata{1, "0x00000001"},
                                           ToHexTestdata{0xffffffff,
                                                         "0xFFFFFFFF"}));
