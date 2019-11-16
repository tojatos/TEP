#include "nodedynamic.h"


NodeDynamic::~NodeDynamic()
{
    int childrenSize = children.size();
    for(int i = 0; i < childrenSize; ++i)
    {
        delete children[i];
    }
}

void NodeDynamic::addNewChild()
{
    NodeDynamic* x = new NodeDynamic;
    children.push_back(x);
}

NodeDynamic *NodeDynamic::getChild(int childOffset)
{
    if(childOffset < 0 || childOffset >= getChildrenNumber())
        return NULL;
    return children[childOffset];
}

void NodeDynamic::printAllBelow()
{
    print();
    int n = getChildrenNumber();
    for(int i = 0; i < n; ++i)
    {
        children[i]->printAllBelow();
    }
}
