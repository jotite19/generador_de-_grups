#pragma once

#include "EquipMonitors.h"

EquipMonitors::EquipMonitors(std::string fitxa_monitors)
{
	DataGS data(0);

	std::vector<std::string>fitxa_monitors_vec;
	fitxa_monitors_vec = data.getData(fitxa_monitors);

	for (std::string monitor : fitxa_monitors_vec)
	{
		Monitor temp(monitor);
		llista_Monitors.push_back(temp);
	}
}

void EquipMonitors::printLlista()
{
	for (Monitor monitor : llista_Monitors)
	{
		std::cout << monitor.getMonitor() << std::endl;
	}
}