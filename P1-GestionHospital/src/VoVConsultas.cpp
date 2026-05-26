/*
 * VoVConsultas.cpp
 *
 *  Created on: 23 feb 2023
 *      Author: Jose Nogales
 */

#include "VoVConsultas.h"
#include "FechaYHora.h"

VoVConsultas::VoVConsultas() {
    this->ocupadas = 0;
    VoVConsulta[ocupadas] = new Consulta;
}

void VoVConsultas::insertarEnOrden(Consulta *consulta) {
// Paso 1: buscar posición para el nuevo elemento
    bool encontrado = false;
    int pos = 0;
    int i = 0;
    while ((i < ocupadas) && (!encontrado)){
    if (VoVConsulta[i]->getFecha() > consulta->getFecha()) {
        encontrado = true;
    } else{
        i++;
        }
    pos = i;
    }
// Paso 2: Abrir hueco en pos para el nuevo elemento:
    for (i = ocupadas; i > pos; i--) {
        VoVConsulta[i] = VoVConsulta[i - 1];
    }
// Paso 3: Insertar el elemento en pos
    VoVConsulta[pos] = consulta;
    ocupadas++;

}

void VoVConsultas::borrar(int posicion) {
    for ( int i = posicion; i < ocupadas; i++ ){
        VoVConsulta[i] = VoVConsulta[i+1];
        ocupadas--;
    }

}

Consulta *VoVConsultas::getPosicion(int posicion) {
   return VoVConsulta[posicion];
}

int VoVConsultas::getOcupadas() {
    return this->ocupadas;
}

bool VoVConsultas::estaVacio() {
    return (ocupadas == 0);
}

bool VoVConsultas::estaLleno() {
    return (ocupadas == MAX);
}

void VoVConsultas::mostrar() {
    cout << "Numero de consultas: " << this->ocupadas << endl;
    for ( int i = 0; i < this->ocupadas; i++ ) {
        VoVConsulta[i]->mostrar( );
    }
}

VoVConsultas::~VoVConsultas() {
}

