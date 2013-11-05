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
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Timer.h"
using namespace std;


void copyInToOut(string input, string output);
void unixInToOut(string input, string output);
void unixBuff(string input, string output);

int main(int argc, char * argv[])
{
   if(argc < 4)
	cout << "Usage: ./a.out reading_file "
	     << "writing_file number_of_times" << endl;
   else
   {
	Timer t;
        double eTime1, eTime2, eTime3;
	int N=atoi(argv[3]);
        t.start();
        for(int i=0; i<N; i++)
	{
	    copyInToOut(argv[1], argv[2]);
	}
	t.elapsedTime(eTime1, eTime2, eTime3);
        cout << "C++ i/o" << endl;
	cout << "Wallclock: " << eTime1 << endl;
	cout << "Usertime: " << eTime2 << endl;
	cout << "Systemtime: " << eTime3 << endl << endl;

	Timer t2;
	t2.start();
        for(int i=0; i<N; i++)
	{
	    unixInToOut(argv[1], argv[2]);
	}
        t2.elapsedTime(eTime1, eTime2, eTime3);
        cout << "unix i/o (1 char): " << endl;
	cout << "Wallclock: " << eTime1 << endl;
	cout << "Usertime: " << eTime2 << endl;
	cout << "Systemtime: " << eTime3 << endl << endl;

        
	Timer t3;
	t3.start();
        for(int i=0; i<N; i++)
	{
	    unixBuff(argv[1], argv[2]);
	}
        t3.elapsedTime(eTime1, eTime2, eTime3);
        cout << "unix i/o (bufsiz): " << endl;
	cout << "Wallclock: " << eTime1 << endl;
	cout << "Usertime: " << eTime2 << endl;
	cout << "Systemtime: " << eTime3 << endl << endl;

   }
}

void copyInToOut(string input, string output)
{
    char single;
    ifstream inputFile(input.c_str());
    ofstream outputFile(output.c_str());

    while(inputFile.good() && inputFile.peek()!=EOF)
    {
	inputFile.get(single);
        outputFile.put(single);
    }
    
    inputFile.close();
    outputFile.close();
}

void unixInToOut(string input, string output)
{
   int inDescriptor = open(input.c_str(), O_RDONLY);
   int outDescriptor = open(output.c_str(), O_WRONLY | O_TRUNC | O_CREAT,
                             S_IRUSR|S_IWUSR);
   
   char* charBuf;

   while(read(inDescriptor, charBuf, sizeof(char)) != 0)
   {
        write(outDescriptor, charBuf, sizeof(char));
   }

   close(inDescriptor);
   close(outDescriptor);
  
}

void unixBuff(string input, string output)
{
   int inDescriptor = open(input.c_str(), O_RDONLY);
   int outDescriptor = open(output.c_str(), O_WRONLY | O_TRUNC | O_CREAT,
                             S_IRUSR|S_IWUSR);
   int test;
   char charBuf[BUFSIZ];

   while(test = read(inDescriptor, charBuf, sizeof(BUFSIZ)))
   {
        if(test < sizeof(BUFSIZ))
	{
            
            write(outDescriptor, charBuf, test);    
 	}
        else
        write(outDescriptor, charBuf, sizeof(BUFSIZ));
   }

   close(inDescriptor);
   close(outDescriptor);
  
}
