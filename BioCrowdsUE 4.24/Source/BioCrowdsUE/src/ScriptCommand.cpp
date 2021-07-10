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
		to_String += "Create " + to_string(numberOf) + " " + profile + " ";
		if (iequals(commandVector[3], "as")) {
			i = 6;
			model = commandVector[4];
			to_String += "as " + model + " ";
			hasModel = true;
		}else {
			i = 4;
		}
		for (; i < commandVector.size() - 1; i++) {
			RegionName += commandVector[i] + " ";
		}
		RegionName += commandVector[commandVector.size() - 1];
		to_String += "in "+ RegionName;
		return;
	}
	else if(iequals(commandVector[0], "All")) {
		isAll = true;
		profile = commandVector[1];
		to_String += "All " + profile + " ";
	}
	else if (iequals(commandVector[0], "When")) {
		op = Operation::WHEN;
		profile = commandVector[1];
		RegionName = commandVector[3];
		string event = "";
		for (int j = 4; j < commandVector.size() -1; j++) {
			event += commandVector[j] + " ";
		}
		event += commandVector[commandVector.size() - 1];
		Event = new ScriptCommand(event);
		behaviour = Event->getBehaviour();
		return;
	}
	else {
		
		profile = commandVector[0];
		target_id = stoi(commandVector[1]);
		to_String += profile + " " + to_string(target_id) + " ";
	}
	if (iequals(commandVector[2], "time")) {
		time = stoi(commandVector[3]);
		i = 4;
	}
	else {
		time = 0;
		i = 2;
	}
	to_String += "time " + to_string(time) + " ";
	if (iequals(commandVector[i], "run")) {
		op = Operation::RUN;
		behaviour = commandVector[i + 1];
		to_String += "run " + behaviour;
	}
	if (iequals(commandVector[i], "stop")) {
		op = Operation::STOP;
		to_String += "Stop";
	}
	if (iequals(commandVector[i], "loop")) {
		op = Operation::LOOP;
		behaviour = commandVector[i + 1];
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