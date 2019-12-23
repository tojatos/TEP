#ifndef DIFFHELPER_H
#define DIFFHELPER_H

inline bool areDifferent(int i, int j, int k, int l)
{
    return i != j && i != k && i != l &&
            j != k && j != l &&
            k != l;
}

#endif // DIFFHELPER_H
