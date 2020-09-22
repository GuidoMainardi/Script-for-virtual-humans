#include <iostream>
#include "Scenario.h"

using namespace std;




void main()
{
    Scenario scenario("Script.txt");
    scenario.load();  
    scenario.run();
    cout << scenario.toString() << endl;

}


