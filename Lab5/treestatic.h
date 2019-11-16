#ifndef TREESTATIC_H
#define TREESTATIC_H
#include "nodestatic.h"


class TreeStatic
{
public:
    TreeStatic();
    ~TreeStatic();

    NodeStatic *getRoot() { return(&root); };
    void printTree();
private:
    NodeStatic root;
};

#endif // TREESTATIC_H
