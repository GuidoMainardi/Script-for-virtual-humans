#ifndef SCRIPTCOMMAND_H
#define SCRIPTCOMMAND_H
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <time.h>
#include "Target.h"
#include "Operation.h"

using namespace std;

class ScriptCommand {

private:
	int target_id;
	Operation op;
	int time;
	int numberOf;
	string behaviour;
	string RegionName;
	string to_String;
	string profile;
	bool isAll = false;
	ScriptCommand* Event;
	string model;
	bool hasModel = false;
public:
	// constructor and auxilary 
	ScriptCommand(string command);
	bool iequals(const string& a, const string& b);
	// gets
	int getTargetID() { return target_id; }
	int getTime() { return time; }
	int getNumberOf() { return numberOf; }
	bool gethasModel() { return hasModel; }
	bool getIsAll() { return isAll; }
	string getRegionName() { return RegionName; }
	string getBehaviour() { return behaviour; }
	string getProfile() { return profile; }
	string getModel() { return model; }
	Operation getOperation() { return op; }
	ScriptCommand* getEvent() { return Event; }
	// to string
	string toString() { return to_String; }
};

#endif
