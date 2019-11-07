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
    Table tab_0, tab_1;
    tab_0.setNewSize(6);
    tab_1.setNewSize(4);
    tab_0 = tab_1;
    tab_1.setValue(2, 123);
    tab_0.printTable();
    tab_1.printTable();
    Table tab_2 = tab_0 + tab_1;
    tab_2.printTable();

    return 0;
}
