//template array
//#include "Array.h"
#include <iostream>
#include <assert.h>
#include <iomanip>
using namespace std;

template <class T>
Array<T>::Array(int newLen)
:len (newLen), buf(new T[newLen])
{
}

template <class T>
Array<T>::Array(Array<T> & l)
:len(l.len), buf (new T[l.len])
{
    for(int i=0; i<l.len; i++)
	buf[i] = l.buf[i];
}

template <class T>
int Array<T>::length()
{
    return len;
}

template <class T>
T& Array<T>::operator [] (int i)
{
    assert(0 <= i && i < len);
    return buf[i];
}

template <class T>
void Array<T>::print(ostream & out)
{
    for (int i=0; i<len; i++)
	out << setw(5) << buf[i];
}

template <class T>
ostream & operator << (ostream & out, Array<T> & a)
{
    a.print(out);
    return out;
}
