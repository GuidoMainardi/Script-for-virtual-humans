#include "ScriptCommand.h"

ScriptCommand::ScriptCommand(string command) {
	stringstream ss(command);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> commandVector(begin, end);
	copy(commandVector.begin(), commandVector.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	int i = 0;
	if (iequals(commandVector[0], "Create")) {

		op = Operation::CREATE;
		numberOf = stoi(commandVector[1]);
		profile = commandVector[2];
		for (int j = 4; j < commandVector.size() - 1; j++) {
			RegionName += commandVector[j] + " ";
		}
		RegionName += commandVector[commandVector.size() - 1];
		to_String += "Create " + to_string(numberOf) + " " + profile + " "+ RegionName;
		return;
	}
	else if(iequals(commandVector[0], "All")) {
		isAll = true;
		profile = commandVector[1];
		to_String += "All " + profile + " ";
	}
	else {
		
		profile = commandVector[0];
		target_id = stoi(commandVector[1]);
		to_String += profile + " " + to_string(target_id) + " ";
	}
	time = stoi(commandVector[3]);
	to_String += to_string(time) + " ";
	if (iequals(commandVector[4], "run")) {
		op = Operation::RUN;
		behaviour = commandVector[5];
		to_String += "run " + behaviour;
	}
	if (iequals(commandVector[4], "stop")) {
		op = Operation::STOP;
		to_String += "Stop";
	}
	if (iequals(commandVector[4], "loop")) {
		op = Operation::LOOP;
		behaviour = commandVector[5];
		to_String += "loop " + behaviour;
	}
}

bool ScriptCommand::iequals(const string& a, const string& b)
{
	return std::equal(a.begin(), a.end(), b.begin(),
		[](char a, char b) {
			return tolower(a) == tolower(b);
		});
}