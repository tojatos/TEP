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
    bool moveSubtree(NodeStatic *parentNode, NodeStatic *newChildNode);
private:
    NodeStatic root;
};

#endif // TREESTATIC_H
