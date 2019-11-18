#include "nodestatic.h"


NodeStatic::~NodeStatic()
{
}

void NodeStatic::addNewChild()
{
    NodeStatic x;
    addNewChild(x);
}

void NodeStatic::addNewChild(NodeStatic &child)
{
    child.parent = this;
    children.push_back(child);
}

NodeStatic *NodeStatic::getChild(int childOffset)
{
    if(childOffset < 0 || childOffset >= getChildrenNumber())
        return NULL;
    return &children[childOffset];
}

NodeStatic *NodeStatic::getParent()
{
    return this->parent;
}

void NodeStatic::setParent(NodeStatic *newParent)
{
    this->parent = newParent;
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
    if(this->parent != NULL)
    {
        this->parent->printUp();
    }
}
