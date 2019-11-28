#ifndef NODEDYNAMIC_H
#define NODEDYNAMIC_H
#include <vector>
#include <iostream>

template<typename T>
class NodeDynamic
{
public:
    NodeDynamic() { parent=NULL; };
    ~NodeDynamic();

    void setValue(T newVal) { val = newVal; };

    int getChildrenNumber() { return children.size(); }
    void addNewChild();
    void addNewChild(NodeDynamic* child);
    NodeDynamic *getChild(int childOffset);
    NodeDynamic *getParent();
    void setParent(NodeDynamic* newParent);
    std::vector<NodeDynamic*> *getChildren() { return &children; };

    void print() { std::cout << " " << val; }
    void prettyPrintBelow(int depth);
    void printAllBelow();
    T sumAllBelow();
    void printUp();

private:
    std::vector<NodeDynamic*> children;
    NodeDynamic* parent;
    T val;
};

template<typename T>
NodeDynamic<T>::~NodeDynamic()
{
    int childrenSize = children.size();
    for(int i = 0; i < childrenSize; ++i)
    {
        delete children[i];
    }
}

template<typename T>
void NodeDynamic<T>::addNewChild()
{
    addNewChild(new NodeDynamic);
}

template<typename T>
void NodeDynamic<T>::addNewChild(NodeDynamic<T> *child)
{
    child->parent = this;
    children.push_back(child);
}

template<typename T>
NodeDynamic<T> *NodeDynamic<T>::getChild(int childOffset)
{
    if(childOffset < 0 || childOffset >= getChildrenNumber())
        return NULL;
    return children[childOffset];
}

template<typename T>
NodeDynamic<T> *NodeDynamic<T>::getParent()
{
    return this->parent;
}

template<typename T>
void NodeDynamic<T>::setParent(NodeDynamic<T> *newParent)
{
    this->parent = newParent;
}

template<typename T>
void NodeDynamic<T>::prettyPrintBelow(int depth)
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

template<typename T>
void NodeDynamic<T>::printAllBelow()
{
    print();
    int n = getChildrenNumber();
    for(int i = 0; i < n; ++i)
    {
        children[i]->printAllBelow();
    }
}

template<typename T>
T NodeDynamic<T>::sumAllBelow()
{
    int ret = this->val;
    int n = getChildrenNumber();
    for(int i = 0; i < n; ++i)
    {
        ret += children[i]->sumAllBelow();
    }
    return ret;
}

template<typename T>
void NodeDynamic<T>::printUp()
{
    print();
    if(this->parent != NULL)
    {
        this->parent->printUp();
    }
}
#endif // NODEDYNAMIC_H
