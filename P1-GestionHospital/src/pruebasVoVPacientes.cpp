//
// pruebasVoVPacientes.h
// Created by Jose Nogales on 09/03/2023.
//

#include "pruebasVoVPacientes.h"

//
// pruebasVoVConsulta.cpp
// Created by Jose Nogales on 09/03/2023.
//

void pruebasConstructorVoVPaciente(){
    cout << "Inicio: pruebasConstructorVoVPaciente" << endl;
    VoVPacientes vp;
    if ( vp.getOcupadas( ) != 0 ) {
        cerr << "ERROR: Un vector recién creado debe tener ocupadas = 0" << endl;
    }
    cout << "Fin: pruebasConstructorVoVPaciente" << endl;
}
void pruebasInsertarVoVPaciente(){
    cout << "Inicio: pruebasInsertarVoVPaciente" << endl;

    VoVPacientes VPacientes;
    Paciente *p;

    if ( !VPacientes.estaVacio ( ) ) {
        cerr << "ERROR: Un vector recién creado debe estar vacío" << endl;
    }
    if ( VPacientes.estaLleno ( ) ) {
        cerr << "ERROR: Un vector recién creado no puede estar lleno" << endl;
    }

    for ( int i = 0; i < MAXPacientes; i++ ) {
        p = new Paciente;
        VPacientes.insertar ( p );
    }

    if ( VPacientes.estaVacio ( ) ) {
        cerr << "ERROR: Un vector en el que se han insertado MAX elementos no puede estar vacío" << endl;
    }
    if ( !VPacientes.estaLleno ( ) ) {
        cerr << "ERROR: Un vector en el que se han insertado MAX elementos debe estar lleno" << endl;
    }

    for ( int i = 0; i < MAXPacientes; i++ ) {
        delete VPacientes.getPosicion( i );
    }
    cout << "Fin: pruebasInsertarVoVPaciente" << endl;

}

void pruebasVoVPaciente(){
    pruebasConstructorVoVPaciente();
    pruebasInsertarVoVPaciente();
}
