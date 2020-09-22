#include "Command.h"

Command::Command(string command){

	to_String = "";

	//Create 10 MonoBehaviour
	if (iequals(command.substr(0, 6), "Create")) {
	
		opcode = Opcode::CREATE;
		to_String += "Create ";

		string number = "";
		int i;
		for (i = 7; command.at(i) != ' '; i++) {
			number += command.at(i);
		}
		quantity = stoi(number);
		to_String += number + " ";

		place = command.substr(i + 1);
		to_String += place;
	
	}
	

	//Start
	if(iequals(command.substr (0,5), "Start")){

		opcode = Opcode::START;
		to_String += "Start ";

		//in
		if(iequals(command.substr (6,2), "in")){

			instruction = Instruction::IN;
			to_String += "in ";
			place = command.substr (9);
			to_String += place;

		}
	}
	//Begin
	else if(iequals(command.substr (0,5), "Begin")){

		opcode = Opcode::BEGIN;
		to_String += "Begin ";

		//Loop
		if(iequals(command.substr (6,4), "Loop")){

			instruction = Instruction::LOOP;
			to_String += "Loop";
		}
	}
	//Go
	else if(iequals(command.substr (0,2), "Go")){

		opcode = Opcode::GO;
		to_String += "Go ";

		//To
		if(iequals(command.substr (3,2), "To")){

			instruction = Instruction::TO;
			to_String += "To ";
			place = command.substr(6);
			to_String += place;
		}
	}
	//Play
	else if(iequals(command.substr (0,4), "Play")){
			
		opcode = Opcode::PLAY;
		to_String += "Play ";

		//Claps
		if(iequals(command.substr (5,5), "Claps")){
				
			instruction = Instruction::CLAPS;
			to_String += "Claps";

		}

		//Dance
		if(iequals(command.substr (5,5), "Dance")){
				
			instruction = Instruction::DANCE;
			to_String += "Dance";

		}
	}
	//End
	else if(iequals(command.substr (0,3), "End")){

		opcode = Opcode::END;
		to_String += "End ";

		//Loop
		if(iequals(command.substr (4,4), "Loop")){

			instruction = Instruction::LOOP;
			to_String += "Loop";
		}
	}
}

bool Command::iequals(const string& a, const string& b)
{
	return std::equal(a.begin(), a.end(), b.begin(),
					[](char a, char b) {
						return tolower(a) == tolower(b);
					});
}
