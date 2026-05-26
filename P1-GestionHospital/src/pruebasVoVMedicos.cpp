/*
 * pruebasVoVMedicos.cpp
 *
 *  Created on: 9 mar 2023
 *      Author: Jose Nogales
 */

#include "pruebasVoVMedicos.h"

void pruebasConstructorVoVMedico(){
    cout << "Inicio: pruebasConstructorVoVMedico" << endl;
    VoVMedicos vm;	// Constructor por defecto
    if ( vm.getOcupadas( ) != 0 ) {
        cerr << "ERROR: Un vector recién creado debe tener ocupadas = 0" << endl;
    }
    cout << "Fin: pruebasConstructorVoVMedico" << endl;
}
void pruebasInsertarVoVMedico(){
    cout << "Inicio: pruebasInsertarVoVMedico" << endl;

    VoVMedicos VMedicos;
    Medico *m;

    if ( !VMedicos.estaVacio ( ) ) {
        cerr << "ERROR: Un vector recién creado debe estar vacío" << endl;
    }
    if ( VMedicos.estaLleno ( ) ) {
        cerr << "ERROR: Un vector recién creado no puede estar lleno" << endl;
    }

    for ( int i = 0; i < MAXMedicos; i++ ) {
        m = new Medico;
        VMedicos.insertar ( m );
    }

    if ( VMedicos.estaVacio ( ) ) {
        cerr << "ERROR: Un vector en el que se han insertado MAX elementos no puede estar vacío" << endl;
    }
    if ( !VMedicos.estaLleno ( ) ) {
        cerr << "ERROR: Un vector en el que se han insertado MAX elementos debe estar lleno" << endl;
    }

    for ( int i = 0; i < MAXMedicos; i++ ) {
        delete VMedicos.getPosicion( i );
    }
    cout << "Fin: pruebasInsertarVoVMedico" << endl;

}

void pruebasVoVMedico(){
    pruebasConstructorVoVMedico();
    pruebasInsertarVoVMedico();
}





