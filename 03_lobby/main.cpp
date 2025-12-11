//
// Created by adriar on 10.12.2025.
//
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

int getHighestFromLine(std::string line, int exclude = -1, bool isFirst = true) {
  int highest = 0, highestPos = -1;
  for (const auto c : line) {
    const int i = c - '0';
    if ( i != exclude && i > highest) {
      highest = i;
      highestPos = line.find_first_of(c);
    }
  }

  if (highestPos + 1 == line.size() && isFirst) {
    return getHighestFromLine(line, highest, isFirst);
  }

  return highest;
}

int main() {

  int total = 0;
  // std::stringstream input("987654321111111\n811111111111119\n234234234234278\n818181911112111\n");
  std::ifstream input("input.txt");
  std::string line;
  while (std::getline(input, line)) {
    int highest = 0, highest_pos = 0;
    int second_highest = 0;
    highest = getHighestFromLine(line);
    highest_pos = line.find_first_of(std::to_string(highest));

    second_highest = getHighestFromLine(line.substr(highest_pos + 1), -1, false);

    std::cout << total << " += " << highest << second_highest << std::endl;
    total += highest * 10 + second_highest;



    std::cout << "total: " << total << std::endl;
  }
}