#include "Scenario.h"

Scenario::Scenario(string fileName)
{
    fName = fileName;
    pc = 0;
    to_String = "";

}

void Scenario::load()
{

    ifstream inFile(fName);

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    for (string ln; getline(inFile, ln); ) {
        Command command(ln);
        text.push_back(command);
        to_String += command.toString() + "\n";
    }
    to_String += "\n";
    inFile.close();
}

void Scenario::run() {
    for (Command c : text)
    {
        switch (c.getOpcode()) {
            case Opcode::CREATE:
                Script temp(c.getPlace() + ".txt");
                to_String += temp.toString() += "\n";
                Agents.push_back(temp);
                break;
        }
    
    }
}

// to sring
string Scenario::toString()
{
    return to_String;
}