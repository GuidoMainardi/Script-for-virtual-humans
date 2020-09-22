#include "Script.h"

Script::Script(string fileName)
{
	fName = fileName;
    pc = 0;
    to_String = "";
    load();
}

void Script::load()
{
    ifstream inFile(fName);

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
        
    for (string ln; getline(inFile, ln); ) {
        Command command(ln);
        Script::text.push_back(command);
        to_String += command.toString() + "\n";
    }
    
    inFile.close();
}

// to sring
string Script::toString()
{
	return to_String;
}
