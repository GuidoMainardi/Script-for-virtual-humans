#include "Scenario.h"

Scenario::Scenario()
{
    fName = "Script.txt";
    //pc = 0;
    //to_String = "";

}

int Scenario::load()
{
    pc = 0;
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
        if (c.getOperation() == Operation::CREATE) {
            max += c.getNumberOf();
        }
    }
    //UE_LOG(LogTemp, Warning, TEXT("%d"), max);
    return max;

}

// to sring
string Scenario::toString()
{
    return ""; //to_String;
}