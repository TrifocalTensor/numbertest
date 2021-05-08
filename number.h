#ifndef NUMBER_H_
#define NUMBER_H_

#include <string>
#include <vector>

class Number {  // TODO: Find a better class name
 public:
  Number();
  ~Number();

  std::string Translate(const std::string &str);

 private:
  std::vector<std::string> Convert(const std::vector<std::string> &seq);
  std::vector<std::string> Tokenize(const std::string &str);
  std::string Untokenize(const std::vector<std::string> &seq);
  std::string Trim(const std::string &str);

  // TODO: This class does not have fields. Set all methods to static and 
  // remove ctor & dtor.
};

#endif  // NUMBER_H_
