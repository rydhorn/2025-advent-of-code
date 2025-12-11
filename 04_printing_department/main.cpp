//
// Created by adriar on 11.12.2025.
//


#include <iostream>
#include <vector>

#include "../util.h"



int main()
{
    std::vector<std::vector<char>> grid;

    std::stringstream input = getFileAsStringstream();
    std::string line;
    while (std::getline(input, line))
    {
        grid.emplace_back();
        for (auto c : line)
        {
            grid.back().push_back(c);
        }
    }

    int totalRolls = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '@')
            {
                int adjacentCount = 0;
                if (i - 1 >= 0 && grid[i - 1][j] == '@') adjacentCount++;
                if (i + 1 < grid.size() && grid[i + 1][j] == '@') adjacentCount++;
                if (j - 1 >= 0 && grid[i][j - 1] == '@') adjacentCount++;
                if (j + 1 < grid[i].size() && grid[i][j + 1] == '@') adjacentCount++;
                if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == '@') adjacentCount++;
                if (i - 1 >= 0 && j + 1 < grid[i].size() && grid[i - 1][j + 1] == '@') adjacentCount++;
                if (i + 1 < grid.size() && j - 1 >= 0 && grid[i + 1][j - 1] == '@') adjacentCount++;
                if (i + 1 < grid.size() && j + 1 < grid[i].size() && grid[i + 1][j + 1] == '@') adjacentCount++;

                if (adjacentCount < 4) totalRolls++;
            }
        }
    }

    std::cout << totalRolls << std::endl;
}