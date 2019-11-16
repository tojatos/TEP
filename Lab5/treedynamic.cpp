#include "treedynamic.h"

TreeDynamic::TreeDynamic()
{
    root = new NodeDynamic();
}

TreeDynamic::~TreeDynamic()
{
    delete root;
}

void TreeDynamic::printTree()
{
    root->printAllBelow();
}
