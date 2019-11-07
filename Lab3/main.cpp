#include <iostream>
#include <algorithm>
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
    tab_0.setValue(1, 13);
    tab_1.setValue(2, 123);
    tab_0 = tab_1;
    tab_0.setValue(0, 19);
    tab_0.printTable();
    tab_1.printTable();
    Table tab_2 = tab_0 + tab_1;
    tab_2.printTable();

    Table ar0("first", 6);
    Table ar1("second", 4);
    ar0.setValue(0, 1);
    ar0.setValue(1, 2);
    ar0.setValue(2, 3);
    ar0.setValue(3, 4);
    ar0.setValue(4, 5);
    ar0.setValue(5, 6);
    ar1.setValue(0, 1);
    ar1.setValue(1, 3);
    ar1.setValue(2, 3);
    ar1.setValue(3, 8);

    ar0.printTable();
    ar1.printTable();

    Table dif = ar0 - ar1;
    dif.printTable();

    return 0;
}
