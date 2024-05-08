#ifndef CONTROLETRAFEGO_HPP
#define CONTROLETRAFEGO_HPP

#include "Astronauta.hpp"
#include "Voos.hpp"
#include <list>
#include <iostream>
#include <string>
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
    void cadastroVoos();
    void imprimirVoos();

    //Metodos Astronauta
    void AstronautasMortosCpf();
    void AstronautasMortosNome();
    void AstronautasMortosVoos();
    void AstronautasDisponiveis();
    void AstronautasIndisponiveis();

    //Metodos Voos
    void AddAstronautaVoo();
};

//Implementar os Metodos



#endif