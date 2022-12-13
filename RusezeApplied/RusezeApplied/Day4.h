#pragma once

#include <vector>
#include <string>


struct range {
	int min;
	int max;
};

class day4
{
public:
	int GetFirstStar(std::vector<std::string> lines);
private:
	bool IsContained(range a, range b);
	range GetRange(std::string rangeString);
	bool CheckRangeStringContained(std::string line);
};


