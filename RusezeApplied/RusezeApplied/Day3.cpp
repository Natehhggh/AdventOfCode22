#include "Day3.h"
#include <unordered_set>


int Day3::CheckAllBagsPouches(std::vector<std::string> bagLines)
{
	int totalSum = 0;
	for (auto bag : bagLines) {
		totalSum += CheckBagPouches(bag);
	}

	return totalSum;
}


int Day3::CheckBagPouches(std::string bagString)
{
		std::string leftPouch = bagString.substr(0, bagString.length() / 2);
		std::string rightPouch = bagString.substr(bagString.length() / 2, bagString.length() / 2);

		std::unordered_set<int> leftPouchSet = GetSet(leftPouch);
		std::unordered_set<int> rightPouchSet = GetSet(rightPouch);
		

	return GetOverlapSum(leftPouchSet, rightPouchSet);
}


int Day3::GetAllBadgeValues(std::vector<std::string> bagLines)
{
	int totalSum = 0;
	int groupSize = 3;
	std::vector<std::vector<std::string>> groups = std::vector<std::vector<std::string>>();

	std::vector<std::string> newGroup = std::vector<std::string>();
	for (auto &bag : bagLines) {
		if (newGroup.size() < groupSize)
		{
			newGroup.push_back(bag);
		}

		if (newGroup.size() == groupSize)
		{
			groups.push_back(newGroup);
			newGroup.clear();
		}
	}

	for (auto &group : groups) {
		totalSum += GetGroupBadgeValue(group);
	}

	return totalSum;
}


int Day3::GetGroupBadgeValue(std::vector<std::string> bagLines)
{
	std::vector<std::unordered_set<int>> groupSets = std::vector<std::unordered_set<int>>();
	
	for (auto &bag : bagLines) {
		groupSets.push_back(GetSet(bag));
	}


	return GetOverlapSum(groupSets);
}

int Day3::GetPriority(char c)
{
	//TODO: test vs hash lookup for a precalculated set of values
	int priority = c;
	if (c >= 'a')
	{
		priority = c - 'a' + 1;
	}
	else
	{
		priority = c - 'A' + 26 + 1; 
	}

	return priority;
}

std::unordered_set<int> Day3::GetSet(std::string pouchString)
{
	std::unordered_set<int> pouchSet;
	for (size_t i = 0; i < pouchString.length(); i++)
	{
		pouchSet.insert(GetPriority(pouchString[i]));
	}

	return pouchSet;
}


int Day3::GetOverlapSum(std::unordered_set<int> leftPouchSet, std::unordered_set<int> rightPouchSet) {
	int sum = 0;

	for (const auto& elem : leftPouchSet) {
		if (rightPouchSet.find(elem) != rightPouchSet.end())
		{
			sum += elem;
		}
	}
	return sum;
}

int Day3::GetOverlapSum(std::vector<std::unordered_set<int>> bagSets) {
	int sum = 0;

	for (const auto& elem : bagSets[0]) {
		bool containedInAll = true;
		for (size_t i = 1; i < bagSets.size(); i++)
		{
			if (bagSets[i].find(elem) == bagSets[i].end())
			{
				containedInAll = false;
				break;
			}
		}

		if (containedInAll)
		{
			sum += elem;
		}
	}
	return sum;
}