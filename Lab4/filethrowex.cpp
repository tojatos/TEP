#include "filethrowex.h"

FileThrowEx::FileThrowEx()
{
    this->fileName = "";
}

FileThrowEx::FileThrowEx(std::string fileName)
{
    this->fileName = fileName;
    openFile(fileName);
}

FileThrowEx::FileThrowEx(const FileThrowEx &other)
{
    this->fileName = other.fileName + "_copy.txt";
    openFile(this->fileName);
}

FileThrowEx::~FileThrowEx()
{
    if(file != NULL) {
        closeFile();
    }
}

void FileThrowEx::openFile(std::string fileName)
{
    this->fileName = fileName;
    file = fopen(fileName.c_str(), FILE_OPEN_FLAGS);
    if(file == NULL)
    {
        throw 1;
    }
}

void FileThrowEx::closeFile()
{
    if(file == NULL)
    {
        throw 1;
    }

    fclose(file);
}

void FileThrowEx::printLine(std::string text)
{
    if(file == NULL)
    {
        throw 1;
    }

    fprintf(file, "%s", text.c_str());
}

void FileThrowEx::printManyLines(std::vector<std::string> text)
{
    if(file == NULL)
    {
        throw 1;
    }

    size_t vecSize = text.size();
    for (int i = 0; i < vecSize; ++i)
    {
        const char * t = text[i].c_str();
        fprintf(file, "%s", t);
    }
}
