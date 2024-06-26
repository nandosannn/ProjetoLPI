#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <list>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

enum StcAstronauta{
    disponivel,
    indisponivel,
    morto
};

class Astronauta{
private:
    string cpf;
    string nome;
    int idade;
public:
    list<int> voosParticipados;
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
    void setCpf(string cpf);
    void setNome(string nome);
    void setIdade(int idade);

    //Metodos

    //Metodo Lista Mortos
    bool verificarListaVoos();
    void imprimirVoosPresentes();
    bool addvoosParticipados(int codigo, list<int>& voosParticipados);
    bool removerVoosParticipados(int codigo, list<int>& voosParticipados);
};


#endif
