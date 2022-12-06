#pragma once

#include <string>
#include <vector>
class FileText
{
private:
	std::vector<std::string>* lines;

public:
	FileText(std::vector<std::string>*);
	std::vector<std::string>* Lines();
	~FileText();
};

