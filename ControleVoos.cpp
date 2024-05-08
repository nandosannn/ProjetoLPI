#include "ControleTrafego.hpp"

//Metodo Adicionar Astronauta
void ControleTrafego::AddAstronautaVoo(){
    int inputVoo;
    cout << "Digite o codigo do Voo que deseja adicionar Astronautas: ";
    cin >> inputVoo;
    string inputAstronauta;
    cout << "Digite o Cpf do Astronauta: ";
    getline(cin, inputAstronauta);

    for (Voos voos : voosAll)
    {
        if ((inputVoo == voos.getCodigo()) && (voos.statusVoo == EmPlanejamento))
        {
            for (Astronauta astronauta : astronautaAll)
            {
                if ((inputAstronauta == astronauta.getCpf()) && (astronauta.statusAstronauta == disponivel))
                {
                    voos.AdicionarAstronauta(astronauta);
                    astronauta.statusAstronauta = indisponivel;
                    astronauta.voosParticipados.push_back(voos.getCodigo());
                    system("cls");
                    cout << "Astronauta " << astronauta.getNome() << " adicionado com sucesso ao voo: " << voos.getCodigo() << endl;
                }
                else{
                    system("cls");
                    cout << "Astronauta nao encontrado ou indisponivel!" << endl;
                }
            }
        }
        else{
            system("cls");
            cout << "Voo nao encontrado ou ja finalizado o planejamento!" << endl;
        }
    }
}