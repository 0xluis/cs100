#include <list>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    list<int> numbers;
    int num;
    ofstream even, odd;
    while(cin >> num)
    {
	numbers.push_back(num);
    }

    numbers.sort();

    even.open("even.txt");
    if(!even)
    {
	cerr << "error opening even.txt";
	return 1;
    }

    odd.open("odd.txt");
    if(!odd)
    {
	cerr << "error opening odd.txt";
	return 1;
    }

    for(list<int>::iterator i=numbers.begin(); i!=numbers.end(); i++)
    {
	if((*i)%2==0)
	    even << *i << " ";
	else
	    odd << *i << endl;
    }

    even.close();
    odd.close();
    return 0;
}
