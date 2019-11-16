#include <iostream>
#include "constants.h"
#include "nodestatic.h"
#include "treestatic.h"

void  treeTest()
{
    TreeStatic tree;
    NodeStatic *root = tree.getRoot();


    root->addNewChild();
    root->addNewChild();

    root->getChild(0)->setValue(1);
    root->getChild(1)->setValue(2);

    root->getChild(0)->addNewChild();
    root->getChild(0)->addNewChild();

    root->getChild(0)->getChild(0)->setValue(11);
    root->getChild(0)->getChild(1)->setValue(12);

    root->getChild(1)->addNewChild();
    root->getChild(1)->addNewChild();

    root->getChild(1)->getChild(0)->setValue(21);
    root->getChild(1)->getChild(1)->setValue(22);

    tree.printTree();

    std::cout << '\n';

    root->getChild(0)->getChild(1)->printUp();

    std::cout << '\n';
}

int main()
{
    treeTest();
    return 0;
}
