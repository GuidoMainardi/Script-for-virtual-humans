#include <iostream>
#include "Scenario.h"

using namespace std;




int main()
{
    Scenario scenario("Script.txt");
    scenario.load();  
    scenario.run();
    return 0;
}


