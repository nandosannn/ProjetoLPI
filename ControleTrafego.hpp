#ifndef CONTROLETRAFEGO_HPP
#define CONTROLETRAFEGO_HPP

#include "Astronauta.hpp"
#include "Voos.hpp"
#include <list>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class ControleTrafego{
public:
    list<Astronauta> astronautaAll;
    list<Voos> voosAll;

    //Construtores
    ControleTrafego();

    //Destrutores
    ~ControleTrafego();

    //Metodos Cadastro
    void cadastroAstronauta();
    void imprimirAstronautas();
    bool testeAstronauta(string input);
    void cadastroVoos();
    void imprimirVoos();
    bool testeVoos(int input);

    //Metodos Astronauta
    void AstronautasMortosCpf();
    void AstronautasMortosNome();
    void AstronautasMortosVoos();
    void AstronautasDisponiveis();
    void AstronautasIndisponiveis();

    //Metodos Voos
    void AddAstronautaVoo(list<Astronauta>& astronautaAll, list<Voos>& voosAll);
    void RemoAstronautaVoo(list<Astronauta>& astronautaAll, list<Voos>& voosAll);
    void PlanejamentoConcluido(list<Voos>& voosAll);
    void ListaPlanejado();
    void ListaEmCurso();
    void ListaFimSucesso();
    void ListaFimSemSucesso();

    //Metodos Controle Geral
    void LancarVoo();
    void ExplodirVoo();
    void FinalizarVoo();



};

//Implementar os Metodos



#endif