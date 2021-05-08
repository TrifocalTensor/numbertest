#include "number.h"

#include <iterator>
#include <sstream>

Number::Number() {}

Number::~Number() {}

std::string Number::Translate(const std::string &str) {
  std::vector<std::string> tokens = Tokenize(str);
  std::vector<std::string> translated_tokens = Convert(tokens);
  std::string result = Untokenize(translated_tokens);
  return result;
  // TODO: Extract tokens as needed instead of loading and processing whole 
  // sequence in memory.
}

std::vector<std::string> Number::Convert(const std::vector<std::string> &seq) {
  std::vector<std::string> result;
	long final_result = 0;
	long intermediate_result = 0;
	for (auto i = seq.begin(); i != seq.end(); ++i) {
		if (*i == "zero") {
			intermediate_result += 0;
		} else if (*i == "one") {
			intermediate_result += 1;
		} else if (*i == "two") {
			intermediate_result += 2;
		} else if (*i == "three") {
			intermediate_result += 3;
		} else if (*i == "four") {
			intermediate_result += 4;
		} else if (*i == "five") {
			intermediate_result += 5;
		} else if (*i == "six") {
			intermediate_result += 6;
		} else if (*i == "seven") {
			intermediate_result += 7;
		} else if (*i == "eight") {
			intermediate_result += 8;
		} else if (*i == "nine") {
			intermediate_result += 9;
		} else if (*i == "ten") {
			intermediate_result += 10;
		} else if (*i == "eleven") {
			intermediate_result += 11;
		} else if (*i == "twelve") {
			intermediate_result += 12;
		} else if (*i == "thirteen") {
			intermediate_result += 13;
		} else if (*i == "fourteen") {
			intermediate_result += 14;
		} else if (*i == "fifteen") {
			intermediate_result += 15;
		} else if (*i == "sixteen") {
			intermediate_result += 16;
		} else if (*i == "seventeen") {
			intermediate_result += 17;
		} else if (*i == "eighteen") {
			intermediate_result += 18;
		} else if (*i == "nineteen") {
			intermediate_result += 19;
		} else if (*i == "twenty") {
			intermediate_result += 20;
		} else if (*i == "thirty") {
			intermediate_result += 30;
		} else if (*i == "forty") {
			intermediate_result += 40;
		} else if (*i == "fifty") {
			intermediate_result += 50;
		} else if (*i == "sixty") {
			intermediate_result += 60;
		} else if (*i == "seventy") {
			intermediate_result += 70;
		} else if (*i == "eighty") {
			intermediate_result += 80;
		} else if (*i == "ninety") {
			intermediate_result += 90;
		} else if (*i == "hundred") {
			intermediate_result *= 100;
		} else if (*i == "thousand") {
			intermediate_result *= 1000;
			final_result += intermediate_result;
			intermediate_result = 0;
		} else if (*i == "million") {
			intermediate_result *= 1000000;
			final_result += intermediate_result;
			intermediate_result = 0;
		} else if (*i == "billion") {
			intermediate_result *= 1000000000;
			final_result += intermediate_result;
			intermediate_result = 0;
		} else if (*i == "trillion") {
			intermediate_result *= 1000000000000L;
			final_result += intermediate_result;
			intermediate_result = 0;
		} else if (*i != "and") {
      final_result += intermediate_result;
      intermediate_result = 0;
      if (final_result != 0) {
        result.push_back(std::to_string(final_result));
        final_result = 0;
      }
      result.push_back(*i);
    }
	}
	final_result += intermediate_result;
	intermediate_result = 0;
  if (final_result != 0) {
    result.push_back(std::to_string(final_result));
    final_result = 0;
  }
	return result;
}

std::vector<std::string> Number::Tokenize(const std::string &str) {
  std::vector<std::string> tokens;
  std::stringstream ss(Trim(str));
  std::string token;
  while (std::getline(ss, token, ' ')) {
    if (token != "") {  // Consecutive spaces yield empty tokens
      tokens.push_back(token);
    }
  }
  return tokens;   
  // TODO: Use std::std::sregex_iterator() to iterate thru tokens 
}

std::string Number::Untokenize(const std::vector<std::string> &seq) {
  std::ostringstream oss;
  std::copy(seq.begin(), seq.end(),
            std::ostream_iterator<std::string>(oss, " "));
  return Trim(oss.str());  // oss.str() has trailing space
}

std::string Number::Trim(const std::string &str) {
  size_t end = str.find_last_not_of(" \t");
  size_t start = str.find_first_not_of(" \t");
  if (std::string::npos != end) {
    std::string right = str.substr(0, end + 1);
    std::string left_right = right.substr(start);
    return left_right;
  } else {
    return "";
  }
  // TODO: Use std::regex_replace() to remove heading and trailing spaces
}
