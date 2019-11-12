#ifndef FILEERRCODE_H
#define FILEERRCODE_H

#include <string>
#include <vector>
#include "constants.h"

class FileErrCode
{
public:
    FileErrCode();
    FileErrCode(std::string fileName);
    ~FileErrCode();

    bool openFile(std::string fileName);
    bool closeFile();
    bool printLine(std::string text);
    bool printManyLines(std::vector<std::string> text);
private:
    FILE *file;
};

#endif // FILEERRCODE_H
