#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <list>
#include <string>
#include "Voos.hpp"
using namespace std;

enum StcAstronauta{
    disponivel,
    indisponivel
};

class Astronauta{
private:
    string cpf;
    string nome;
    int idade;
public:
    list<Voos> voosParticipados;
    int statusAstronauta;

    //Construtores
    Astronauta(string cpf, string nome, int idade);
    Astronauta();

    //Destrutor
    ~Astronauta();

    //Encapsuladores
    string getCpf();
    string getNome();
    int getIdade();
    void setIdade(int idade);
};


#endif

//Implementar os Metodos