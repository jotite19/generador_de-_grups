#pragma once
#include "DataGS.h"

std::vector<std::string> DataGS::getData(std::string nom_fixer)
{
    std::ifstream dades_entrada(nom_fixer);

    std::vector<std::string> dades;
    std::string entrada;

    //Entrada
    while (dades_entrada >> entrada)
    {
        dades.push_back(entrada);
    }

    dades_entrada.close();
    return dades;
}

int DataGS::setData(std::string nom_fixer, std::vector<std::string> newinfo)
{
    std::ofstream dades_sortida(nom_fixer);

    //Sortida
    for (std::string dada : newinfo)
    {
        dades_sortida << dada << std::endl;
    }

    dades_sortida.close();
    return 0;
}