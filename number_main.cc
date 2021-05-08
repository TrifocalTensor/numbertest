#include <stdio.h>
#include <iostream>

#include "number.h"

int main(int argc, char *argv[]) {
  std::string cmd = argv[0];
  if (argc != 2) {
    std::cout << "Usage: " << cmd << " 'text to translate'" << std::endl;
    return EXIT_FAILURE;
  }
  std::string text = argv[1];
  Number number;
  std::cout << "Input: " << text << std::endl;
  std::cout << "Output: " << number.Translate(text) << std::endl;
  return EXIT_SUCCESS;
}
