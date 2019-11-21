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

bool TreeStatic::moveSubtree(NodeStatic *parentNode, NodeStatic *newChildNode)
{
    if(parentNode == NULL || newChildNode == NULL)
        return false;

    std::vector<NodeStatic> *children = newChildNode->getParent()->getChildren();
    NodeStatic copiedNode = *newChildNode;
    parentNode->addNewChild(copiedNode);
    parentNode->assignParents();

    int childrenSize = children->size();
    bool found = false;
    for (int i = 0; i < childrenSize && !found; ++i)
    {
        if(&((*children)[i]) == newChildNode)
        {
            children->erase(children->begin() + i);
            found = true;
        }
    }

    return true;
}
