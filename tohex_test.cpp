
#include "tohex.h"
#include <gtest/gtest.h>

TEST(ToHexTestSuite, zero) {
  auto s = to_hex(0);
  EXPECT_EQ(s, "0x00000000");
}