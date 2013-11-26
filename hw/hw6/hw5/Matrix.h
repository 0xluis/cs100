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

#ifndef MATRIX_H
#define MATRIX_H
#include "Array.h"

//needed for friend to be declared outside of this file
template <typename Element> class Matrix;
template <typename Element> std::ostream& operator <<(std::ostream & out, 
				                     Matrix<Element>&m);
template <typename Element>
class Matrix
{
    private:
	int rows, cols;
	Array<Array<Element>*> m;
    public:
	Matrix( int newRows, int newCols);
	int numRows();
	int numCols();
	Array <Element> & operator [] (int row);
	void print(std::ostream & out);
	//<> needed to define non template function
	friend std::ostream & operator << <>(std::ostream &out, Matrix<Element> &m);
};
//needed or linking errors
#include "Matrix.cpp"
#endif
