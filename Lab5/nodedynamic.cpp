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

void NodeDynamic::prettyPrintBelow(int depth)
{
    for(int i = 0; i < depth; ++i)
    {
        if(i > 0) std::cout << "   ";
        std::cout << "|";
    }
    if(depth>0) std::cout << "---";
    std::cout << this->val << '\n';
    int n = getChildrenNumber();
    for(int i = 0; i < n; ++i)
    {
        children[i]->prettyPrintBelow(depth+1);
    }

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


void NodeDynamic::printUp()
{
    print();
    if(this->parent != NULL)
    {
        this->parent->printUp();
    }
}
