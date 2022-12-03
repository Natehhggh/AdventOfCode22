#pragma once
#include <fstream>
#include <vector>
class FileReader
{
private:
	std::ifstream InStream;
	std::vector<std::string> lines;
	
public: 
	FileReader();
	void Read(std::string);
	std::vector<std::string> Lines();
};

