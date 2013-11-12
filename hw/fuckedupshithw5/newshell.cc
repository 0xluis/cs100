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
#include <cstring>

using namespace std;
int input(char ** argv)
{
    int argc = 0;
    string arg, toPush;
     char *cstr;

  // Read in arguments till the user hits enter
  while (cin >> arg) {

    // Convert that std::string into a C string.
    cstr = new char[arg.size()+1];
    strcpy(cstr, arg.c_str());
    argv[argc] = cstr;

    // Increment our counter of where we're at in the array of arguments.
    argc++;

    // If the user hit enter, stop reading input.
    if (cin.get() == '\n')
      break;
  }

  // Have to have the last argument be NULL so that execvp works.
  argv[argc] = NULL;
 
  // Return the number of arguments we got.
  return argc;
}

int execCmd(char **args, int pipes)
{
    // The number of commands to run
    const int commands = pipes + 1;
    int i = 0;

    int pipefds[2*pipes];

    for(i = 0; i < pipes; i++){
        if(pipe(pipefds + i*2) < 0) {
            perror("Couldn't Pipe");
            exit(EXIT_FAILURE);
        }
    }

    int pid;

    int j = 0;
    int k = 0;
    int s = 1;
    int inS = 1;
    int place;
    int commandStarts[10];
    int inR[10];
    int outR[10];
    commandStarts[0] = 0;
    inR[0] = 0;

    // This loop sets all of the pipes to NULL
    
// And creates an array of where the next
    // Command starts

    while (args[k] != NULL){
        if(!strcmp(args[k], "|")){
            args[k] = NULL;
            // printf("args[%d] is now NULL", k);
            commandStarts[s] = k+1;
            s++;
        }
        if(!strcmp(args[k], ">"))
	{
	    inR[inS] = k+1;
            inS++;
	}
        k++;
    }



    for (i = 0; i < commands; ++i) {
        // place is where in args the program should
        // start running when it gets to the execution
        // command
        place = commandStarts[i];

        pid = fork();
        if(pid == 0) {
            //if not last command
            if(i < pipes){
                if(dup2(pipefds[j + 1], 1) < 0){
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            //if not first command&& j!= 2*pipes
            if(j != 0 ){
                if(dup2(pipefds[j-2], 0) < 0){
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            int q;
            for(q = 0; q < 2*pipes; q++){
                    close(pipefds[q]);
            }

            // The commands are executed here, 
            // but it must be doing it a bit wrong          
            if( execvp(args[place], args + place) < 0 ){
                    perror(*args);
                    exit(EXIT_FAILURE);
            }
        }
        else if(pid < 0){
            perror("error");
            exit(EXIT_FAILURE);
        }

        j+=2;
    }

    for(i = 0; i < 2 * pipes; i++){
        close(pipefds[i]);
    }

    for(i = 0; i < pipes + 1; i++){
        wait(NULL);
    }
} 

void parseExec (int argc, char** argv)//, char** left, char** right)
{
    int pipe=0;
    for(int i=0; i<argc; i++)
    {
	if(string(argv[i]) == "|")
	{
	    pipe++;
	}
    }
    execCmd(argv, pipe);

}

int main()
{
    //the input from user
    char*argv [999];
    //if we need to pipe these will serve as the left and right side of the pipe
//    char*left [999];
//    char*right [999];
    int argc = 0;
    while(true)
    {
	cout << "% ";
        argc = input(argv);
	parseExec(argc, argv);
        
        //clear array
	for(int i=0; i<argc; i++)
	{
	    argv[i] = NULL;
	}
    }

}
