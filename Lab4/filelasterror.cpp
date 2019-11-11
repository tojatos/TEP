#include "filelasterror.h"

FileLastError::FileLastError()
{

}

FileLastError::FileLastError(std::string fileName)
{
    openFile(fileName);
}

FileLastError::~FileLastError()
{
    if(file != NULL) {
        closeFile();
    }
}

void FileLastError::openFile(std::string fileName)
{
    lastError = false;
    file = fopen(fileName.c_str(), "w+");
    if(file == NULL)
    {
        lastError = true;
        return;
    }
}

void FileLastError::closeFile()
{
    lastError = false;

    if(file == NULL)
    {
        lastError = true;
        return;
    }

    fclose(file);
}

void FileLastError::printLine(std::string text)
{
    lastError = false;

    if(file == NULL)
    {
        lastError = true;
        return;
    }

    fprintf(file, "%s", text.c_str());
}

void FileLastError::printManyLines(std::vector<std::string> text)
{
    lastError = false;

    if(file == NULL)
    {
        lastError = true;
        return;
    }

    size_t vecSize = text.size();
    for (int i = 0; i < vecSize; ++i)
    {
        const char * t = text[i].c_str();
        fprintf(file, "%s", t);
    }
}
