#ifndef CONTROLETRAFEGO_HPP
#define CONTROLETRAFEGO_HPP

#include "Astronauta.hpp"
#include "Voos.hpp"
#include <list>
using namespace std;

class ControleTrafego{
public:
    list<Astronauta> astronautaAll;
    list<Voos> voosAll;

    //Construtores
    ControleTrafego();

    //Destrutores
    ~ControleTrafego();
};

//Implementar os Metodos



#endif