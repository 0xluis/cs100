#define STACK_CAPACITY 1000
#include <iostream>
using namespace std;

class Stack
{
    private:
	char* stackArray;
	int size;

    public:
	Stack()
	:stackArray(NULL), size(0)
	{
	    stackArray = new char [STACK_CAPACITY];
	}

	void push(char c)
	{
	    if(size < STACK_CAPACITY)
	    {
	    	stackArray[size] = c;
	        size++;
	    }else{
        	cout << "The stack has reached it's maximum capacity!" << endl;
	    }
	}
	
	char pop()
	{
	    if(size > 0)
	    {
		size--;
		return stackArray[size];
	    }else{
		cout << "The stack is empty, cannot pop!" << endl;
	    }
	}

	char top()
	{
	    if(size > 0)
	    {
		return stackArray[size-1];
	    }else{
		cout << "The stack is empty, there is no top!" << endl;
	    }
	}

	bool isEmpty()
	{
	    return size == 0;
	}

	~Stack()
	{
	    delete [] stackArray;
	}
};
