#ifndef SCRIPT_H
#define SCRIPT_H
#include <iostream>
#include <string>
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
    vector<Command> text;
    string to_String;

public:
    Script(string fileName);
    void load();
    string toString();
};
#endif