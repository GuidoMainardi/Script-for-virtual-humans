#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Command{

	Command(string command){

		toString = "";

		//Start
		if(iequals(command.substr (0,5), "Start")){

			opcode = Opcode::START;

			//in
			if(iequals(command.substr (6,2), "in"){

				instruction = Instruction::IN;
				place = command.substr (9);

			}
		}
		//Begin
		else if(iequals(command.substr (0,5), "Begin")){

			opcode = Opcode::BEGIN;

			//Loop
			if(iequals(command.substr (5,4), "Loop")){

				instruction = Instruction::LOOP;
			}
		}
		//Go
		else if(iequals(command.substr (0,2), "Go")){

			opcode = Opcode::GO;

			//To
			if(iequals(command.substr (2,2), "To")){

				instruction = Instruction::TO;
				place = command.substr(6);
			}
		}
		//Play
		else if(iequals(command.substr (0,4), "Play")){
			
			opcode = Opcode::PLAY;

			//Claps
			if(iequals(command.substr (5,5), "Claps")){
				
				instruction = Instruction::CLAPS;

			}

			//Dance
			if(iequals(command.substr (5,5), "Dance")){
				
				instruction = Instruction::DANCE;

			}
		}
		//End
		else if(iequals(command.substr (0,3), "End")){

			opcode = Opcode::END;

			//Loop
			if(iequals(command.substr (3,4), "Loop")){

				instruction = Instruction::LOOP;
			}
		}
	}

	bool iequals(const string& a, const string& b)
	{
		return std::equal(a.begin(), a.end(), b.begin(),
						[](char a, char b) {
							return tolower(a) == tolower(b);
						});
	}
}
