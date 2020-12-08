#ifndef BEHAVIOURCOMMAND_H
#define BEHAVIOURCOMMAND_H
#include "Instruction.h"
#include "Position.h"
#include "Opcode.h"
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;


class BehaviourCommand
{
private:
	Opcode opcode;
	Instruction instruction;
	int quantity;
	Position place;
	string destiny;
	string to_String;

public:
	BehaviourCommand(string command);
	bool iequals(const string& a, const string& b);
	Opcode getOpcode() { return opcode; }
	Instruction getInstruction() { return instruction; }
	int getQuantity() { return quantity; }
	Position getPlace() { return place; }
	string toString() { return to_String; }
	string getDestiny() { return destiny; }
	Position getnumber(int i, string str);
};
#endif