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
    // tests
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

    Table t3("Table0", 2);
    Table t4("Table1", 2);

    t3.setValue(0, 1);
    t3.setValue(1, 2);

    t4.setValue(0, 3);
    t4.setValue(1, 4);

    t3.printTable();
    t4.printTable();

    t3.acc(t4);

    t3.printTable();


    return 0;
}
