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
#include "Senario.h"
#include "FIleReader.h"

using namespace std;


class Scenario
{
public:
    FString fName;
    int pc;
    vector<ScriptCommand> text;
    map<string, Script> Scripts;
    Scenario();
    int load();
    string toString();
};
#endif