#include "Script.h"

Script::Script(string fileName)
{
    fName = FString(fileName.c_str());
    pc = 0;
    to_String = "";
    load();
}

void Script::load()
{
    FString file = "";
    UE_LOG(LogTemp, Warning, TEXT("%s"), *fName);
    USenario::LoadTxt(fName, file);
    UE_LOG(LogTemp, Warning, TEXT("%s"), *file);
    TArray<FString> Array;
    file.ParseIntoArray(Array, TEXT("\n"), true);
    for (auto c : Array) {
        std::string const ln = TCHAR_TO_UTF8(*c);
        BehaviourCommand command(ln);
        Script::text.push_back(command);
    }
}

// to sring
string Script::toString()
{
	return to_String;
}
