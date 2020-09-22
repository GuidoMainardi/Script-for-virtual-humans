#ifndef SCENARIO_H
#define SCENARIO_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Command.h"
#include "Script.h"

using namespace std;


class Scenario
{
private:
    string fName;
    int pc;
    vector<Command> text;
    vector<Script> Agents;
    string to_String;

public:
    Scenario(string fileName);
    void load();
    void run();
    string toString();
};
#endif