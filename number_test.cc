#include <stdexcept>
#include <string>

#include "number.h"

#define ASSERT_EQUAL(a, b) { \
  if ((a) != (b)) \
    throw std::runtime_error( \
      "assert_equal failed: line " + std::to_string(__LINE__) + ": " + \
      "expected '" + (a) + "', obtained '" + (b) + "'"); \
}

int main(int argc, char *argv[]) {
  Number number;

  ASSERT_EQUAL("101", number.Translate("one hundred and one"));
  ASSERT_EQUAL("I have 100 apples", number.Translate("I have one hundred apples"));

  ASSERT_EQUAL("a 1 b", number.Translate("a one b"));
  ASSERT_EQUAL("a 12 b", number.Translate("a twelve b"));
  ASSERT_EQUAL("a 123 b", number.Translate("a one hundred and twenty three b"));
  ASSERT_EQUAL("a 1234 b", number.Translate("a one thousand two hundred and thirty four b"));
  ASSERT_EQUAL("a 12345 b", number.Translate("a twelve thousand three hundred and forty five b"));
  ASSERT_EQUAL("a 123456 b", number.Translate("a one hundred and twenty three thousand four hundred and fifty six b"));
  ASSERT_EQUAL("a 1234567 b", number.Translate("a one million two hundred and thirty four thousand five hundred and sixty seven b"));
  ASSERT_EQUAL("a 12345678 b", number.Translate("a twelve million three hundred and forty five thousand six hundred and seventy eight b"));
  ASSERT_EQUAL("a 123456789 b", number.Translate("a one hundred twenty three million four hundred and fifty six thousand seven hundred and eighty nine b"));

  ASSERT_EQUAL("", number.Translate(""));
  ASSERT_EQUAL("", number.Translate(" "));
  ASSERT_EQUAL("1", number.Translate(" one"));
  ASSERT_EQUAL("1", number.Translate("one "));
  ASSERT_EQUAL("1", number.Translate(" one "));

  ASSERT_EQUAL("11 aa", number.Translate("  eleven  aa"));
  ASSERT_EQUAL("11 aa", number.Translate("  eleven  aa "));
  ASSERT_EQUAL("aa 11", number.Translate("aa eleven  "));
  ASSERT_EQUAL("aa 11", number.Translate("  aa  eleven  "));

  ASSERT_EQUAL("a 123 b 456 c", number.Translate("a one hundred and twenty three b four hundred and fifty six c"));

  return EXIT_SUCCESS;
}
