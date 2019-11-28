
void copy_table(int *from, int *to, int size, int offset)
{
    for(int i = offset; i < offset + size; ++i)
    {
        to[i] = from[i-offset];
    }
}
