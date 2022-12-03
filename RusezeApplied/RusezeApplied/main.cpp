#include "FileReader.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	int day = 3;
	FileReader reader = FileReader();

	reader.Read("Data\\Day3.txt");

	
	std::vector<std::string> lines = reader.Lines();

	std::cout << lines.at(0);

	return 0;
}

