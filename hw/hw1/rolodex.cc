#include <iostream>
#include <fstream>
using namespace std;

//we gotta make a node for the list
struct Contact
{
    public:
    Contact* next;
    string name;
    string address;
    string number;

    Contact(string contactName, string contactAddress, string contactNumber)
    :name(contactName), address(contactAddress), number(contactNumber), next(NULL)
    {
    }
};

class Rolodex
{

    private:

    Contact* head;
    bool modified;

    public:
    Rolodex()
    :head(NULL), modified(false)
    {
	//default constructor
    }

    void insert()
    {
	
	string name, address, number;
        char response;
	cin.clear();
	cin.ignore();
	cout << "Enter last name: ";
        getline(cin, name);
	cin.clear();
	cout << "Enter address: ";
	getline(cin, address);
	cin.clear();
	cout << "Enter phone number: ";
	getline(cin, number);
	cin.clear();

	Contact* newContact = new Contact(name, address, number);

	if(!head)
	{
	    head = newContact;
	    modified = true;
	    return;
	}

	Contact* index = head;

	while(index->next!=NULL)
	{
	    if(index->next->name > name)
	    {
		newContact->next = index->next;
		index->next = newContact;
		modified = true;
		return;
	    }

	    index=index->next;
	}

	index->next = newContact;
	modified = true;

    }

    void find()
    {
	if(!head)
	{
	    cout<< "Rolodex is currently empty." << endl;
	    return;
	}

	string nameToFind;
	cout << "Please enter the last name of the "
	     << "contact you wish to find (case sensitive): ";
	cin >> nameToFind;

	Contact* index = head;
        while(index)
	{
	    if(index->name == nameToFind)
	    {
		cout << index->address << endl;
		return;
	    }
	    index=index->next;
	}

	cout << "No contact by the name of " << nameToFind << " exsits!" << endl;
    }

   void deleteContact()
    {
        if(!head)
        {
            cout<< "Rolodex is currently empty." << endl;
            return;
        }

        string nameToFind;
        cout << "Please enter the last name of the "
             << "contact you wish to delete (case sensitive): ";
        cin >> nameToFind;

        Contact* index = head;
	
	if(index->name == nameToFind)
	{
	    head = index->next;
	    delete index;
	    modified = true;
	    cout << "Deleted!" << endl;
	    return;
	}

        while(index->next)
        {
            if(index->next->name == nameToFind)
            {
		Contact* toDelte = index->next;
		index->next = toDelte->next;
		delete toDelte;
		modified = true;
		cout << "Deleted!" << endl;
		return;
            }
            index=index->next;
        }

	if(index->name == nameToFind)
	{
	    delete index;
	    //deallocate and set pointer to null becuase
	    //could still be pointed to by previous node
	    index = 0;
	    modified = true;
	    cout << "Deleted!" << endl;
	    return;
	}

        cout << "No contact by the name of " << nameToFind << " exsits!" << endl;
    }
    
    void print()
    {
	if(!head)
	{
	    cout << "Nothing to print!!" << endl;
	    return;
	}
	Contact* index = head;
	int number = 0;
	while(index)
	{
	    number ++;
	    cout << "\n==========================================\n"
		 << "Contact # " << number << endl
	         << "Last Name: " << index->name << endl
	 	 << "Address: " << index->address << endl
		 << "Phone Number: " << index->number << endl
		 << "==========================================\n\n";
	   index = index->next;
	}
    }

    void save()
    { 
	if(!head)
	{
	    cout << "The rolodex is empty, cannot save!\n";
	    return;
	}

	Contact* index = head;
	string nameOfFile;
	cout << "Name the .rolosav file: ";
	cin >> nameOfFile;
	nameOfFile+=".rolosav";

	ofstream savefile;
	savefile.open(nameOfFile.c_str());
	savefile << "*START*\n";

	while(index)
	{
            savefile << index->name << endl << index->address << endl
		     << index->number << endl;
	    index = index->next;
	}
	savefile << "*END*\n";

	cout << "File has been saved in working directory as "
	     << nameOfFile << endl;

	modified = false;

	savefile.close();
       
    }

    void quit()
    {
	if(modified)
	{
	    char choice;
	    do
	    {
	        cout << "Would you like to save? (Y or N): ";
	        cin >> choice;
            }while(choice != 'Y' && choice != 'N');

	    if(choice == 'Y')
	    {
		save();
	    }
	}
    }

    void load()
    {
	string nameOfFile, name, address, number;
	cout << "What is the name of the .rolosave file: ";
	cin >> nameOfFile;
	nameOfFile+=".rolosav";
	ifstream savefile (nameOfFile.c_str());
	if(savefile.is_open())
	{
	    Contact* index;

	    savefile >> name;//lets get rid of the starting header

	    while(savefile >> name && name != "*END*")
	    {
		savefile.ignore();
		getline(savefile, address);
		getline(savefile, number);
		if(!head)
		{
		    head = new Contact(name, address, number);
		    index = head;
		}
		else
		{
		    index->next = new Contact(name, address, number);
	            index = index->next;
		}
		
	    }
	    cout << "Rolosav file has been loaded!" << endl;
	    savefile.close();
	}
	else
	    cout << "Error cannot open file!\n";
	
	return;
    }

    void menu()
    {
	char command;
	while(true)
	{
	    cout << "\n   Rolodex Program (Card Contacts Spinny Thingy)\n"
	         << "============================================="
	         << "=====\n"
                 << "||\ti - inseart a new address\t\t||\n"
	         << "||\tf - find an address\t\t\t||\n"
	         << "||\td - delete an address\t\t\t||\n"
	         << "||\tp - print all cards in rolodex\t\t||\n"
	         << "||\tl - load addresss from a .rolosav\t||\n"
	         << "||\ts - save the address to a .rolosav\t||\n"
	         << "||\tq - quit the program\t\t\t||\n";
	    cout << "Type in letter command: ";
	    cin >> command;
	    if(cin.peek()!='\n')
	    {
		cout << "Input truncated to 1st char";
		cin.ignore();
	    }
	    cout << endl;
	
	    switch (command)
	    {
	        case 'i':
	          insert();
	        break;
	        case 'f':
	          find();
	        break;
	        case 'd':
	          deleteContact();
	        break;
	        case 'p':
	          print();
	        break;
	        case 'l':
	          load();
	        break;
	        case 's':
	          save();
	        break;
	        case 'q':
		  quit();
		  return;
	        default:
	          cout << "Invalid command" << endl;
	    }
	}
    }

};


int main()
{
    Rolodex a;
    a.menu();
}
