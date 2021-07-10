#ifndef SCRIPT_H
#define SCRIPT_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "BehaviourCommand.h"
#include "FIleReader.h"

using namespace std;


class Script
{
public:
    FString fName;
    int pc;
    vector<BehaviourCommand> text;
    string to_String;
    Script(string fileName);
    void load();
    string toString();
};
#endif