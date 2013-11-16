/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW5
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include <iostream>
#include <list>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> strToVect(string input)
{
    vector<string> words;
    string toPush;
    stringstream ss(input);
    while(ss>>toPush)
	words.push_back(toPush);
    return words;
}

int execute(string input)
{
    vector<string> words = strToVect(input);
    const char **argv = new const char* [words.size()];
    const char *program = words[0].c_str();
    int i;
    int status;
    string token;
    int pid = fork();
    
    switch(pid)
    {
	case -1:
	    cout << "Forked up!\n";
	    return -1;
	case 0:
	    for(i=0; i<words.size(); i++)
	    {
		if(words[i] != ">" && words[i] != "<")
		    argv[i] = words[i].c_str();
		else
		{
		    token = words[i];
		    if(i+1 == words.size())
		    {
			cerr << "Error expected file name!\n";
			exit(1);
		    }else{

		        if(token == ">")
			{
			    int output;
			    output = open(words[i+1].c_str(), O_WRONLY
					 | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
			    dup2(output, 1);
			    close(output);
			}else{
			    int input;
			    input = open(words[i+1].c_str(), O_RDONLY);
			    dup2(input, 0);
			    close(input);
			}
		    }
		    argv[i] = NULL;
		}
	    }
	    argv[i++] = NULL;
	    if(execvp(program, (char**)argv) == -1)
	    	perror("execvp failed");
	    exit(1);

    	default:
	     return waitpid(pid, &status, 0);
    }
}

int pipeExecute(list<string> listCommands)
{
    
}

list<string> splitPipes(string input)
{
    string strToPush;
    list<string> listToReturn;

    for(int i=0; i<input.size(); i++)
    {
	if(input[i] != '|')
	{
	   strToPush+=input[i]; 
	}
	else
	{
	   listToReturn.push_back(strToPush);
	   strToPush = ""; 
	}
    }

    listToReturn.push_back(strToPush);
    return listToReturn;
}

void parsePipes(list<string> listCommands)
{
    //no pipes needed just run the commands
    if(listCommands.size() == 1)
    {
	execute(listCommands.front());
    }
    //we have pipes
    else
    {
	pipeExecute(listCommands);
    }
}

int main()
{
    string input;
    list<string> listCommands;
    while(true)
    {
	cout << "~badshell% ";
	//paht enviroment
	//cout << getenv("PATH");
	getline(cin, input);
        listCommands = splitPipes(input);   
	parsePipes(listCommands);
	input = "";
    }
}
