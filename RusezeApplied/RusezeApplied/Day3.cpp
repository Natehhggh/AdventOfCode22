#include "Day3.h"
#include <unordered_set>


int Day3::CheckAllBags(std::vector<std::string> bagLines)
{
	int totalSum = 0;
	for (auto bag : bagLines) {
		totalSum += CheckBag(bag);
	}

	return totalSum;
}


int Day3::CheckBag(std::string bagString)
{
		std::string leftPouch = bagString.substr(0, bagString.length() / 2);
		std::string rightPouch = bagString.substr(bagString.length() / 2, bagString.length() / 2);

		std::unordered_set<int> leftPouchSet = GetSet(leftPouch);
		std::unordered_set<int> rightPouchSet = GetSet(rightPouch);
		

	return GetOverlapSum(leftPouchSet, rightPouchSet);
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

