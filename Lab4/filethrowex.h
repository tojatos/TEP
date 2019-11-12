#ifndef FILETHROWEX_H
#define FILETHROWEX_H

#include <string>
#include <vector>
#include "constants.h"

class FileThrowEx
{
public:
    FileThrowEx();
    FileThrowEx(std::string fileName);
    ~FileThrowEx();

    void openFile(std::string fileName);
    void closeFile();
    void printLine(std::string text);
    void printManyLines(std::vector<std::string> text);
private:
    FILE *file;
};

#endif // FILETHROWEX_H
