#include "ScriptCommand.h"

ScriptCommand::ScriptCommand(string command) {
	// Agent X time Y run behaviour
	if (iequals(command.substr(0, 5), "Agent")) {

		int i = 6;
		target = Target::AGENT;
		to_String += "Agent ";
		
		//X
		target_id = getnumber(&i, command);
		to_String += to_string(target_id) + " ";

		// time Y
		if (iequals(command.substr(i, 4), "time")) {
			i += 5;
			time = getnumber(&i, command);
			to_String += "time " + to_string(time) + " ";
			// run behaviour
			if (iequals(command.substr(i, 3), "run")) {
				i += 4;
				op = Operation::RUN;
				to_String += "run ";

				behaviour = command.substr(i);
				to_String += behaviour;
			} // stop
			else if (iequals(command.substr(i, 4), "stop")) {
				i += 5;
				op = Operation::STOP;
				to_String += "Stop ";
			}
		}
	}
}

int ScriptCommand::getnumber(int *i, string str) {
	int temp;
	string number = "";
	for (temp = *i; str.at(temp) != ' '; temp++) {
		number += str.at(temp);
	}
	*i = temp + 1;
	return stoi(number);
}

bool ScriptCommand::iequals(const string& a, const string& b)
{
	return std::equal(a.begin(), a.end(), b.begin(),
		[](char a, char b) {
			return tolower(a) == tolower(b);
		});
}