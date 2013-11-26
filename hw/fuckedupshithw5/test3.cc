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















int execute(string input)
{
    //convert the string into vector of strings
    vector<string> words = strToVect(input);
    //size of the vector is the size of the argvs
    const char **argv = new const char* [words.size()];
    //take the first argument ie the command name
    //and call get path to search PATH for the file
    const char *program = get_path(words[0]).c_str();
    int i, status, pid = fork();
    string token;
    
    switch(pid)
    {
        case -1:
            cout << "Forked up!\n";
            return -1;
        case 0:
            //loop through vector for each argument
            for(i=0; i<words.size(); i++)
            {
                //if the string is not a io token add it to argv
                if(words[i] != ">" && words[i] != "<")
                    argv[i] = words[i].c_str();
                else
                {
                    //if the string is a token for i/o set string token
                    //to the < or >

	            token = words[i];
                    //if we are at the last index eg echo hello >
                    //error a input or output file must be defined
                    if(i+1 == words.size())
                    {
                        cerr << "Error expected file name!\n";
                        exit(1);
                    }else{
                        //if it is not the last index open the next index for
                        //input/output
                        if(token == ">")
                        {
                            int output;
                            output = open(words[i+1].c_str(), O_WRONLY
                                         | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
                            dup2(output, 1);
                            close(output);
                        }else{
                            int input;
                            if((input = open(words[i+1].c_str(), O_RDONLY)) < 0)
                            {
                                cerr << "No such file: " << words[i+1] << endl;
                                exit(1);
                            }
                            dup2(input, 0);
                            close(input);
                        }
                    }
                    //set the space for the "<" argument to null
                    argv[i] = NULL;
                }
            }
            //end argv with null so that it is execv friendly
            argv[i++] = NULL;
            //execute
            if(execv(program, (char**)argv) == -1)
                perror("execv failed");
            exit(1);

        default:
             return waitpid(pid, &status, 0);
    }
}





int execCmd(char **args, int pipes)
{
    // The number of commands to run
    const int commands = pipes + 1;
    int pipefds[2*pipes];

    //open nessacry ammount of pipes
    for(int i = 0; i < pipes; i++){
        if(pipe(pipefds + i*2) < 0) {
            perror("Couldn't Pipe");
            exit(EXIT_FAILURE);
        }
    }

    int pid;

    int k = 0;
    int s = 1;
    int inS = 1;
    int place;
    int commandStarts[10];
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
        k++;
    }



    for (int i = 0, j=0; i < commands; i++, j+=2) {
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
	    string a = args;
            execute(a)
            }
        }
        else if(pid < 0){
            perror("error");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < 2 * pipes; i++){
        close(pipefds[i]);
    }

    for(int i = 0; i < pipes + 1; i++){
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
