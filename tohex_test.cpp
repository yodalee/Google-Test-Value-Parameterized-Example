
#include "tohex.h"
#include <algorithm>
#include <fstream>
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
  std::string filename;
};

class ToHexParameterSuite : public ::testing::TestWithParam<ToHexTestdata> {};

TEST_P(ToHexParameterSuite, ParameterTest) {
  auto param = GetParam();
  auto s = to_hex(param.in);
  EXPECT_EQ(s, param.ans);
}

std::vector<ToHexTestdata> read_testdata(const std::string &path) {
  std::vector<ToHexTestdata> dataset;
  std::string line;
  std::ifstream fs(path);
  assert(fs.good());
  ToHexTestdata data;
  std::string filename = path;
  filename.erase(std::remove_if(filename.begin(), filename.end(), ::ispunct),
                 filename.end());

  size_t lineno = 0;
  while (std::getline(fs, line)) {
    lineno++;
    if (lineno % 2 == 0) {
      data.ans = line;
      data.filename = filename + "L" + std::to_string(lineno);
      dataset.push_back(data);
    } else {
      data.in = stoi(line);
    }
  }
  return dataset;
}

std::string PrintToString(const ToHexTestdata &data) {
  return std::to_string(data.in) + "->" + data.ans;
}

INSTANTIATE_TEST_SUITE_P(
    TableInstantiation, ToHexParameterSuite,
    ::testing::ValuesIn(read_testdata("testdata.txt")),
    [](::testing::TestParamInfo<ToHexParameterSuite::ParamType> info) {
      return info.param.filename;
    });
