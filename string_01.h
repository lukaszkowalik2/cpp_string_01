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
  size_t str_len = str.length();
  size_t substr_len = substr.length();

  for (size_t i = 0; i <= str_len - substr_len; i++) {
    size_t j;
    for (j = 0; j < substr_len; j++) {
      if (str[i + j] != substr[j]) {
        break;
      }
    }
    if (j == substr_len) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

auto custom_search(const char* str, const char* substr) -> int {
  size_t str_len = strlen(str);
  size_t substr_len = strlen(substr);

  for (size_t i = 0; i <= str_len - substr_len; i++) {
    size_t j;

    for (j = 0; j < substr_len; j++) {
      if (*(str + i + j) != *(substr + j)) {
        break;
      }
    }
    if (j == substr_len) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

}  // namespace string_toys

#endif /* CPP_STRING_H */
