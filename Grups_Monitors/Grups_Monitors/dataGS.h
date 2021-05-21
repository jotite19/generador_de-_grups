#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class DataGS
{
public:
	DataGS(int u) {};
	~DataGS() {};

	std::vector<std::string> getData(std::string nom_fixer);
	int setData(std::string nom_fixer, std::vector<std::string> newinfo);

private:
	std::ofstream dades_entrada;
	std::ofstream dades_sortida;
};