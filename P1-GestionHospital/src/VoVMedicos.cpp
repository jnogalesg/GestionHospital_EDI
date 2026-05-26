/*
 * VoVMedicos.cpp
 *
 *  Created on: 27 feb 2023
 *      Author: Jose Nogales
 */

#include "VoVMedicos.h"

VoVMedicos::VoVMedicos() {
    this->ocupadas = 0;
    VoVMedico[ocupadas] = new Medico;
}

void VoVMedicos::insertar(Medico *m) {
    this->VoVMedico[this->ocupadas] = m;
    ocupadas++;
}

void VoVMedicos::borrar(int posicion) {
    for ( int i = posicion; i < ocupadas; i++ ){
        VoVMedico[i] = VoVMedico[i+1];
    }
    ocupadas--;
}

Medico* VoVMedicos::getPosicion(int posicion) {
	   return VoVMedico[posicion];
}

int VoVMedicos::getOcupadas() {
    return this->ocupadas;
}

bool VoVMedicos::estaVacio() {
    return (ocupadas == 0);
}

bool VoVMedicos::estaLleno() {
    return (ocupadas == MAXMedicos);
}

VoVMedicos::~VoVMedicos() {

}

