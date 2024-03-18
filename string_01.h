#include <cstring>
#include <iostream>

#ifndef CPP_STRING_H
#define CPP_STRING_H

namespace string_toys {
auto uppercase(char c) -> char {
  if (c >= 'a' && c <= 'z') {
    c = c - 32;
  }

  return c;
}

auto reverse(const std::string& str) -> std::string {
  std::string str_reversed;

  for (const char& c : str) {
    str_reversed = c + str_reversed;
  }

  return str_reversed;
}

auto first_to_upper(const std::string& str) -> std::string {
  bool new_word = true;
  std::string str_first_to_upper = str;

  for (char& c : str_first_to_upper) {
    if (new_word) {
      c = uppercase(c);
      new_word = false;
    }
    if (c == ' ') {
      new_word = true;
    }
  }
  return str_first_to_upper;
}

auto count_vowels(const std::string& str) -> int {
  int count = 0;

  for (const char& c : str) {
    const char up_c = uppercase(c);
    if (up_c == 'A' || up_c == 'E' || up_c == 'I' || up_c == 'O' || up_c == 'U' || up_c == 'Y') {
      count++;
    }
  }
  return count;
}

auto sum_digits(const std::string& str) -> int {
  int sum = 0;
  for (const char& c : str) {
    bool is_digit = isdigit(c);
    if (is_digit) {
      sum = sum + c - '0';
    }
  }
  return sum;
}

auto search_substr(const std::string& str, const std::string& substr) -> int {
  int str_len = str.length();
  int substr_len = substr.length();
  int found_index = -1;

  for (int i = 0; i <= str_len - substr_len; i++) {
    bool match = true;
    for (int j = 0; j < substr_len; j++) {
      if (str[i + j] != substr[j]) {
        match = false;
        break;
      }
    }
    if (match) {
      found_index = i;
      break;
    }
  }
  return found_index;
}

auto custom_search(const char* str, const char* substr) -> int {
  int str_len = strlen(str);
  int substr_len = strlen(substr);
  int found_index = -1;

  for (int i = 0; i <= str_len - substr_len; i++) {
    bool match = true;
    for (int j = 0; j < substr_len; j++) {
      if (*(str + i + j) != *(substr + j)) {
        match = false;
        break;
      }
    }
    if (match) {
      found_index = i;
      break;
    }
  }
  return found_index;
}

}  // namespace string_toys

#endif /* CPP_STRING_H */
