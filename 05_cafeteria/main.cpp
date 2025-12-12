#include <fstream>
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <set>

#include "../util.h"


int main() {
    const std::stringstream input = getFileAsStringstream();

    // parse input into ranges and available ingredients
    std::stringstream ranges(input.str().substr(0, input.str().find("\n\n")));
    std::stringstream available(input.str().substr(ranges.str().size() + 2));

    //process ranges
    std::vector<std::ranges::iota_view<ulong, ulong>> allFreshIds;
    std::vector<std::pair<ulong, ulong>> allFreshStartsEnds;
    std::string line;
    while (std::getline(ranges, line))
    {
        unsigned long start = std::stol(line.substr(0, line.find('-')));
        unsigned long end = std::stol(line.substr(line.find('-') + 1));
        auto range = std::ranges::views::iota(start, end);
        allFreshIds.emplace_back(range);
        allFreshStartsEnds.emplace_back(start, end);
    }

    // process available ingredients
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

    // part 2
    // merge overlapping ranges
    std::vector<std::pair<ulong, ulong>> mergedFreshIds;
    std::ranges::sort(allFreshStartsEnds, std::less<>(), &std::pair<ulong, ulong>::first);
    for (const auto& range : allFreshStartsEnds)
    {
        if (mergedFreshIds.empty() || mergedFreshIds.back().second < range.first)
        {
            mergedFreshIds.push_back(range);
        }
        else
        {
            mergedFreshIds.back().second = std::max(mergedFreshIds.back().second, range.second);
        }
    }

    // calculate total fresh ingredients in merged ranges
    unsigned long long totalFreshIngredients = 0;
    for (const auto& range : mergedFreshIds)
    {
        totalFreshIngredients += range.second - range.first + 1;
    }
    std::cout << "Total unique fresh ingredient IDs: " << totalFreshIngredients << std::endl;

    return 0;
}