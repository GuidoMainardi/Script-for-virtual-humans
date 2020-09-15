using System;
using System.IO;
using System.Collections.Generic;
using System.Resources;

public class Script
{
	private String fName;
	private int pc; 
    private List<Command> script;
    private String toString;

    public Script(String fileName)
	{
		fName = fileName;
        pc = 0;
        script = new List<Command>();
        String toString = "";
	}

	public viod load()
    {
        try
        {
            String ln; 
            // Open the text file using a stream reader.
            using (var file = new StreamReader(fName))
            {
                while((ln = file.ReadLine()) != null)
                {
                    Command command = new Command(ln);
                    script.Add(command);
                    toString += command.ToString() + "\n";
                }
            }
        }
        catch (IOException e)
        {
            Console.WriteLine("The file could not be read:");
            Console.WriteLine(e.Message);
        }
    }

    // to sring
	public override string ToString()
    {
		return toString;
    }
}
