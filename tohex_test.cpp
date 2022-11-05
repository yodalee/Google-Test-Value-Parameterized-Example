
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