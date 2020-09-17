#ifndef SCRIPT_H
#define SCRIPT_H
#include <vector>
#include <iomanip>
#include <fstream>
#include "Command.h"
#include "Script.cpp"

using namespace std;

class Script
{
    private:
        string fName;
        int pc; 
        vector<Command> script;
        string toString;

    public:
        Script(string fileName);
        void load();
        void imprime();
    }
#endif