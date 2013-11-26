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

#include <iostream>
#include "Array.h"
#include "Matrix.h"
//#include <iomanip>
using namespace std;

template<class T>
void fillMatrix(Matrix<T> & m)
{
    int i, j;
    for(i=0; i<m.numRows();i++)
	m[i][0] = T();
    for(j=0; j<m.numCols(); j++)
	m[0][j]=T();
    for(i=1; i<m.numRows(); i++)
	for(j=1; j<m.numCols(); j++)
	    m[i][j] = T(i*j);
}

int main()
{
    Matrix<int> m(10,5);
    fillMatrix (m);
    cout << m << endl << endl;

    Matrix<double> M(8,10);
    fillMatrix(M);
    cout << setprecision(1) << fixed <<  M << endl;
    try
    {
        m[11];
    }
    catch(IndexOutOfBoundsException a)
    {
	cerr << "Index is out of bounds\n";
    }
}
