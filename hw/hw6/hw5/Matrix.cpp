/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW6
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

//#include "Matrix.h"
#include <iostream>
#include <assert.h>
#include <iomanip>
using namespace std;

template<class Element>
Matrix<Element>::Matrix(int newRows, int newCols)
:rows(newRows), cols(newCols), m(rows)
{
    for(int i=0; i<rows; i++)
	m[i]= new Array<Element>(cols);

}

template<class Element>
int Matrix<Element>::numRows()
{
    return rows;
}

template<class Element>
int Matrix<Element>::numCols()
{
    return cols;
}

template<class Element>
Array<Element> & Matrix<Element>::operator [](int row)
{
	return * m[row];
}

template<class Element>
void Matrix<Element>::print(ostream & out)
{
    for(int i=0; i<rows; i++)
	m[i]->print(out);
}

template<class Element>
std::ostream & operator << (ostream &out, Matrix<Element> &m)
{
    m.print(out);
    return out;
}
