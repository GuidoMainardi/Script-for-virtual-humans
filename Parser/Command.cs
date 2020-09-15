using System;
using System.ComponentModel.Design;

public enum Opcode
{
	Create,
	Agent
}
public enum Instruction
{
	Play,
	Go,
	Stop,
	Agents
}
public enum Action
{
	Clap,
	Dance
}
public class Command
{
	private Opcode opcode;
	private int quantity;
	private Instruction instruction;
	private Action action;
	private String details;
	private String toString;
	public Command(String command)
	{
		toString = "";
		// Create x agents {(a,b,c), (m,n,p), ... (d,e,f)}
		if(command.Substring(0, 6).Equals("Create", StringComparison.InvariantCultureIgnoreCase))
        {
			opcode = Opcode.Create;
			toString += "Create ";

			String number = "";
			int i;
			for (i = 7; command[i] == " "; i++) { number += command[i];}
			quantity = int.Parse(number);
			toString += quantity + " ";

			if (command.Substring((i + 1), 6).Equals("agents", StringComparison.InvariantCultureIgnoreCase))
            {
				instruction = Instruction.Agents;
				i += 7;
			}

			details = command.Substring(i);

			toString += details;
		}
		// Agent x go to (a,b, c)
		else if (command.Substring(0,5).Equals("Agent", StringComparison.InvariantCultureIgnoreCase))
        {
			opcode = Opcode.Agent;
			toString += "Agent ";

			String number = "";
			int i;
			for (i = 6; command[i] == " "; i++) { number += command[i]; }
			quantity = int.Parse(number);
			toString += quantity + " ";

			if(command.Substring(i + 1, 5).Equals("go to", StringComparison.InvariantCultureIgnoreCase))
            {
				instruction = Instruction.Go;
				i += 6;
				toString += "Go ";
            }
			if(command.Substring(i + 1, 4).Equals("stop", StringComparison.InvariantCultureIgnoreCase))
            {
				instruction = Instruction.Go;
				i += 5;
				toString += "Stop ";
            }
			if (command.Substring(i + 1, 4).Equals("paly", StringComparison.InvariantCultureIgnoreCase))
			{
				instruction = Instruction.Play;
				i += 5;
				toString += "Play ";

				if (command.Substring(i, 5).Equals("claps", StringComparison.InvariantCultureIgnoreCase)){
					action = Action.Clap;
					i += 6;
					toString += "Clap ";
				}
				if (command.Substring(i, 5).Equals("dance", StringComparison.InvariantCultureIgnoreCase)){
					action = Action.Dance;
					i += 6;
					toString += "Dance ";
				}
			}

			details = command.Substring(i);
			toString += details;
		}
	}

	public Opcode GetOpcode()
    {
		return opcode;
    }

	// to sring
	public override string ToString()
    {
		return toString;
    }
}
