#ifndef TREEDYNAMIC_H
#define TREEDYNAMIC_H
#include "nodedynamic.h"


template<typename T>
class TreeDynamic
{
public:
    TreeDynamic();
    ~TreeDynamic();

    NodeDynamic<T> *getRoot() { return root; };
    void printTree();
    void printPrettyTree();
    bool moveSubtree(NodeDynamic<T> *parentNode, NodeDynamic<T> *newChildNode);
private:
    NodeDynamic<T> *root;
};

template<typename T>
TreeDynamic<T>::TreeDynamic()
{
    root = new NodeDynamic<T>();
}

template<typename T>
TreeDynamic<T>::~TreeDynamic()
{
    delete root;
}

template<typename T>
void TreeDynamic<T>::printTree()
{
    root->printAllBelow();
}

template<typename T>
void TreeDynamic<T>::printPrettyTree()
{
    root->prettyPrintBelow(0);
}

template<typename T>
bool TreeDynamic<T>::moveSubtree(NodeDynamic<T> *parentNode, NodeDynamic<T> *newChildNode)
{
    if(parentNode == NULL || newChildNode == NULL)
        return false;

    std::vector<NodeDynamic<T>*> *children = newChildNode->getParent()->getChildren();
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
#endif // TREEDYNAMIC_H
