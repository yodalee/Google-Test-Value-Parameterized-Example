
#include "tohex.h"
#include <string>

std::string to_hex(int32_t val) {
  std::string ret("0x");

  for (size_t i = sizeof(val) * 2; i > 0;) {
    --i;
    int c = 0xf & (val >> (4 * i));
    ret.push_back(c >= 10 ? (c + 'A' - 10) : (c + '0'));
  }
  return ret;
}
