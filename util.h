//
// Created by adriar on 11.12.2025.
//

#ifndef INC_2025_ADVENT_OF_CODE_UTIL_H
#define INC_2025_ADVENT_OF_CODE_UTIL_H
#include <fstream>
#include <sstream>
#include <string>

inline std::stringstream getFileAsStringstream(const std::string& filename = "input.txt") {
  std::ifstream input(filename);
  std::stringstream ss;
  ss << input.rdbuf();
  return ss;
}

#endif //INC_2025_ADVENT_OF_CODE_UTIL_H