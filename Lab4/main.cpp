#include <iostream>
#include "constants.h"
#include "filelasterror.h"

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
}
