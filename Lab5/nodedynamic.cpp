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
    addNewChild(new NodeDynamic);
}

void NodeDynamic::addNewChild(NodeDynamic *child)
{
    child->parent = this;
    children.push_back(child);
}

NodeDynamic *NodeDynamic::getChild(int childOffset)
{
    if(childOffset < 0 || childOffset >= getChildrenNumber())
        return NULL;
    return children[childOffset];
}

NodeDynamic *NodeDynamic::getParent()
{
    return this->parent;
}

void NodeDynamic::setParent(NodeDynamic *newParent)
{
    this->parent = newParent;
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
