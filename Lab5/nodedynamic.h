#ifndef NODEDYNAMIC_H
#define NODEDYNAMIC_H
#include <vector>
#include <iostream>

class NodeDynamic
{
public:
    NodeDynamic() { val = 0; };
    ~NodeDynamic();

    void setValue(int newVal) { val = newVal; };

    int getChildrenNumber() { return children.size(); }
    void addNewChild();
    NodeDynamic *getChild(int childOffset);

    void print() { std::cout << " " << val; }
    void printAllBelow();

private:
    std::vector<NodeDynamic*> children;
    int val;
};

#endif // NODEDYNAMIC_H
