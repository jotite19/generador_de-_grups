#pragma once
#include "GrupInfants.h"

std::vector<std::string> GrupInfants::getMonitorsString()
{
	std::vector<std::string> r;
	for (Monitor m : llista_Monitors)
	{
		r.push_back(m.getMonitor());
	}
	return r;
}

int GrupInfants::genHeuristica()
{
	vegadesActualitzat++;
	heuristicaGrup = 0;
	for (Monitor m : llista_Monitors)
	{
		heuristicaGrup += m.updateHeuristica(getMonitorsString(), nomGrup);
	}
	return heuristicaGrup;
}

void GrupInfants::printGrups()
{
	std::cout << nomGrup << ": " << genHeuristica() << std::endl;
	for (Monitor moni : llista_Monitors)
	{
		std::cout << moni.getMonitor() << "(" << moni.updateHeuristica(getMonitorsString(), nomGrup) << "%), ";
	}
	std::cout << std::endl << std::endl;
}

int GrupInfants::printPerformance(int it)
{
	std::cout << "- " << nomGrup << ":" << vegadesActualitzat << "" << std::endl;
	return vegadesActualitzat;
}