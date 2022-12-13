#include "FileReader.h"
#include <iostream>
#include <vector>
#include <string>
#include "Day3.h"
#include "Day4.h"

int main()
{
	int day = 3;
	FileReader reader = FileReader();

	reader.Read("Data\\Day4.txt");
	
	std::vector<std::string> lines = reader.Lines();

	day4 dayObject = day4();
	
	int value = dayObject.GetSecondStar(lines);

	std::cout <<  "Value: " << value;

	return 0;
}

