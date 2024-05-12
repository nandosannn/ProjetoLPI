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

    bool AdicionarAstronauta(Astronauta& astronauta, list<Astronauta>& AstronautasPresentes);
    bool RemoverAstronauta(string cpf, list<Astronauta>& AstronautasPresentes);

    

    //Metodo Controle Geral Voos.hpp
    void statusAstronautaMorto (list<Astronauta>& AstronautasPresentes, list<Astronauta>& astronautaAll);
    void limparLista(list<Astronauta>& AstronautasPresentes);
    void statusAstronautoVooFim (list<Astronauta>& AstronautasPresentes, list<Astronauta>& astronautaAll);
};

#endif

//Implementar os Metodos