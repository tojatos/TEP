#include "treestatic.h"

TreeStatic::TreeStatic()
{
    root = NodeStatic();
}

TreeStatic::~TreeStatic()
{

}

void TreeStatic::printTree()
{
    root.printAllBelow();
}
