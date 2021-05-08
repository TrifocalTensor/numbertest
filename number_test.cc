#include <stdexcept>
#include <string>

#include "number.h"

#define ASSERT_EQUAL(a, b) { \
  if ((a) != (b)) \
    throw std::runtime_error( \
      "assert_equal failed: line " + std::to_string(__LINE__) + ": " + \
      "expected '" + (a) + "', obtained '" + (b) + "'"); \
}
// TODO: Move this macro to a dedicated testing header

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

  ASSERT_EQUAL("1", number.Translate("one"));
  ASSERT_EQUAL("10", number.Translate("ten"));
  ASSERT_EQUAL("11", number.Translate("eleven"));
  ASSERT_EQUAL("100", number.Translate("one hundred"));
  ASSERT_EQUAL("101", number.Translate("one hundred and one"));
  ASSERT_EQUAL("110", number.Translate("one hundred and ten"));
  ASSERT_EQUAL("111", number.Translate("one hundred and eleven"));
  ASSERT_EQUAL("1000", number.Translate("one thousand"));

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

  ASSERT_EQUAL("11 aa bb cc 22", number.Translate("eleven aa bb cc twenty two"));
  ASSERT_EQUAL("x a 11 m p 22 n q 33 c y", number.Translate("x a eleven m p twenty two n q thirty three c y"));
  ASSERT_EQUAL("xxx yyy zzz", number.Translate("xxx yyy zzz"));
  ASSERT_EQUAL("xyz", number.Translate("xyz"));
  //ASSERT_EQUAL("a and b", number.Translate("a and b"));  // TODO: Fix case

  // TODO: Test all numbers from 1 to 20
  // TODO: Test 20, 30, 40, ..., 100
  // TODO: Test 1000, 10000, 100000, ..., 1000000000

  return EXIT_SUCCESS;
}
