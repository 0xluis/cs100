/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW2
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include <iostream>
#include <list>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

using namespace std;

void recursiveLS(string directory, int tab = 0);

int main(int argc, char* argv[])
{
    int argument = 1;
    if(argc > 1)
    {
    	for(int i = 1; i < argc; i++)
        {
			recursiveLS(argv[i]);
        }
    }
    else
        recursiveLS(".");
}

void recursiveLS(string directory, int tab)
{
    //we will be using deque nvm list instead becuase they have a sort
    //to keep track of files and subdirectories
    list<string> filesDq;
	
    DIR* dir = opendir(directory.c_str());
    dirent *direntp;
    string files;
    while(direntp = readdir(dir))
    {
        files = direntp->d_name;
	//we dont want push back ourselves or the folder we
	//entered from
        if(files != "." && files != "..")
		{
	    //everything is a file!
    	    filesDq.push_back(files);
		}
    }

	filesDq.sort();
    closedir(dir);
    
    //we have to check if this just a regular file if so we print it out
	//as such
    if(!dir)
    {
	struct stat fileInfo;
	if(lstat(directory.c_str(), &fileInfo) == 0)
	{
	    string permissions;
	    if(fileInfo.st_mode & S_IRUSR)
		permissions += "r";
	    else
		permissions += "-";
            if(fileInfo.st_mode & S_IWUSR)
		permissions += "w";
	    else
		permissions += "-";
	    if(fileInfo.st_mode & S_IXUSR)
		permissions += "x";
	    else
		permissions += "-";
	    if(fileInfo.st_mode & S_IRGRP)
		permissions += "r";
	    else
		permissions += "-";
	    if(fileInfo.st_mode & S_IWGRP)
		permissions += "w";
	    else
		permissions += "-";
	    if(fileInfo.st_mode & S_IXGRP)
		permissions += "x";
	    else
		permissions += "-";
	    if(fileInfo.st_mode & S_IROTH)
		permissions += "r";
	    else
		permissions += "-";
	    if(fileInfo.st_mode & S_IWOTH)
		permissions += "w";
	    else
		permissions += "-";
	    if(fileInfo.st_mode & S_IXOTH)
		permissions += "x";
	    else
		permissions += "-";

	    //we need to convert the time according to stat(2)
	    //requires localtime
	    struct tm * correctedTime;
	    char charTime[999];
	    correctedTime = localtime(&fileInfo.st_mtime);
	    strftime(charTime, 999, "%b %d %H:%M",correctedTime);
	    cout <<  permissions << " " << fileInfo.st_nlink << " " 
                 << fileInfo.st_size << " " << charTime << " " 
                 << directory << endl;
            return;
	}else{	
	    cout << "Error could not open " << directory << endl;
            return;
	}
    }

   
    
    for(list<string>::iterator i = filesDq.begin(); i!=filesDq.end(); ++i)
    {
	string currentFile = directory + "/" + *i;
	struct stat fileInfo;
	if(lstat(currentFile.c_str(), &fileInfo) == 0)
	{
	    string permissions;
	    if(S_ISDIR(fileInfo.st_mode))
    	     {
		for(int k=0; k<tab; k++)
		    cout << "\t";
		cout << *i << endl;
		recursiveLS(currentFile, ++tab);
		tab--;
	     }else{

	     if(fileInfo.st_mode & S_IRUSR)
		permissions += "r";
	     else
		permissions += "-";
             if(fileInfo.st_mode & S_IWUSR)
		permissions += "w";
	     else
		permissions += "-";
	     if(fileInfo.st_mode & S_IXUSR)
		permissions += "x";
	     else
		permissions += "-";
	     if(fileInfo.st_mode & S_IRGRP)
		permissions += "r";
	     else
		permissions += "-";
	     if(fileInfo.st_mode & S_IWGRP)
		permissions += "w";
	     else
		permissions += "-";
	     if(fileInfo.st_mode & S_IXGRP)
		permissions += "x";
	     else
		permissions += "-";
	     if(fileInfo.st_mode & S_IROTH)
		permissions += "r";
	     else
		permissions += "-";
	     if(fileInfo.st_mode & S_IWOTH)
		permissions += "w";
	     else
		permissions += "-";
	     if(fileInfo.st_mode & S_IXOTH)
		permissions += "x";
	     else
		permissions += "-";


	     //we need to convert the time according to stat(2)
	     //requires localtime
	     struct tm * correctedTime;
	     char charTime[999];
	     correctedTime = localtime(&fileInfo.st_mtime);
	     strftime(charTime, 999, "%b %d %H:%M",correctedTime);
	     for(int k = 0; k < tab; k++)
		cout << "\t";
	     cout <<  permissions << " " << fileInfo.st_nlink << " "
		  << fileInfo.st_size << " " << charTime << " " << *i << endl;
	    }

	}
    }
}
