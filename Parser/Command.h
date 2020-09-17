#ifndef COMMAND_H
#define COMMAND_H
#include "Instruction.h"
#include "Opcode.h"

using namespace std;


class Command
{
    private: 
		Opcode opcode;
		Instruction instruction;
		string place;
		string toString;
        
    public:
		Command(string command);
		Opcode getOpcode() { return opcode;}
		Instruction getInstruction() { return instruction; }
		string getPlace(){ return place; }
		string toString() { return toString; }
}

#endif