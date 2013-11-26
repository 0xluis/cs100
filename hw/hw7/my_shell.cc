/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW6
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

string get_path(string);
vector<string> strToVect(string);
int execute(string);
void pipeExecute(list<string>);
list<string> splitPipes(string);
void parsePipes(list<string>);
string findFilePath(vector<string>, string);
string get_path(string);

void int_handler(int param)
{
    
    cout << endl << flush;
}

int main()
{
    string input;
    list<string> listCommands;
    if(signal(SIGINT, int_handler)== SIG_ERR)
    {
	perror("Signal was not successful");
    }
   
    while(cin.good())
    {
	cout  << "% ";
	getline(cin, input);
        listCommands = splitPipes(input);
	parsePipes(listCommands);
	input = "";
	cout.clear();
    }
}

//convert a line of strings into seperate
//vector indexes ie "hello world" is vect[0] = hello vect[1]=world
vector<string> strToVect(string input)
{
    vector<string> words;
    string toPush;
    stringstream ss(input);
    while(ss>>toPush)
	words.push_back(toPush);
    return words;
}

//executes the command by forking and calling execv
//argument is the line enterd by user eg: ls ../
int execute(list<string> listCommands)
{
    //the amount of commands, pipes and pipefiledescriptors
    int commands = listCommands.size(), pipes = commands-1, pipefds[2*pipes];
    //used for loops inside of the child when forked
    //warnings were given when declared inside of the children when i was using
    //switch statements also used k outside of its loop
    int q, k, pid;

    bool bg = false;
    if(listCommands.back().find("&") != -1)
	bg = true;

    //set up the required pipes with a for loop
    for(int i=0; i<pipes; i++)
        if(pipe(pipefds+i*2) < 0)
        {
	    perror("couldnt pipe");
	    exit(1);
        }

    //loop through the list of commands
    for(int i=0, j=0; i<commands; i++, j+=2)
    {
        //convert the string into vector of strings
        vector<string> words = strToVect(listCommands.front());
        listCommands.pop_front();
        //size of the vector is the size of the argvs
        const char **argv = new const char* [words.size()];
        //take the first argument ie the command name
        //and call get path to search PATH for the file
        const char *program = get_path(words[0]).c_str();
	//string used to find a < > or &
        string token;
        pid = fork();
        
	//if child process then set up the pipes by replacing the
	//stdout (using i) and stdin (using j incremented plus 2 each itteration)
        if(pid == 0)
        {
	    if(i<pipes)
		if(dup2(pipefds[j+1],1) < 0)
		{
		    perror("dup2 failed");
		    exit(1);
		}
	    if(j!=0)
	    {
		if(dup2(pipefds[j-2], 0) < 0)
		{
		    perror("dup2 failed");
		    exit(1);
		}
	    }

	    //close the fds
	    for(q=0; q<2*pipes; q++)
	    {
		close(pipefds[q]);
	    }

	    //SETS UP ARGV for exec and gets rid of < > &
	    //loop through vector for each argument
	    for(k=0; k<words.size(); k++)
	    {
		//if the string is not a io token add it to argv
		if(words[k] != ">" && words[k] != "<")
		    argv[k] = words[k].c_str();
		else
		{
                    //if the string is a token for i/o set string token
		    //to the < or >
		    token = words[k];
		    //if we are at the last index eg echo hello >
		    //error a input or output file must be defined
		    if(k+1 == words.size())
		    {
			cerr << "Error expected file name!\n";
			exit(1);
		    }else{
			//if it is not the last index open the next index for
			//input/output
		        if(token == ">")
			{
			    int output;
			    output = open(words[k+1].c_str(), O_WRONLY
					 | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
			    dup2(output, 1);
			    close(output);

			}else if(token == "<"){
			    int input;
			    if((input = open(words[k+1].c_str(), O_RDONLY)) < 0)
		            {
				cerr << "No such file: " << words[k+1] << endl;
				exit(1);
			    }
			    dup2(input, 0);
			    close(input);

			}
		    }
		    //set the space for the token argument to null
		    argv[k] = NULL;
		}
	    }
	    //end argv with null so that it is execv friendly
	    argv[k++] = NULL;
	    
            //execute program
	    if(execv(program, (char**)argv) == -1)
	    {
	    	perror("execv failed");
	        exit(1);
	    }

        }//end of if(pid == 0) *child*
	
	else if(pid <0)//we errored when we forked
	{
	    perror("error");
	    exit(1);
        }

    }//loop if we have more commands to pipe
    
    //parent closes fds
    for(q=0; q<2*pipes; q++)
    {
	close(pipefds[q]);
    }

    //waits for every child to finish unless a & was found
    if(!bg)
    for(int i=0; i<pipes+1; i++)
    {
	wait(NULL);
    }

    return 0;
}


//split the commands by | into list
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
    //user typed in exit quit the shell
    if(listCommands.front() == "exit")
	exit(0);
    //if no command ie user just hit enter dont exec anything
    if(listCommands.front() != "")
    {
        execute(listCommands);
    }
}

//find the path for a program by looking at PATH
string findFilePath(vector<string> paths, string program)
{
    int tryOpen;
    string programPath;
    //loop through all possible paths
    for(int i=0; i<paths.size(); i++)
    {
	//for some reason on well path has /usr/bin/
	//instead of /usr/bin if a directory has / at the end dont append
        if(paths.at(i).at(paths.at(i).size()-1) == '/')
            programPath = paths.at(i) + program;
	else
	    programPath = paths.at(i)+"/"+program;

	//cout << programPath << endl;
        
        //check by trying to open a file descriptor if it fails
	//the file does not exit in that directory
	tryOpen = open(programPath.c_str(), O_RDONLY);
	if(tryOpen > 0)
	{
	    close(tryOpen);
	    return programPath;
	}
    }

    cout << "Program not found under $PATH!\n";
    return "";
}

string get_path(string program)
{
    //set up a vector of strings with all possible paths
    vector<string> toReturn;
    string path = getenv("PATH");
    while(path.find(':') != -1)
    {
	toReturn.push_back(path.substr(0,path.find(':')));
	path = path.substr(path.find(':')+1);
    }
    
    toReturn.push_back(path);
    
    //search for the file in all the possible paths
    return findFilePath(toReturn, program);
}
