#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>

#include "DataGS.h"
#include "EquipMonitors.h"
#include "GrupInfants.h"
#include "Esplai.h"

void algoritmeHCD(Esplai esplai, int it)
{
    std::cout << "Iniciant algoritme HCD:" << std::endl;

    int heuDiff = 0;
    int lastHeu = 0; 

    esplai.algoritmeGrupal(it);
    lastHeu = esplai.getHeuristicaGlobal();
    heuDiff = lastHeu - heuDiff;

    while (heuDiff != 0)
    {
        //std::cout << "Iteracio acabada amb heuristica: " << esplai.getHeuristicaGlobal() << std::endl;
        //std::cout << "Iteracio amb millor heuristica: " << esplai.getheuristicaBestGrup() << std::endl << std::endl;
        esplai.establexiBestGrup();
        esplai.loadBestEsplai();
        esplai.algoritmeGrupal(it);
        heuDiff = lastHeu - esplai.getHeuristicaGlobal();
        lastHeu = esplai.getHeuristicaGlobal();
    }
    esplai.printBestEsplai();
}

void algoritmeHCDmanual(Esplai esplai, EquipMonitors equip, int it)
{
    algoritmeHCD(esplai, it);

    bool exit = true;
    char continuar = 'n';
    char bufferIrrelevant = 'n';

    while (exit)
    {
        std::cout << "Nous grups:   [r + enter]" << std::endl;
        std::cout << "Exit:         [e + enter]" << std::endl;
        std::cin >> continuar;

        if (continuar == 'r')
        {
            esplai.reiniciaGrups(equip.getLlistaMonitors());
            algoritmeHCD(esplai, it);
        }
        else
        {
            exit = false;
        }
    }
}

void algoritmeHCDautomatic(Esplai esplai, EquipMonitors equip, int it, int intents)
{
    algoritmeHCD(esplai, it);

    for(int i = 0; i < intents; i++)
    {
        esplai.reiniciaGrups(equip.getLlistaMonitors());
        algoritmeHCD(esplai, it);
    }

}

int main()
{
    int it = 500;

    EquipMonitors equip("dadesMonitorsFinal.txt");
    Esplai esplai(equip.getLlistaMonitors());

    std::cout << "Iniciant programa" << std::endl;

    //algoritmeHCDmanual(esplai, equip, it);
    algoritmeHCDautomatic(esplai, equip, it, 20);

    return 0;
}
