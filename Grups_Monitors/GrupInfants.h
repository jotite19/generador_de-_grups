#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Monitor.h"

class GrupInfants
{
public:
	GrupInfants(std::string n, int t) { nomGrup = n; heuristicaGrup = 0;  tamany = t; vegadesActualitzat = 0; };
	~GrupInfants() {};

	void setMonitor(Monitor m) { llista_Monitors.push_back(m);};
	void setTamany(int t) { tamany = t; };

	std::vector<Monitor> getMonitors() { return llista_Monitors; };
	std::vector<std::string> getMonitorsString();
	int getTamany() { return tamany; };
	int getTamanyActual() { return llista_Monitors.size(); }
	std::string getNom() { return nomGrup; }
	int getheuristicaGrup() { return heuristicaGrup; };

	void borraMonitor(int index) { llista_Monitors.erase(llista_Monitors.begin() + index); };

	int genHeuristica();

	void printGrups();
	int printPerformance(int it);

private:

	int tamany;
	std::string nomGrup;
	std::vector<Monitor> llista_Monitors;

	int heuristicaGrup;
	int vegadesActualitzat;
};
