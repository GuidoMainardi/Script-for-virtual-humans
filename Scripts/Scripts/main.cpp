#include <iostream>
#include "Script.h"

using namespace std;




void main()
{
    Script script("MonoBehaviour.txt");
    script.load();  
    cout << script.toString() << endl;

}


