#pragma once
#include "Monitor.h"

int Monitor::updateHeuristica(std::vector<std::string> monitors, std::string grup)
{
	float h = 0;

	//Grup
	for (int i = 0; i < p_grupsInfants.size(); i++)
	{
		if (grup == p_grupsInfants[i])
		{
			h += 2 - i;
			break;
		}
	}
	if (h != 0)
	{
		//Heuristiques generals
		for (std::string moni : monitors)
		{
			//Si Conos
			for (int i = 0; i < p_SConos.size(); i++)
			{
				if (moni == p_SConos[i])
				{
					h += 2;
				}
			}

			//No Conos
			for (int i = 0; i < p_NConos.size(); i++)
			{
				if (moni == p_NConos[i])
				{
					h -= 2;
				}
			}

			//LConos
			for (int i = 0; i < p_LConos.size(); i++)
			{
				if (moni == p_LConos[i])
				{
					h -= 2;
				}
			}
		}
	}
	else
	{
		h = 3;
	}

	h = h*100 / max_heuristica;
	heuristica = h;

	//Grup M Imposible
	for (int i = 0; i < p_grupImposible.size(); i++)
	{
		if (grup == p_grupImposible[i])
		{
			heuristica = 0;
			break;
		}
	}

	return h;
}

void Monitor::genMaxHeuristica()
{	
	int mh = 5;

	mh += p_SConos.size();
	mh += p_NConos.size();
	mh += p_LConos.size();

	max_heuristica = mh;
}
