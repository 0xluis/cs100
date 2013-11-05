/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW3
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include <iostream>
#include "String.h"

using namespace std;

String::String (const char * s)
{

    //obtain the length
    len = 0;
    for (; s[len]!='\0'; len++)
	continue;
    
    //create the new array
    buf = new char[len+1];
    for (int i=0; i < len; i++)
	buf[i] = s[i];

    //dont forget the null terminating char
    buf[len+1] = '\0';
}

String::String (const String & s)
{
    //obtain length
    len = s.len;
    
    //create new array
    buf = new char[len+1];
    for (int i=0; i < len; i++)
	buf[i] = s.buf[i];

    //dont forget null terminating char
    buf[len+1] = '\0';
}

String String::operator = (const String & s)
{
    //get rid of old mem
    delete [] buf;
    //set new length/array
    len = s.len;
    buf = new char[len+1];
    //initialize the data
    for(int i=0; i<len+1; i++)
    {
	buf[i] = s.buf[i];
    }

    return *this;
}

char & String::operator [] (int index)
{
    if(inBounds(index))
    {
	return buf[index];
    }else{
	cout << "Error: out of bounds!" << endl;
	//we dont want to return the null in the
	//string or we can allow the main to edit the
	//null terminating character
	static char nulterm;
	nulterm = 0;
	return nulterm;
    }
}

int String::size()
{
    return len;
}

String String::reverse()
{
    //create new string to return witht eh same
    //size as this
    String StringToReturn(buf);
    //loop in reverse from this and foward on StrinTOreturn
    for(int i=len-1, k=0; i>=0; i--, k++)
    {
	StringToReturn.buf[k] = buf[i];
    }
  
    return StringToReturn;
}

int String::indexOf (char c)
{
    //loop and fine char return index if found -1 if not
    for(int i=0; i<len; i++)
    {
	if(c == buf[i])
	{
	    return i;
	}
    }
    return -1;
}

bool String::operator == (String s)
{
    //if not same leangth return false
    if(len != s.len)
    	return false;

    //loop and check each cahr if not the smae reutnr false
    for(int i=0; i<len; i++)
	if(buf[i] != s.buf[i])
    	    return false;
    
    return true;
}

bool String::operator != (String s)
{
    //lazy just check fi they are equal and reurn the oppisite of that
    //ie if the equal function returns false that means
    //they werent equal so we just not that and voila != function
    return !(*this == s);
}

bool String::operator > (String s)
{
    if(len > s.len)
	return true;

    else if(len < s.len)
	return false;

    else
    {
        //is equal??
        bool equal = true;
        

	for(int i=0; i<len; i++)
        {
	    if(buf[i] < s.buf[i])
	    	return false;
            if(buf[i] != s.buf[i])
		equal = false;
        }
       
        return !equal;
    }
}

bool String::operator < (String s)
{
    //smaller length therfore smaller
    if(len < s.len)
	return true;
    //bigger length therefore bigger
    else if(len > s.len)
	return false;
    
    else
    {
    	//is equal??
        //equal lentghs 3 posible outcomes
        //they are equal or s is bigger or s is smaller
        bool equal = true;
        
        for(int i=0; i<len; i++)
	{
           //check if we are greater if so return false
	    if(buf[i] > s.buf[i])
		return false;
            //we havent ran into a greater chekc if we have
            //a differnt char if so update flag
	    if(buf[i] != s.buf[i])
		equal = false;
	}
	//outcome depends on wether we determined if string is equal
	return !equal;
     }
}

bool String::operator <= (String s)
{
    //greater than s
    if(len > s.len)
	return false;
    //smaller than s
    else if(len < s.len)
	return true;
    //same size so lets just check if we run
    //into a char > char at x index
    else
	for(int i=0; i<len; i++)
	    if(buf[i] > s.buf[i])
	    	return false;

    //we didnt run intoa  char > x at any point
    //ie all chars are either < or =
    return true;
}

bool String::operator >= (String s)
{
    //smaller size so s is bigger
    if(len < s.len)
	return false;
    //greater size so this is > s
    if(len > s.len)
	return true;
    //same size so lets just check if we
    //ever run into a < char at x index
    else
	for(int i=0; i<len; i++)
	    if(buf[i] < s.buf[i])
		return false;
    //if not we are either equal or greater than
    return true;
}

//concatentates this and s to return result
String String::operator + (String s)
{
    //new string
    String newStrToRtn;
    //length is both added
    newStrToRtn.len = len + s.len;
    //delete the null char
    delete [] newStrToRtn.buf;
    //allocate new memory
    newStrToRtn.buf = new char[len+1];

    //lets loop through this
    int i=0;
    for(; i<len; i++)
	newStrToRtn.buf[i]=buf[i];

    //loop through s
    for(int j=0; j<s.len; j++, i++)
	newStrToRtn.buf[i] = s.buf[j];

    //insert null terminating char
    newStrToRtn.buf[newStrToRtn.len + 1] = '\0';
    
    return newStrToRtn;
}

//concatenteates s onto the end of this
String String::operator += (String s)
{
    //create new length
    len = len + s.len;
    //hold the old s char array
    char* temp = buf;
    //allocate memory for both
    buf = new char[len+1];
    
    //loop through this
    int i=0;
    for(; i<len-s.len; i++)
    {
	buf[i] = temp[i];
    }

    //loop thorugh s
    for(int j=0; j<s.len; j++, i++)
    {
	buf[i] = s.buf[j];
    }

    //create null char
    buf[len+1] = '\0';

    delete temp;

    
    return *this;
    
}

void String::print (ostream & out)
{
    //simple go through array and print add a space to make it
    //look nicer
    for(int i=0; i<len; i++)
	out << buf[i];
}

void String::read (istream & in)
{ 
    //we need somewhere to store the stream input
    //doing it directly to buf is quite nasty and
    //requires more work/hacks
    char streamArray[9999];
    in >> streamArray;
    len = 0;
    //get the actual length of this new input
    for(int i=0; streamArray[i] != '\0'; i++)
	len++;

    //deallocate the mem in use
    delete [] buf;
    //allocate new mem
    buf = new char[len+1];
    //loop again through the input array to actually insert
    //the chars into the String class
    for (int i=0; i<len; i++)
	buf[i] = streamArray[i];

    //add the null ;)
    buf[len+1] = '\0';
}

String::~String()
{
    //deallocate mem
    delete [] buf;
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
