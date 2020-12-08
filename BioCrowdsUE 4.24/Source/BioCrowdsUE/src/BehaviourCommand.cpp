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
			//place = getnumber(7, command);
			destiny = command.substr(6);
			if (destiny[destiny.size() - 1] == '\r' || destiny[destiny.size() - 1] == '\n') {
				destiny = destiny.substr(0, destiny.size() - 1);
			}
			to_String += place.tostring();
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

Position BehaviourCommand::getnumber(int i, string str) {
	int x = 0, y = 0, z = 0;
	string number = "";
	for (; str.at(i) != ','; i++) {
		number += str.at(i);
	}
	i++;
	x = stoi(number);
	number = "";
	for (; str.at(i) != ','; i++) {
		number += str.at(i);
	}
	i++;
	y = stoi(number);
	number = "";
	for (; str.at(i) != ')'; i++) {
		number += str.at(i);
	}
	i++;
	z = stoi(number);
	Position temp(x, y, z);
	return temp;
}