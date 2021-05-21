#include <iostream>
#include "DataGS.h"
#include "EquipMonitors.h"
int main()
{
    EquipMonitors equip("dadesMonitors.txt");
    
    equip.printLlista();

    return 0;
}