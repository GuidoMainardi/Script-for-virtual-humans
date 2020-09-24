#include "BehaviourCommand.h"

BehaviourCommand::BehaviourCommand(string command){

	to_String = "";

	//Go
	if (iequals(command.substr(0, 2), "Go")) {

		opcode = Opcode::GO;
		to_String += "Go ";

		//To
		if (iequals(command.substr(3, 2), "To")) {

			instruction = Instruction::TO;
			to_String += "To ";
			place = command.substr(6);
			to_String += place;
		}
	}
	//Play
	else if (iequals(command.substr(0, 4), "Play")) {

		opcode = Opcode::PLAY;
		to_String += "Play ";

		//Claps
		if (iequals(command.substr(5, 5), "Claps")) {

			instruction = Instruction::CLAPS;
			to_String += "Claps";

		}

		//Dance
		if (iequals(command.substr(5, 5), "Dance")) {

			instruction = Instruction::DANCE;
			to_String += "Dance";

		}
	}
}

bool BehaviourCommand::iequals(const string& a, const string& b)
{
	return std::equal(a.begin(), a.end(), b.begin(),
					[](char a, char b) {
						return tolower(a) == tolower(b);
					});
}
