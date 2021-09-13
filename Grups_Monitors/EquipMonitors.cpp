#pragma once

#include "EquipMonitors.h"

EquipMonitors::EquipMonitors(std::string fitxa_monitors)
{
	DataGS data(0);
	int tipus_llista = 0;
	int seccio = 0;

	std::vector<std::string> fitxa_monitors_vec;
	std::vector<std::string> llista;


	fitxa_monitors_vec = data.getData(fitxa_monitors);

	for (std::string dades : fitxa_monitors_vec)
	{
		switch (tipus_llista)
		{
		case 0:
			if (dades != "break")
				llista.push_back(dades);
			else
			{ 
				for (std::string monitor : llista)
				{
					Monitor temp(monitor);
					llista_Monitors.push_back(temp);
				}
				llista.clear();
				tipus_llista++;
				seccio++;
			}
			break;

		case 1:
			if (dades != "break") 
				llista.push_back(dades);
			else
			{
				asignarllista(llista, seccio);
				llista.clear();
				seccio++;
			}
			break;

		default:
			break;
		}

	}
	
}

void EquipMonitors::asignarllista(std::vector<std::string> l, int p)
{
	int i = 0;
	for (int x = 0; x < llista_Monitors.size(); x++)
	{
		std::vector<std::string> temp_list;
		while (i < l.size())
		{
			if (l[i] != ".")
			{
				temp_list.push_back(l[i]);
				i++;
			}
			else
			{
				i++;
				break;
			}
		}
		
		switch (p)
		{
		case 1:
			llista_Monitors[x].setPGI(temp_list);
			break;

		case 2:
			llista_Monitors[x].setSCON(temp_list);
			break;
		
		case 3:
			llista_Monitors[x].setNCON(temp_list);
			break;

		case 4:
			llista_Monitors[x].setLCON(temp_list);
			break;

		case 5:
			llista_Monitors[x].setGMI(temp_list);
			break;

		default:
			break;
		}
		llista_Monitors[x].genMaxHeuristica();
	}
}

void EquipMonitors::printLlista()
{
	for (Monitor monitor : llista_Monitors)
	{ 
		std::cout << monitor.getMonitor() << ": ";

		std::cout << std::endl << "  PGI: ";
		for (std::string pgi : monitor.getPGI())
			std::cout << pgi << ", ";

		std::cout << std::endl << "  SCON: ";
		for (std::string pgi : monitor.getSCON())
			std::cout << pgi << ", ";

		std::cout << std::endl << "  NCON: ";
		for (std::string pgi : monitor.getNCON())
			std::cout << pgi << ", ";

		std::cout << std::endl << "  LCON: ";
		for (std::string pgi : monitor.getLCON())
			std::cout << pgi << ", ";
		std::cout << std::endl;

		std::cout << std::endl;
	}
}