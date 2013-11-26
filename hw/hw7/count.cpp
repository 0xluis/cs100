#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

map<string,int> make_map(vector<string>, set<string>);
void print(map<string,int>);

int main(int argc, char* argv[])
{
    //if not being used correctly inform user
    if(argc != 3)
    {
	cerr << "Usage: " << argv[0] << " InputFile ExclusionFile\n";
	return 1;
    }

    string toPush, count;
    vector<string> Input;
    ifstream inputFile, ExclusionFile;

    //read input file to a vector of strings
    //and a count string (easier to look for repeats)
    inputFile.open(argv[1]);
    while(inputFile >> toPush)
    {
	Input.push_back(toPush);
    }
    inputFile.close();

    //get the exclusion list and put it into a string
    ExclusionFile.open(argv[2]);
    set<string> excludeThese;
    while(ExclusionFile >> toPush)
    {
	excludeThese.insert(toPush);
    }
    ExclusionFile.close();

    print(make_map(Input, excludeThese));
    
}

map<string,int> make_map(vector<string> input, set<string> exclude)
{
    map<string, int> mapToReturn;
    //for count and laziness
    multiset<string> words;
    for(int i=0; i<input.size(); i++)
    {
	words.insert(input[i]);
    }

    for(int i=0; i<input.size(); i++)
    {
	if(exclude.find(input[i])==exclude.end())
        {
	    mapToReturn.insert(make_pair(input[i],words.count(input[i])));
	}
    }

   return mapToReturn;
}

void print(map<string,int> theMap)
{
    for(std::map<string,int>::iterator i=theMap.begin(); i!=theMap.end(); i++)
	cout << i->first << " repeated " << i->second << endl;
}
