#include "string_01.h"

#include <iostream>

using namespace std;

auto main() -> int {
  string str;
  cout << "Enter a string" << endl;
  getline(cin, str);
  string reverse_str = string_toys::reverse(str);

  cout << "Reversed string: " << reverse_str << endl;

  string str_first_to_up = string_toys::first_to_upper(str);

  cout << "First to upper: " << str_first_to_up << endl;

  int count_vowels = string_toys::count_vowels(str);
  cout << "Vowels count: " << count_vowels << endl;

  int digit_sum = string_toys::sum_digits(str);
  cout << "Digit sum: " << digit_sum << endl;

  string substr = "dsa 1";
  int index = string_toys::search_substr(str, substr);
  cout << "Substring index: " << index << endl;

  int index2 = string_toys::custom_search(str.c_str(), substr.c_str());
  cout << "Index 2:" << index2 << endl;

  return 0;
}
