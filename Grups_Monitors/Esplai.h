#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

#include "DataGS.h"
#include "EquipMonitors.h"
#include "GrupInfants.h"

class Esplai
{
public:
	Esplai(std::vector<Monitor> monitors);
	~Esplai() {};

	std::vector<GrupInfants> getGrups() { return grups; }
	int getheuristicaBestGrup() { return heuristicaBestGrup; }
	void setGrups(std::vector<GrupInfants> g) { grups = g; }

	void algoritmeGrupal(int iteracions);
	void guardaConvinacio();
	void establexiBestGrup() { grups = bestGrups; };
	void reiniciaGrups(std::vector<Monitor> monitors);
	void loadBestEsplai();

	int getHeuristicaGlobal();
	
	void printEsplai();
	void printBestEsplai();
	void printReport(int it);

private:
	std::vector<GrupInfants> grups;
	std::vector<GrupInfants> bestGrups;
	
	int heuristicaBestGrup;

	std::string nomsGrups = "BTMXA";
	int nombreInfantsGrup[5] = { 3, 2, 2, 3, 3};
};

