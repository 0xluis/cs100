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
#include <iostream>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
//keep track of how many calls
int I=0, Q=0, S=0;

void sigI_handler(int signalNum);
void sigQ_handler(int signalNum);
void sigS_handler(int signalNum);

void init_signal_handlers();

int main()
{
    //init the handlers
    init_signal_handlers();
    while(1)
	cout << "X" << flush;
}

void init_signal_handlers()
{
    //call handlers
    signal(SIGINT, sigI_handler);
    signal(SIGQUIT, sigQ_handler);
    signal(SIGTSTP, sigS_handler);
}

void sigI_handler(int signalNum)
{
    cout << "I" << flush;
    I++;
}

void sigQ_handler(int signalNum)
{
    cout << "Q" << flush;
    Q++;
}

void sigS_handler(int signalNum)
{
    if(S==2)
    {
	cout << endl << "Interrupt: " << I 
             << endl << "Stop: " << S
             << endl << "Quit: " << Q << endl;
        exit(0);
    }

    cout << "S" << flush;
    S++;

    kill(getpid(), SIGSTOP);
}
