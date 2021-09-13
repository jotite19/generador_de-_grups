#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Monitor
{
public:
	Monitor(std::string n) {nom = n; };
	~Monitor() {};

	std::string getMonitor() { return nom; };
	std::vector<std::string> getPGI() { return p_grupsInfants; };
	std::vector<std::string> getSCON() { return p_SConos; };
	std::vector<std::string> getNCON() { return p_NConos; };
	std::vector<std::string> getLCON() { return p_LConos; };
	std::vector<std::string> getGMI() { return p_grupImposible; };
	int getHeuristica() { return heuristica; };

	int setPGI(std::vector<std::string> pgi) { p_grupsInfants = pgi; return p_grupsInfants.size(); };
	void setSCON(std::vector<std::string> con) { p_SConos = con; };
	void setNCON(std::vector<std::string> con) { p_NConos = con; };
	void setLCON(std::vector<std::string> con) { p_LConos = con; };
	void setGMI(std::vector<std::string> gmi) { p_grupImposible = gmi; }

	int updateHeuristica(std::vector<std::string> monitors, std::string grup);
	void genMaxHeuristica();

private:
	std::string nom;
	std::vector<std::string> p_grupsInfants;
	std::vector<std::string> p_SConos;
	std::vector<std::string> p_NConos;
	std::vector<std::string> p_LConos;
	std::vector<std::string> p_grupImposible;

	int heuristica;
	int max_heuristica;
	int numeroGrupsMonitors = 5;

};


