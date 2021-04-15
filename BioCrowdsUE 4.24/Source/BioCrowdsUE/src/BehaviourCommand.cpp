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
			destiny = command.substr(6);
			if (destiny[destiny.size() - 1] == '\r' || destiny[destiny.size() - 1] == '\n') {
				destiny = destiny.substr(0, destiny.size() - 1);
			}
			to_String += destiny;
		}
	}
	//Play
	else if (iequals(command.substr(0, 4), "Play")) {

		opcode = Opcode::PLAY;
		to_String += "Play ";

		destiny = command.substr(5);
		to_String += destiny;
	}
}

bool BehaviourCommand::iequals(const string& a, const string& b)
{
	return std::equal(a.begin(), a.end(), b.begin(),
					[](char a, char b) {
						return tolower(a) == tolower(b);
					});
}
