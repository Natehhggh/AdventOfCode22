#include "StringHelper.h"
#include <sstream>

std::vector<std::string> StringHelper::Split(std::string string, char delim)
{
	std::vector<std::string> splitTokens = std::vector<std::string>();

	std::stringstream stream = std::stringstream(string);
	std::string token;

	while (std::getline(stream, token, delim)) {
		splitTokens.push_back(token);
	}

	return splitTokens;
}
