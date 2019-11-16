#include "nodestatic.h"


NodeStatic::~NodeStatic()
{
}

void NodeStatic::addNewChild()
{
    NodeStatic x;
    x.parents.push_back(*this);
    children.push_back(x);
}

NodeStatic *NodeStatic::getChild(int childOffset)
{
    if(childOffset < 0 || childOffset >= getChildrenNumber())
        return NULL;
    return &children[childOffset];
}

void NodeStatic::printAllBelow()
{
    print();
    int n = getChildrenNumber();
    for(int i = 0; i < n; ++i)
    {
        children[i].printAllBelow();
    }
}

void NodeStatic::printUp()
{
    print();
    int parentsSize = this->parents.size();
    for(int i = 0; i < parentsSize; ++i)
    {
        this->parents[i].printUp();
    }
}
