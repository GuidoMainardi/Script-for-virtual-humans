#include "BehaviourCommand.h"

BehaviourCommand::BehaviourCommand(string command){

	stringstream ss(command);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> commandVector(begin, end);
	copy(commandVector.begin(), commandVector.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

	to_String = "";

	//Go
	if (iequals(commandVector[0], "Go")) {

		opcode = Opcode::GO;
		to_String += "Go ";

		//To
		if (iequals(commandVector[1], "To")) {

			instruction = Instruction::TO;
			to_String += "To ";
			for (int i = 2; i < commandVector.size() - 1; i++) {
				destiny += commandVector[i] + " ";
			}
			destiny += commandVector[commandVector.size() - 1];
			//if (destiny[destiny.size() - 1] == '\r' || destiny[destiny.size() - 1] == '\n') {
			//	destiny = destiny.substr(0, destiny.size() - 1);
			//}
			to_String += destiny;
		}
	}
	//Play
	else if (iequals(commandVector[0], "Play")) {

		opcode = Opcode::PLAY;
		to_String += "Play ";

		for (int i = 1; i < commandVector.size() - 1; i++) {
			destiny += commandVector[i] + " ";
		}
		destiny += commandVector[commandVector.size() - 1];

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
