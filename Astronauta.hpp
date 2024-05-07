#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <list>
#include <string>
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
};


#endif

//Implementar os Metodos