#include <iostream>
#include "constants.h"
#include "filelasterror.h"
#include "filethrowex.h"
#include "fileerrcode.h"

void openLastError()
{
    std::cout << "Last error\n";
    FileLastError f;
    for(int i = 0; i < 10 && !f.getLastError(); ++i)
    {
        std::cout << i << '\n';
        f.openFile(TEST_FILE_NAME);
    }
}

void openThrowEx()
{
    std::cout << "Throw ex\n";
    FileThrowEx f;
    try {
        for(int i = 0; i < 10; ++i)
        {
            std::cout << i << '\n';
            f.openFile(TEST_FILE_NAME);
        }
    } catch(int ex) {
        std::cout << "Exception: " << ex << '\n';
    }
}

void openErrCode()
{
    std::cout << "Err code\n";
    FileErrCode f;
    int code = 0;
    for(int i = 0; i < 10 && !code; ++i)
    {
        std::cout << i << '\n';
        code = f.openFile(TEST_FILE_NAME);
    }
}
int main()
{
    FileLastError f;
    f.openFile("test");
    if(!f.getLastError()) {
        f.printManyLines({"ala", "ma"});
        if(!f.getLastError()) {
            f.printLine("kota");
        }
    }
    FileThrowEx fex;
    fex.openFile("fex");
    fex.printManyLines({"ala", "ma"});
    fex.printLine("kota");

    openLastError();
    openThrowEx();
    openErrCode();


    FileThrowEx copy = fex;
    copy.printLine("test_copy");
}
