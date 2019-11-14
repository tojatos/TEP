#include "fileerrcode.h"

FileErrCode::FileErrCode()
{

}

FileErrCode::FileErrCode(std::string fileName, int &ret)
{
    ret = openFile(fileName);
}

FileErrCode::~FileErrCode()
{
    if(file != NULL) {
        closeFile();
    }
}

bool FileErrCode::openFile(std::string fileName)
{
    file = fopen(fileName.c_str(), FILE_OPEN_FLAGS);
    if(file == NULL)
    {
        return 1;
    }
    return 0;
}

bool FileErrCode::closeFile()
{
    if(file == NULL)
    {
        return 1;
    }

    fclose(file);
    return 0;
}

bool FileErrCode::printLine(std::string text)
{
    if(file == NULL)
    {
        return 1;
    }

    fprintf(file, "%s", text.c_str());
    return 0;
}

bool FileErrCode::printManyLines(std::vector<std::string> text)
{
    if(file == NULL)
    {
        return 1;
    }

    size_t vecSize = text.size();
    for (int i = 0; i < vecSize; ++i)
    {
        const char * t = text[i].c_str();
        fprintf(file, "%s", t);
    }
    return 0;
}
