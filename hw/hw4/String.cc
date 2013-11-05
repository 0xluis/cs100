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
#include "String.h"
#include <iostream>
using namespace std;

//both constructors should construct
//this strong fromt he paramater s
String::String (const char * s)
:head(0)
{

    //construct the head
    head = new ListNode(s[0], 0);
    ListNode* index = head->next;
    for(int i=0; s[i] != '\0'; i++)
    {
        //we already copied the first char.
	if(i==0)
	   continue;
        else
	{
	    index = new ListNode(s[i],0);
	    index = index->next;
        }
    }

}

String::String (const String & s)
{
    //construct da other String
    //NEVER KNOWS BEST
    ListNode * indexOfS = s.head;
    ListNode * indexOfThis;
    head = new ListNode(indexOfS->info, 0);
    indexOfThis = head->next;
    indexOfS = indexOfS->next;
    while(indexOfS != NULL)
    {
	indexOfThis = new ListNode(indexOfS->info, 0);
	indexOfThis = indexOfThis->next;
	indexOfS = indexOfS->next;
    }
}

String String::operator = (const String & s)
{
}

char & String::operator [] (int index)
{
}

int String::length() const
{
    int len = 0;
    ListNode* index = head;
    while(index != NULL)
    {	
	len++;
	index=index->next;
    }
    return len;
}

int String::indexOf (char c) const
{
}

bool String::operator == (String s) const
{
}

//concatentates this and s to return result
String String::operator + (String s) const
{
}

//concatenteates s onto the end of this
String String::operator += (String s)
{
}

void String::print (ostream & out)
{
    //go through the list and print each info
    ListNode* index = head;
    while(index!=NULL)
    {
	out << index->info;
	index=index->next;
    }
}

void String::read (istream & in)
{
}

String::~String()
{
}

ostream & operator << (ostream & out, String str)
{
    str.print(out);
    return out;
}
istream & operator >> (istream & in, String & str)
{
    str.read(in);
    return in;
}

