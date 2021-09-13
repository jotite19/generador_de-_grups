#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "DataGS.h"
#include "Monitor.h"

class EquipMonitors
{
public:
	EquipMonitors(std::string fitxa_monitors);
	~EquipMonitors() {};

	std::vector<Monitor> getLlistaMonitors() { return llista_Monitors; }

	void asignarllista(std::vector<std::string> l, int p);

	void printLlista();

private:
	std::vector<Monitor> llista_Monitors;
};