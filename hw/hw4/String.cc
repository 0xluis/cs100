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
    ListNode* tmpList = new ListNode(s[0],0);
    head = tmpList;
    int i=0;
    for(; s[i]!='\0'; i++)
    {
        //we already copied the first char.
	if(i==0)
	   continue;
        else
	{
	    tmpList->next = new ListNode(s[i],0);
            
	    tmpList = tmpList->next;
        }
    }
    
    if(i!=0)
        tmpList->next = new ListNode(s[i],0);

}

String::String (const String & s)
{
    //construct da other String
    //NEVER KNOWS BEST
    ListNode * tmpList;
    tmpList = new ListNode(s.head->info, 0);
    head = tmpList;
    //tmpList = tmpList->next;
    ListNode* indexOfS = s.head->next;
    while(indexOfS)
    {
	tmpList->next = new ListNode(indexOfS->info, 0);
	tmpList = tmpList->next;
	indexOfS = indexOfS->next;
    }
}

String String::operator = (const String & s)
{
    if(&s != this)
    {
	//deallocate previous memory
	if(head)
	{
	    ListNode* delThis = head;
	    while(head)
	    {
		head = head->next;
		delete delThis;
                delThis = head;
	    }
	}
	
	ListNode* newList = new ListNode(s.head->info, 0);
	head = newList;
	//newList = newList->next;
	ListNode* index = s.head->next;

	while(index)
	{
	    newList->next = new ListNode(index->info, 0);
	    index = index->next;
	    newList = newList->next;
	}
    }
 
    return *this;
}

char & String::operator [] (const int & index)
{
    if(!inBounds(index))
    {
	cout << "Out of bounds" << endl;
	static char ret;
	ret = '\0';
	return ret;
    }
    
    ListNode* indexPtr = head;
    for(int i=0; indexPtr; i++)
    {
	if(i==index)
	    return indexPtr->info;
        indexPtr=indexPtr->next;
    }

    static char ret;
    ret = '\0';
    return ret;
}

int String::length() const
{
    int len = 0;
    ListNode* index = head;
    while(index)
    {	
	if(index->info != '\0')
	    len++;
	index=index->next;
    }
    return len;
}

int String::indexOf (char c) const
{
    ListNode* index = head;
    int i=0;
    while(index)
    {
	if(c == index->info)
	{
	    return i;
	}
	i++;
	index = index->next;
    }

    return -1;
}

bool String::operator == (const String & s) const
{
    if(length() != s.length())
	return false;

    ListNode* thisIndex = head;
    ListNode* sIndex = s.head;
    //we only need to check one in reality but just incase
    //i dont link stuff ocrreclty which i doubt i didnt
    while(thisIndex && sIndex)
    {
	if(thisIndex->info != sIndex->info)
	    return false;
        thisIndex = thisIndex->next;
	sIndex = sIndex->next;
    }
    return true;
}

//concatentates this and s to return result
String String::operator + (const String & s) const
{
    String strRet(*this);

    ListNode* thisIndex = strRet.head;
    //get to the null char node	

    while(thisIndex->next)
    {
	thisIndex = thisIndex->next;
    }

    delete thisIndex;
    thisIndex = new ListNode(s.head->info, 0);

    ListNode* sIndex = s.head->next;
    //thisIndex = thisIndex->next;
    while(sIndex)
    {
        thisIndex->next = new ListNode(sIndex->info, 0);
	thisIndex = thisIndex->next;
        sIndex = sIndex->next;
    }
    return strRet;
}

//concatenteates s onto the end of this
String String::operator += (const String & s)
{
    //if c+=c if we edit left we edit right....
    //will jsut make a copy of this each time just incase
    String strRet = (*this+s);

    
    //deallocate all data in this
    ListNode* delThis = head;
    while(head)
    {
	head=delThis->next;
        delete delThis;
        delThis = head;
    }

   //reallocate all of the data from the new string to s
 
   ListNode* thisIndex = strRet.head->next;
   head = new ListNode(strRet.head->info, 0);
   ListNode* realThis = head;
   while(thisIndex)
   {
	realThis->next = new ListNode(thisIndex->info, 0);
	realThis = realThis->next;
        thisIndex = thisIndex->next;
   }
    return *this;
}

void String::print (ostream & out)
{
    //go through the list and print each info
    ListNode* index = head;
    while(index)
    {
	out << index->info;
	index=index->next;
    }
}

void String::read (istream & in)
{
    char inputAlloc[10000];
    in.getline(inputAlloc,10000);
    int len = 0;
    //get the length of the new input
    for(int i=0; inputAlloc[i] != '\0'; i++, len++);

    //deallocate the mem in use
    ListNode* delThis = head;
    while(head)
    {
        head=head->next;
        delete delThis;
        delThis = head;
    }
    
    ListNode* index;
    for(int i=0; i<len; i++)
    {
	if(i==0)
	{
	    head = new ListNode(inputAlloc[i],0);
            index = head;
	}
        else
        {
	    index->next = new ListNode(inputAlloc[i],0);
            index=index->next;
        }
    }
    index = new ListNode('\0', 0);
}

String::~String()
{
    ListNode* delThis = head;
    while(head)
    {
	head=head->next;
        delete delThis;
        delThis = head;
    }
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

