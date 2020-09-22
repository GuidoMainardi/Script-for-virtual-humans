#ifndef COMMAND_H
#define COMMAND_H
#include "Instruction.h"
#include "Opcode.h"
#include <string>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


class Command
{
private:
	Opcode opcode;
	Instruction instruction;
	int quantity;
	string place;
	string to_String;

public:
	Command(string command);
	bool iequals(const string& a, const string& b);
	Opcode getOpcode() { return opcode; }
	Instruction getInstruction() { return instruction; }
	int getQuantity() { return quantity; }
	string getPlace() { return place; }
	string toString() { return to_String; }
};
#endif