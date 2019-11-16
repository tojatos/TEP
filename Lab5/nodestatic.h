#ifndef NODESTATIC_H
#define NODESTATIC_H
#include <vector>
#include <iostream>

class NodeStatic
{
public:
    NodeStatic() { val = 0; };
    ~NodeStatic();

    void setValue(int newVal) { val = newVal; };

    int getChildrenNumber() { return children.size(); }
    void addNewChild();
    NodeStatic *getChild(int childOffset);

    void print() { std::cout << " " << val; }
    void printAllBelow();
    void printUp();

private:
    std::vector<NodeStatic> children;
    std::vector<NodeStatic> parents;
    int val;
};

#endif // NODESTATIC_H
