#include "treedynamic.h"

TreeDynamic::TreeDynamic()
{
    root = NodeDynamic();
}

TreeDynamic::~TreeDynamic()
{

}

void TreeDynamic::printTree()
{
    root.printAllBelow();
}
