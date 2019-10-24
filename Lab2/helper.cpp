
void copy_table(int *oldTable, int *newTable, int size)
{
    for(int i = 0; i < size; ++i)
    {
        newTable[i] = oldTable[i];
    }
}
