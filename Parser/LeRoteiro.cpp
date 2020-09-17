#include <iostream>
#include "Script.h"

using namespace std;

class LeRoteiro 
{
    Script script = new Script("script.txt");
    
    void main()
    {

        script.load();  
        script.imprime();

    }


}

