#pragma once

#include <unordered_set>
#include <string>
#include <vector>
class Day3
{
public:
	int CheckAllBags(std::vector<std::string> bagLines);
	
private:
	int CheckBag(std::string bagString);
	int GetPriority(char c);
	std::unordered_set<int> GetSet(std::string pouchString);
	int GetOverlapSum(std::unordered_set<int> leftPouchSet, std::unordered_set<int> rightPouchSet);
};

