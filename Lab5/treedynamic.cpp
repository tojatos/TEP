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

void TreeDynamic::printPrettyTree()
{
    root->prettyPrintBelow(0);
}

bool TreeDynamic::moveSubtree(NodeDynamic *parentNode, NodeDynamic *newChildNode)
{
    if(parentNode == NULL || newChildNode == NULL)
        return false;

    std::vector<NodeDynamic*> *children = newChildNode->getParent()->getChildren();
    int childrenSize = children->size();
    bool found = false;
    for (int i = 0; i < childrenSize && !found; ++i)
    {
        if((*children)[i] == newChildNode)
        {
            children->erase(children->begin() + i);
            found = true;
        }
    }
    parentNode->addNewChild(newChildNode);

    return true;
}
