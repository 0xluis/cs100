#ifndef MATRIX_H
#define MATRIX_H
#include "Array.h"
template <class Element>
class Matrix
{
    int rows, cols;
    Array<Array<Element>*> m;
};

#endif
