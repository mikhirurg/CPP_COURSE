//
// Created by @mikhirurg on 01.07.2020.
//

#include <iostream>

unsigned strlen(const char *str) {
  unsigned count = 0;
  const char *c = str;
  while (*c != '\0') {
    count++;
    c++;
  }
  return count;
}

int strstr(const char *text, const char *pattern) {
  unsigned text_len = strlen(text);
  unsigned pattern_len = strlen(pattern);

  if (pattern_len > text_len) {
    return -1;
  }

  if (pattern_len == 0) {
    return 0;
  }

  for (int i = 0; i <= text_len - pattern_len; i++) {
    for (int j = 0; j < pattern_len; j++) {
      if (text[i + j] != pattern[j]) {
        break;
      }
      if (j == pattern_len - 1) {
        return i;
      }
    }
  }

  return -1;
}

int main() {
  const char *a = "a";
  const char *b = "ef";
  std::cout << strstr(a, b);
}