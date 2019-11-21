#ifndef NODEDYNAMIC_H
#define NODEDYNAMIC_H
#include <vector>
#include <iostream>

class NodeDynamic
{
public:
    NodeDynamic() { val = 0; parent=NULL; };
    ~NodeDynamic();

    void setValue(int newVal) { val = newVal; };

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
    void printUp();

private:
    std::vector<NodeDynamic*> children;
    NodeDynamic* parent;
    int val;
};

#endif // NODEDYNAMIC_H
