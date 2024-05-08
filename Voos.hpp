#ifndef VOO_HPP
#define VOO_HPP

#include <list>
#include "Astronauta.hpp"
#include <iterator>
#include <string>
using namespace std;

enum SituacaoVoo{
    EmPlanejamento,
    Planejado,
    EmCurso,
    FimSucesso,
    FimSemSucesso
};

class Voos{
private:
    int codigo;
public:

    list<Astronauta> AstronautasPresentes;
    int statusVoo;

    //Construtores
    Voos();
    Voos(int codigo);
   
    //Destrutor
    ~Voos();

    //Encapsuladores
    int getCodigo();

    //Metodos
    void imprimirAstronautasPresentes();

    void AdicionarAstronauta(Astronauta astronauta);
    void RemoverAstronauta(Astronauta astronauta);
};

#endif

//Implementar os Metodos