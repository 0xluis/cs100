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
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

const int PRINTNUM = 10000;

using namespace std;

void child_work_print(char a)
{
    for(int i=0; i<PRINTNUM; i++)
    {
	cout << a << flush;
    }
}

int main()
{  
    //pid_t pID;
    switch(pid_t pid = fork())
    {
	case -1: perror ("forked up"), exit(1);
	case 0: cout << "Child 0: " << getpid() << endl;
                child_work_print('b'); 
                exit(0);
        default: break;
    }

    switch(pid_t pid = fork())
    {
	case -1: perror ("forked up"), exit(1);
	case 0: cout << "Child 1: " << getpid() << endl;
                child_work_print('c');
                exit(0);
        default: break;
    }

    switch(pid_t pid = fork())
    {
	case -1: perror ("forked up"), exit(1);
	case 0: cout << "Child 2: " << getpid() << endl;
                child_work_print('d');
		exit(0);
        default:
		child_work_print('a');
		//wait for all the children
		wait(NULL);
		wait(NULL);
		wait(NULL);
		exit(0);
    }

    return 0;
}
