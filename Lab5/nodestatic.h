#ifndef NODESTATIC_H
#define NODESTATIC_H
#include <vector>
#include <iostream>

class NodeStatic
{
public:
    NodeStatic() { val = 0; parent = NULL; };
    ~NodeStatic();

    void setValue(int newVal) { val = newVal; };

    int getChildrenNumber() { return children.size(); }
    void addNewChild();
    NodeStatic *getChild(int childOffset);
    void setParent(NodeStatic *parent) { this->parent = parent; };
    NodeStatic *getParent() { return this->parent; };

    void print() { std::cout << " " << val; }
    void printAllBelow();
    void printUp();

private:
    std::vector<NodeStatic> children;
    int val;
    NodeStatic *parent;
};

#endif // NODESTATIC_H
