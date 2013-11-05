#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
    //Create a stack
    Stack stackOfChars;

    string input;
    //get input from user repeatedly until ^D input
    cout << "Press enter to push into stack, ^D to end\n";
    while(cin >> input)
    {     
    	//once the user stops entering a string "enter"
    	//push back the  chars into a stack
    	for(int i=0; i<input.size(); i++)
    	{
	    stackOfChars.push(input.at(i));
    	}
    }
    
    //cout << endl;
    //print the characters in reverse order
    while(!stackOfChars.isEmpty())
    {
	cout << stackOfChars.pop();
    }
    
    cout << endl;
}
