#include "ControleTrafego.hpp"

void ControleTrafego::AstronautasMortos(){
    int astronautasMortos = 0;
    int elementos = 1;
    for (Astronauta astronautas : astronautaAll)
    {
        if (astronautas.statusAstronauta == morto)
        {
            cout << "Astronautas mortos #luto :" << endl;
            cout << "Nome: " << astronautas.getNome() << endl;
            cout << "Cpf: " << astronautas.getCpf() << endl;
            cout << "Voos que participou: " << endl;
            astronautas.imprimirVoosPresentes();
            astronautasMortos = 1;
            elementos++;
        }  
    }

    if (astronautasMortos == 0)
    {
        cout << "Nenhum astronauta morto #DeusNoControle" << endl;
    }
    
    
}