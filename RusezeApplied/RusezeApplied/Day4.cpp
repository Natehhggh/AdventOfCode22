#pragma once

#include <vector>
#include <string>
#include "day4.h"
#include "StringHelper.h"

int day4::GetFirstStar(std::vector<std::string> lines)
{
	int containedCount = 0;

	for (size_t i = 0; i < lines.size(); i++)
	{
		containedCount += CheckRangeStringContained(lines[i]);
	}

	return containedCount;
}

bool day4::IsContained(range a, range b)
{
	return ( (a.min <= b.min) == (b.max <= a.max) );
}

bool day4::CheckRangeStringContained(std::string line)
{
	std::vector<std::string> rangeStrings = StringHelper::Split(line, ',');

	std::vector<range> ranges = std::vector<range>();

	for (size_t i = 0; i < rangeStrings.size(); i++)
	{
		ranges.push_back(GetRange(rangeStrings[i]));
	}

	bool contained = IsContained(ranges[0], ranges[1]);

	return contained;
}

range day4::GetRange(std::string rangeString)
{
	std::vector<std::string> rangeVals = StringHelper::Split(rangeString, '-');
	range newRange = range();
	newRange.min = stoi(rangeVals[0]);
	newRange.max = stoi(rangeVals[1]);
	return newRange;
}


