#pragma once

#include <unordered_set>
#include <string>
#include <vector>
class Day3
{
public:
	int CheckAllBagsPouches(std::vector<std::string> bagLines);
	int GetAllBadgeValues(std::vector<std::string> bagLines);

private:
	int CheckBagPouches(std::string bagString);
	int GetGroupBadgeValue(std::vector<std::string> bagLines);
	int GetPriority(char c);
	std::unordered_set<int> GetSet(std::string pouchString);
	int GetOverlapSum(std::unordered_set<int> leftPouchSet, std::unordered_set<int> rightPouchSet);
	int GetOverlapSum(std::vector<std::unordered_set<int>> bagSets);
};

