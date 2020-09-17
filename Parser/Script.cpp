#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Command.h"

using namespace std;

class Script
{
    private:
	string fName;
	int pc; 
    vector<Command> script;
    string toString;

    public:
    Script(String fileName)
	{
		fName = fileName;
        pc = 0;
        script = new vector<Command>();
        string toString = "";
	}

	void load()
    {
        string ln;
        ifstream inFile;
        
        inFile.open(fName);
        if (!inFile) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }
        
        while (inFile >> ln) {
            Command command = new Command(ln);
            script.push_back(command);
            toString += command.toString() + "\n";
        }
        
        inFile.close();
    }

    // to sring
	string toString()
    {
		return toString;
    }
}
