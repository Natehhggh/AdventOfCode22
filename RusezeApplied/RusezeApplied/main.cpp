#include "FileReader.h"
#include <iostream>
#include <vector>
#include <string>
#include "Day3.h"

int main()
{
	int day = 3;
	FileReader reader = FileReader();

	reader.Read("Data\\Day3.txt");
	
	std::vector<std::string> lines = reader.Lines();

	Day3 day3 = Day3();

	int value = day3.CheckAllBags(lines);
	

	std::cout <<  "Value: " << value;

	return 0;
}

