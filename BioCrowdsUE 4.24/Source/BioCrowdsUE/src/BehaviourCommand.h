#ifndef BEHAVIOURCOMMAND_H
#define BEHAVIOURCOMMAND_H
#include "Instruction.h"
//#include "Position.h"
#include "Opcode.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;


class BehaviourCommand
{
private:
	Opcode opcode;
	Instruction instruction;
	int quantity;
	string destiny = "";
	string to_String;

	//Position place;

public:
	// functions
	BehaviourCommand(string command);
	bool iequals(const string& a, const string& b);

	// gets
	int getQuantity() { return quantity; }
	string getDestiny() { return destiny; }
	Opcode getOpcode() { return opcode; }
	Instruction getInstruction() { return instruction; }
	// to string
	string toString() { return to_String; }

	// old go to
	//Position getPlace() { return place; }
	//Position getnumber(int i, string str);
};
#endif