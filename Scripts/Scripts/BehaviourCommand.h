#ifndef BEHAVIOURCOMMAND_H
#define BEHAVIOURCOMMAND_H
#include "Instruction.h"
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
	string place;
	string to_String;

public:
	BehaviourCommand(string command);
	bool iequals(const string& a, const string& b);
	Opcode getOpcode() { return opcode; }
	Instruction getInstruction() { return instruction; }
	int getQuantity() { return quantity; }
	string getPlace() { return place; }
	string toString() { return to_String; }
};
#endif