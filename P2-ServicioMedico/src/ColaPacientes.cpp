/*
 * ColaPacientes.cpp
 *
 *  Created on: 12 mar 2023
 *      Author: Jose Nogales
 */

#include "ColaPacientes.h"

ColaPacientes::ColaPacientes() {
	cP = new Cola <Paciente *>();
}

void ColaPacientes::insertar(Paciente *p) {
	cP->encolar(p);
}

void ColaPacientes::obtener(Paciente *&p) {
	cP->getPrimero(p);
	cP->desencolar();
}

Paciente* ColaPacientes::obtener() {
	Paciente *p = nullptr;
	p =  cP->getPrimero();
	cP->desencolar();
	return p;
}

bool ColaPacientes::estaVacia() {
	return cP->estaVacia();
}

void ColaPacientes::mostrar() {
	Cola <Paciente *> *cPAux = new Cola<Paciente *>;
	Paciente *p;

	while (!cP->estaVacia()){
		cP->getPrimero(p);
		cP->desencolar();
		cPAux->encolar(p);
		cout<<"**";
		p->mostrar();
	}
	while (!cPAux->estaVacia()){
		cPAux->getPrimero(p);
		cP->encolar(p);
		cPAux->desencolar();
	}
	delete cPAux;
}

int ColaPacientes::contar() {
	Cola <Paciente *> *cPAux = new Cola<Paciente *>;
	Paciente *p = nullptr;
	int cuenta = 0;

	while(!cP->estaVacia()){
		cP->getPrimero(p);
		cPAux->encolar(p);
		cP->desencolar();
		cuenta++;
	}
	while (!cPAux->estaVacia()){
		cPAux->getPrimero(p);
		cP->encolar(p);
		cPAux->desencolar();
	}
	return cuenta;
}

ColaPacientes::~ColaPacientes() {
	while (!cP->estaVacia()){
	cP->desencolar();
	}
	delete cP;
}

