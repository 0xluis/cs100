//template array
#ifndef ARRAY_H
#define ARRAY_H
#include <ostream>
template <typename T> class Array;
template <typename T> std::ostream& operator <<(std::ostream & out, Array<T>&a);

template <typename T>
class Array
{
    private:
	int len;
	T *buf;
    public:
	Array(int newLen);
	Array(Array<T>&);
	int length();
	T &operator [] (int);
	void print(std::ostream &);
	//template <typename T>
	friend std::ostream & operator << <>(std::ostream & out, Array<T>& a);
};
#include "Array.cpp"
#endif

