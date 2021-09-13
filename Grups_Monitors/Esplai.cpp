#include "Esplai.h"
#include <time.h>

Esplai::Esplai(std::vector<Monitor> monitors)
{
	for (int k = 0; k < 5; k++)
	{
		std::string n;
		n.push_back(nomsGrups[k]);
		GrupInfants g(n, nombreInfantsGrup[k]);
		grups.push_back(g);
	}

	int r = 0;
	int j = 0;
	srand(time(0));
	std::vector<Monitor> m = monitors;
	for (int i = 0; i < monitors.size(); i++)
	{
		r = std::rand() % (m.size());
		if (grups[j].getTamanyActual() < grups[j].getTamany())
		{
			grups[j].setMonitor(m[r]);
		}
		else
		{
			j++;
			grups[j].setMonitor(m[r]);
		}
		m.erase(m.begin() + r);
	}
	heuristicaBestGrup = getHeuristicaGlobal();
	guardaConvinacio();
}

void Esplai::reiniciaGrups(std::vector<Monitor> monitors)
{
	grups.clear();
	bestGrups.clear();
	heuristicaBestGrup = 0;

	for (int k = 0; k < 5; k++)
	{
		std::string n;
		n.push_back(nomsGrups[k]);
		GrupInfants g(n, nombreInfantsGrup[k]);
		grups.push_back(g);
	}

	int r = 0;
	int j = 0;
	srand(time(0));
	std::vector<Monitor> m = monitors;
	for (int i = 0; i < monitors.size(); i++)
	{
		r = std::rand() % (m.size());
		if (grups[j].getTamanyActual() < grups[j].getTamany())
		{
			grups[j].setMonitor(m[r]);
		}
		else
		{
			j++;
			grups[j].setMonitor(m[r]);
		}
		m.erase(m.begin() + r);
	}
	heuristicaBestGrup = getHeuristicaGlobal();
	guardaConvinacio();
}

void Esplai::algoritmeGrupal(int iteracions)
{
	for (int j = 0; j < grups.size(); j++)
	{
		grups[j].genHeuristica();
	}

	int minHeuMoniIndex = 0;
	int minHeuGrupIndex = 0;

	for (int i = 0; i < iteracions; i++)
	{
		srand(i);
		//Detectar el grup mes trist
		int minHeuGrup = grups[0].getheuristicaGrup()/grups[0].getTamany();
		for (int i = 1; i < grups.size(); i++)
		{
			int heuristicaGrupActual = grups[i].getheuristicaGrup()/grups[i].getTamany();
			if (heuristicaGrupActual < minHeuGrup)
			{
				minHeuGrup = heuristicaGrupActual;
				minHeuGrupIndex = i;
			}
		}

		//Detectar el moni mes trist
		std::vector<Monitor> llista_Monitors = grups[minHeuGrupIndex].getMonitors();
		int minHeuMoni = llista_Monitors[0].getHeuristica();
		for (int i = 1; i < llista_Monitors.size(); i++)
		{
			int heuristicaMoniActual = llista_Monitors[i].getHeuristica();
			if (heuristicaMoniActual < minHeuMoni)
			{
				int minHeuGrup = heuristicaMoniActual;
				int minHeuMoniIndex = i;
			}
		}

		//Trobar nou lloc el Moni mes trist 
		int victimGIndex = minHeuGrupIndex;
		int j = std::rand() % (grups.size());
		
		for (int i = 0; i < j; i++)
			victimGIndex += 1;
		if (victimGIndex == minHeuGrupIndex)
			victimGIndex += 1;
		if (victimGIndex >= grups.size())
			victimGIndex -= grups.size();
		
		int victimMIndex = std::rand() % (grups[victimGIndex].getTamanyActual());

		//Canviar de lloc el Moni mes trist 
		grups[minHeuGrupIndex].setMonitor((grups[victimGIndex].getMonitors()[victimMIndex]));
		grups[victimGIndex].setMonitor((grups[minHeuGrupIndex].getMonitors()[minHeuMoniIndex]));

		grups[minHeuGrupIndex].borraMonitor(minHeuMoniIndex);
		grups[victimGIndex].borraMonitor(victimMIndex);

		grups[minHeuGrupIndex].genHeuristica();
		grups[victimGIndex].genHeuristica();

		//Guardar convinacio si es la millor
		int heuristicaGeneralActual = getHeuristicaGlobal();
		if (heuristicaGeneralActual > heuristicaBestGrup)
		{
			heuristicaBestGrup = getHeuristicaGlobal();
			guardaConvinacio();
		}
	}
}

void Esplai::guardaConvinacio()
{
	bestGrups.clear();
	for (GrupInfants g : grups)
	{
		bestGrups.push_back(g);
	}
}

int Esplai::getHeuristicaGlobal()
{
	int h = 0;
	for (GrupInfants g : grups)
	{
		h += g.getheuristicaGrup();
	}
	return h;
}

void Esplai::printBestEsplai()
{
	std::cout << "Els millors grups de monitors trobats son: " << heuristicaBestGrup << std::endl << std::endl;
	for (GrupInfants g : bestGrups)
	{
		g.printGrups();
	}
}

void Esplai::printEsplai()
{
	std::cout << "Els grups de monitors actuals son: " << heuristicaBestGrup << std::endl << std::endl;
	for (GrupInfants g : grups)
	{
		g.printGrups();
	}
}

void Esplai::printReport(int it)
{
	int p = 0;
	clock_t begin = clock();
	algoritmeGrupal(it);
	clock_t end = clock();

	std::cout << "Canvis: " << it << std::endl;
	std::cout << "Elapsed time: " << end - begin << " ms" << std::endl;
	std::cout << "Canvis de monitors:" << std::endl;
	for (GrupInfants g : grups)
		p += g.printPerformance(it);
	std::cout << "Canvis Totals: " << p << std::endl << std::endl;

	printBestEsplai();
}

void Esplai::loadBestEsplai()
{
	grups.clear();
	for (GrupInfants g : bestGrups)
	{
		grups.push_back(g);
	}
}