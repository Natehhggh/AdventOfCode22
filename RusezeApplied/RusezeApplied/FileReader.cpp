#include "FileReader.h"
#include <string>

FileReader::FileReader()
{
	InStream =  std::ifstream();
}

void FileReader::Read(std::string filePath)
{
	InStream.open(filePath);
	lines = std::vector<std::string>();
	
	while (!InStream.eof()) {
		std::string line;
		getline(InStream, line);
		lines.push_back(line);
	}
}

std::vector<std::string> FileReader::Lines()
{
	return lines;
}

