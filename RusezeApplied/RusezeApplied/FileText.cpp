#include "FileText.h"

FileText::FileText(std::vector<std::string>* linesPtr)
{
    lines = linesPtr;
}

std::vector<std::string>* FileText::Lines()
{
    return lines;
}

FileText::~FileText()
{
    delete& lines;
}
