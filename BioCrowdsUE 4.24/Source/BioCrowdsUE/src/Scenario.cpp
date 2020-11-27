#include "Scenario.h"

Scenario::Scenario()
{
    fName = "Script.txt";
    //pc = 0;
    //to_String = "";

}

int Scenario::load()
{
    FString file = "";
    //UE_LOG(LogTemp, Warning, TEXT("%s"), *fName);
    UFIleReader::LoadTxt(fName, file);
    TArray<FString> Array;
    file.ParseIntoArray(Array, TEXT("\n"), true);
    //UE_LOG(LogTemp, Warning, TEXT("%s"), *file);
    //int num = Array.Num();
    //UE_LOG(LogTemp, Warning, TEXT("%d"), num);
    for (auto c : Array) {
        if (c != Array.Last()) { c.RemoveAt(c.Len() - 1); }
        //UE_LOG(LogTemp, Warning, TEXT("%s"), *c);
        std::string const ln = TCHAR_TO_UTF8(*c);
        ScriptCommand command(ln);
        text.push_back(command);
    }
    int max = 0;
    for (ScriptCommand c : text)
    {
        if (c.getBehaviour().length() != 0 && Scripts.find(c.getBehaviour()) == Scripts.end()) {
            Script temp(c.getBehaviour() + ".txt");
            Scripts.insert({ c.getBehaviour(), temp });
        }
        if (c.getTargetID() > max) {
            max = c.getTargetID();
        }
    }
    return max;

}
/*
void Scenario::runnnnnn() {
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
        if (time == 10) { cout << "end of the day" << endl; time = 0; cout << "start of the day" << endl; }
        Sleep(1000);
        time++;
    }
}
*/
// to sring
string Scenario::toString()
{
    return ""; //to_String;
}