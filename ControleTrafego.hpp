#ifndef CONTROLETRAFEGO_HPP
#define CONTROLETRAFEGO_HPP

#include "Astronauta.hpp"
#include "Voos.hpp"
#include <list>
#include <iostream>
using namespace std;

class ControleTrafego{
public:
    list<Astronauta> astronautaAll;
    list<Voos> voosAll;

    //Construtores
    ControleTrafego();

    //Destrutores
    ~ControleTrafego();

    //Metodos
    void cadastroAstronauta();

    void imprimirAstronautas();

};

//Implementar os Metodos



#endif