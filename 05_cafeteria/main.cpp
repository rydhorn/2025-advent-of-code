#include <fstream>
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <set>

#include "../util.h"


int main() {
    const std::stringstream input = getFileAsStringstream();

    std::stringstream ranges(input.str().substr(0, input.str().find("\n\n")));
    std::stringstream available(input.str().substr(ranges.str().size() + 2));

    std::vector<std::ranges::iota_view<ulong, ulong>> allFreshIds;
    std::string line;

    //process ranges
    while (std::getline(ranges, line))
    {
        unsigned long start = std::stol(line.substr(0, line.find('-')));
        std::string l = line.substr(line.find('-') + 1);
        unsigned long end = std::stol(line.substr(line.find('-') + 1));
        auto range = std::ranges::views::iota(start, end);
        allFreshIds.emplace_back(range);
    }
    int freshIngredients = 0;
    while (std::getline(available, line))
    {
        for (const auto& range : allFreshIds)
        {
            if (std::ranges::binary_search(range, std::stol(line)))
            {
                freshIngredients++;
                break;
            }
        }
    }

    std::cout << "Total fresh ingredients: " << freshIngredients << std::endl;

    return 0;
}