#include <iostream>
#include "constants.h"
#include "table.h"

void mod_tab(Table *tab, int newSize)
{
    tab->setNewSize(newSize);
}

void mod_tab(Table tab, int newSize)
{
    tab.setNewSize(newSize);
}
int main()
{
    Table t;
    t.setName("Arr");
    std::cout << "Mod tab start:\n";
    mod_tab(t, 6);
    std::cout << "Mod tab end.\n";
    Table *t2 = t.clone();
    std::cout << "Mod tab pointer start:\n";
    mod_tab(t2, 7);
    std::cout << "Mod tab pointer end.\n";
    delete t2;

    Table t3("Table", 1);

    return 0;
}
