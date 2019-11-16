#include "nodedynamic.h"


NodeDynamic::~NodeDynamic()
{
}

void NodeDynamic::addNewChild()
{
    NodeDynamic x;
    x.parents.push_back(*this);
    children.push_back(x);
}

NodeDynamic *NodeDynamic::getChild(int childOffset)
{
    if(childOffset < 0 || childOffset >= getChildrenNumber())
        return NULL;
    return &children[childOffset];
}

void NodeDynamic::printAllBelow()
{
    print();
    int n = getChildrenNumber();
    for(int i = 0; i < n; ++i)
    {
        children[i].printAllBelow();
    }
}

void NodeDynamic::printUp()
{
    print();
    int parentsSize = this->parents.size();
    for(int i = 0; i < parentsSize; ++i)
    {
        this->parents[i].printUp();
    }
}
