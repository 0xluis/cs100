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

//im putting my commands into a vector
//so read in the linea and vectorize
vector<string> vectorize(string input)
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
    const char **argv = new const char* [vectArgv.size()];
    const char *program = vectArgv[0].c_str();
    int i;
    string token;
    vector<string> commands;
    int pipefd[2];
    switch (pid)
    {
    	case -1:
	    cout << "forked up!\n";
	    return -1;
	case 0:
//	{
	  //need to conver the vector of strings to array of string pointers
	    //string token;
	   // const char **argv = new const char* [vectArgv.size()];
	   // const char *program = vectArgv[0].c_str();
	    //argv[0] = program;
	   // int i;
//	    vector<string> commands;
	    for (i=0; i<vectArgv.size() && vectArgv[i]!="|"; i++)
	    {
		if(vectArgv[i] != ">" && vectArgv[i] != "<") //&& vectArgv[i] != "|")
		{
      	    	    argv[i] = vectArgv[i].c_str();
		}
		else
		{
		    token = vectArgv[i];
		    if(i+1 == vectArgv.size())
		    {
			//if(token != "|")
  			    cerr << "Error expected file namae!\n";
			//else
			  //  cerr << "Open pipe!\n";
			_exit(1);
		    }else{
		    	if(token == ">")
			{
		    	    int output;
		    	    output = open(vectArgv[i+1].c_str(), O_WRONLY 
				           | O_TRUNC | O_CREAT, S_IRUSR|S_IWUSR);
			    dup2(output, 1);
			    close(output);
		    	}else{
			    int input;
			    input = open(vectArgv[i+1].c_str(), O_RDONLY);
			    dup2(input,0);
			    close(input);
			}
		        /*if(token == "|")
			{
			    argv[i] = NULL;
			    pipe(pipefd);
		            int pid2 = fork();
			    if(pid2<0) exit(1);
			    if(pid2>0)
			    {
				close(pipefd[1]);
			    }
			    else
			    {
			  	close(pipefd[0]);
			    }
			}*/
		    }
		    argv[i] = NULL;
		}	
	    }
	    argv[i++] = NULL;
            if(argv[i-1] == "|")
	    {
		cerr << "PIPESHIT";
	    }
	
	    
	  
	    if(execvp (program, (char **)argv) == -1)
		perror("execvp failed");

	    
	    exit (1);
//	}
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
	argv = vectorize(input);
	
	for(int i=0; i<argv.size(); i++)
	{
	    cout << argv[i] << " " << i << endl;
	}
	
	if (execute(argv) < 0)
	    perror(argv[0].c_str());

	input = "";
	argv.clear();
    }
}
