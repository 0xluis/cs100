/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW4
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#ifndef STRING_CLASSH
#define STRING_CLASSH
#include <iostream>
using namespace std;

class String
{
    public:
	//both constructors should construct
	//this strong fromt he paramater s
	String (const char * s = "");
	String (const String & s);
	String operator = (const String & s);
	char & operator [] (const int & index);
	int length() const;
	int indexOf (char c) const;
	bool operator == (const String & s) const;
	//concatentates this and s to return result
	String operator + (const String & s) const;
	//concatenteates s onto the end of this
	String operator += (const String & s);
	void print (ostream & out);
	void read (istream & in);
	~String();
    private:
	bool inBounds (int i)
	{
	    return i >= 0 && i < length();
	}
	struct ListNode
	{
	    char info;
	    ListNode* next;
	    ListNode(char newInfo, ListNode * newNext)
	    :info(newInfo), next(newNext)
	    {
     //          cout << "Node with char " << info  << " created " << endl;
	    }
            //you may add static methods here
	};
	ListNode * head;
};

ostream & operator << (ostream & out, String str);
istream & operator >> (istream & in, String & str);

#endif
