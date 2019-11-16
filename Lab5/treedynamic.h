#ifndef TREEDYNAMIC_H
#define TREEDYNAMIC_H
#include "nodedynamic.h"


class TreeDynamic
{
public:
    TreeDynamic();
    ~TreeDynamic();

    NodeDynamic *getRoot() { return root; };
    void printTree();
private:
    NodeDynamic *root;
};

#endif // TREEDYNAMIC_H
