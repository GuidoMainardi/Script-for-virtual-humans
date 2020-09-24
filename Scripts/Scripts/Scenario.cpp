#include "Scenario.h"

Scenario::Scenario(string fileName)
{
    fName = fileName;
    pc = 0;
    to_String = "";

}

void Scenario::load()
{

    ifstream inFile(fName);

    if (!inFile) {
        cout << "Unable to open file: " << fName << endl;
        exit(1); // terminate with error
    }

    for (string ln; getline(inFile, ln); ) {
        ScriptCommand command(ln);
        text.push_back(command);
        to_String += command.toString() + "\n";
    }
    to_String += "\n";
    inFile.close();

    for (ScriptCommand c : text)
    {
        if (c.getBehaviour().length() != 0 && Scripts.find(c.getBehaviour()) == Scripts.end()) {
            Script temp(c.getBehaviour());
            Scripts.insert({ c.getBehaviour(), temp });
        }
        if (Agents.find(c.getTargetID()) == Agents.end()) {
           Agents.insert({c.getTargetID(), c.getBehaviour()});
        }
    }

    cout << "loaded file: " << fName << endl;
}

void Scenario::run() {
    int time = 0;
    cout << "start of the day" << endl;
    while (true) {
        cout << "time: " << time << endl;

        for (ScriptCommand c : text) {
            if (c.getTime() == time) {
                if (c.getOperation() == Operation::RUN) {
                    cout << "Agent " << c.getTargetID() << " run: " << c.getBehaviour() << " at time: " << time << endl;
                    cout << Scripts.find(c.getBehaviour())->second.toString() << endl;
                }
                if (c.getOperation() == Operation::STOP) {
                    cout << "Agent " << c.getTargetID() << " stoped at time: " << time << endl;
                }
            }
        }
        if (time == 10) { cout << "end of the day" << endl << endl; time = 0; cout << "start of the day" << endl; }
        Sleep(1000);
        time++;
    }
}

// to sring
string Scenario::toString()
{
    return to_String;
}