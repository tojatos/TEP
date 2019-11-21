#ifndef NODESTATIC_H
#define NODESTATIC_H
#include <vector>
#include <iostream>

class NodeStatic
{
public:
    NodeStatic() { val = 0; parent=NULL;};
    ~NodeStatic();

    void setValue(int newVal) { val = newVal; };
    int getChildrenNumber() { return children.size(); }
    void addNewChild();
    void addNewChild(NodeStatic &child);
    void assignParents();
    NodeStatic *getChild(int childOffset);
    NodeStatic *getParent();
    void setParent(NodeStatic* newParent);
    std::vector<NodeStatic> *getChildren() { return &children; };

    void print() { std::cout << " " << val; }
    void printAllBelow();
    void printUp();

private:
    std::vector<NodeStatic> children;
    NodeStatic* parent;
    int val;
};

#endif // NODESTATIC_H
