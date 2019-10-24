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
    mod_tab(t, 6);
    Table *t2 = t.clone();
    mod_tab(t2, 7);
    delete t2;

    Table t3("Table", 1);

    return 0;
}
