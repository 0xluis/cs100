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
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
vector<string> parse(string input)
{
    string push;
    vector<string> retVector;
    int i;
    for(i=0; i<input.size(); i++)
    {
	if(input[i] != ' ')
	{
	    push+=input[i];
	}
	else
	{
            if(push == "")
	    	continue;
	    retVector.push_back(push);
	    push = "";
	}
    }
    if(push != "")
    	retVector.push_back(push);

    return retVector;
}

int execute (vector<string> vectArgv)
{
    
    int status;
    int pid = fork();
    switch (pid)
    {
    	case -1:
	    cout << "forked up!\n";
	    return -1;
	case 0:
	{
	  //need to conver the vector of strings to array of string pointers
	    const char **argv = new const char* [vectArgv.size()];
	    const char *program = vectArgv[0].c_str();
	    //argv[0] = program;
	    for (int i=0; i<vectArgv.size(); i++)
	    {
		
	    	argv[i] = vectArgv[i].c_str();
	    }
	    argv[vectArgv.size()] = NULL;
	  
	    if(execvp (program, (char **)argv) == -1)
		perror("execvp failed");
	    _exit (1);
	}
	default:
	    int status;
	    return waitpid(-1, &status, 0);
    }
}

int main()
{
    string input;
    vector <string> argv;
    while(true)
    {
	cout << "% ";
	getline(cin, input);
	argv = parse(input);

	if (execute(argv) < 0)
	    perror(argv[0].c_str());

	input = "";
	argv.clear();
    }
}
