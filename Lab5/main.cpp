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

    root->getChild(0)->getChild(1)->printUp();

    std::cout << '\n';

}

void moveStaticTest()
{
    TreeStatic tree;
    TreeStatic tree2;
    NodeStatic *root = tree.getRoot();
    NodeStatic *root2 = tree2.getRoot();

    root->setValue(0);
    root->addNewChild();
    root->addNewChild();
    root->addNewChild();

    root->getChild(0)->setValue(1);
    root->getChild(1)->setValue(2);
    root->getChild(2)->setValue(3);
    root->getChild(2)->addNewChild();
    root->getChild(2)->getChild(0)->setValue(4);

    tree.printTree();

    std::cout << '\n';

    root2->addNewChild();
    root2->addNewChild();

    root2->setValue(50);
    root2->getChild(0)->setValue(54);
    root2->getChild(1)->setValue(55);
    root2->getChild(0)->addNewChild();
    root2->getChild(0)->addNewChild();
    root2->getChild(0)->getChild(0)->setValue(56);
    root2->getChild(0)->getChild(1)->setValue(57);
    root2->getChild(0)->getChild(0)->addNewChild();
    root2->getChild(0)->getChild(0)->getChild(0);
    root2->getChild(0)->getChild(0)->getChild(0)->setValue(58);

    tree2.printTree();

    std::cout << '\n';

    tree.moveSubtree(root->getChild(2), root2->getChild(0));

    tree.printTree();
    std::cout << '\n';
    tree2.printTree();
    std::cout << '\n';
    root->getChild(2)->getChild(1)->getChild(0)->getChild(0)->printUp();
    std::cout << '\n';
}

void moveDynamicTest()
{
    TreeDynamic tree;
    TreeDynamic tree2;
    NodeDynamic *root = tree.getRoot();
    NodeDynamic *root2 = tree2.getRoot();

    root->setValue(0);
    root->addNewChild();
    root->addNewChild();
    root->addNewChild();

    root->getChild(0)->setValue(1);
    root->getChild(1)->setValue(2);
    root->getChild(2)->setValue(3);
    root->getChild(2)->addNewChild();
    root->getChild(2)->getChild(0)->setValue(4);

    tree.printTree();

    std::cout << '\n';

    root2->addNewChild();
    root2->addNewChild();

    root2->setValue(50);
    root2->getChild(0)->setValue(54);
    root2->getChild(1)->setValue(55);
    root2->getChild(0)->addNewChild();
    root2->getChild(0)->addNewChild();
    root2->getChild(0)->getChild(0)->setValue(56);
    root2->getChild(0)->getChild(1)->setValue(57);
    root2->getChild(0)->getChild(0)->addNewChild();
    root2->getChild(0)->getChild(0)->getChild(0);
    root2->getChild(0)->getChild(0)->getChild(0)->setValue(58);

    tree2.printTree();

    std::cout << '\n';

    tree.moveSubtree(root->getChild(2), root2->getChild(0));

    tree.printTree();
    std::cout << '\n';
    tree2.printTree();
    std::cout << '\n';
    root->getChild(2)->getChild(1)->getChild(0)->getChild(0)->printUp();
    std::cout << '\n';
}

int main()
{
    staticTreeTest();
    dynamicTreeTest();
    moveStaticTest();
    moveDynamicTest();
    return 0;
}
