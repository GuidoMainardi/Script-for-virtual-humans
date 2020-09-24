#ifndef SCENARIO_H
#define SCENARIO_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <map>
#include "ScriptCommand.h"
#include "Script.h"
#include "Operation.h"

using namespace std;


class Scenario
{
private:
    string fName;
    int pc;
    vector<ScriptCommand> text;
    map<string, Script> Scripts;
    map<int, string> Agents;
    string to_String;

public:
    Scenario(string fileName);
    void load();
    void run();
    string toString();
};
#endif