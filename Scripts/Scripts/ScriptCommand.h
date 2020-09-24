#ifndef SCRIPTCOMMAND_H
#define SCRIPTCOMMAND_H
#include <string>
#include <iostream>
#include <algorithm>
#include "Target.h"
#include "Operation.h"

using namespace std;

class ScriptCommand {

private:
	Target target;
	int target_id;
	Operation op;
	int time;
	string behaviour;
	string to_String;
public:
	ScriptCommand(string command);
	bool iequals(const string& a, const string& b);
	int getnumber(int *i, string str);
	Target getTarget() { return target; }
	int getTargetID() { return target_id; }
	Operation getOperation() { return op; }
	int getTime() { return time; }
	string getBehaviour() { return behaviour; }
	string toString() { return to_String; }
};

#endif
