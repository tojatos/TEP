#ifndef FILELASTERROR_H
#define FILELASTERROR_H

#include <string>
#include <vector>

class FileLastError
{
public:
    FileLastError();
    FileLastError(std::string fileName);
    ~FileLastError();

    void openFile(std::string fileName);
    void closeFile();
    void printLine(std::string text);
    void printManyLines(std::vector<std::string> text);

    bool getLastError() {return(lastError);}
private:
    bool lastError;
    FILE *file;
};

#endif // FILELASTERROR_H
