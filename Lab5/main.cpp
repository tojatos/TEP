#include <iostream>
#include "constants.h"
#include "nodestatic.h"
#include "treestatic.h"
#include "nodedynamic.h"
#include "treedynamic.h"

void  staticTreeTest()
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


void  dynamicTreeTest()
{
    TreeDynamic tree;
    NodeDynamic *root = tree.getRoot();

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
}
int main()
{
    staticTreeTest();
    dynamicTreeTest();
    return 0;
}
