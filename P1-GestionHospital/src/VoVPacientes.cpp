/*
 * VoVPacientes.cpp
 *
 *  Created on: 27 feb 2023
 *      Author: Jose Nogales
 */

#include "VoVPacientes.h"

VoVPacientes::VoVPacientes() {
	ocupadas = 0;
    VoVPaciente[ocupadas] = new Paciente;
}

void VoVPacientes::insertar(Paciente *p) {
    this->VoVPaciente[this->ocupadas] = p;
    ocupadas++;
}

void VoVPacientes::borrar(int posicion) {
    for ( int i = posicion; i < ocupadas; i++ ){
        VoVPaciente[i] = VoVPaciente[i+1];
    }
    ocupadas--;
}

Paciente* VoVPacientes::getPosicion(int posicion) {
	   return VoVPaciente[posicion];
}

int VoVPacientes::getOcupadas() {
	return this->ocupadas;
}

bool VoVPacientes::estaVacio() {
    return (ocupadas == 0);
}

bool VoVPacientes::estaLleno() {
    return (ocupadas == MAXPacientes);

}

VoVPacientes::~VoVPacientes() {
	// TODO Auto-generated destructor stub
}

