#ifndef SCRIPTCOMMAND_H
#define SCRIPTCOMMAND_H
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
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
public:
	ScriptCommand(string command);
	bool iequals(const string& a, const string& b);
	int getTargetID() { return target_id; }
	Operation getOperation() { return op; }
	int getTime() { return time; }
	int getNumberOf() { return numberOf; }
	string getRegionName() { return RegionName; }
	string getBehaviour() { return behaviour; }
	string getProfile() { return profile; }
	string toString() { return to_String; }
	bool getIsAll() { return isAll; }
};

#endif
