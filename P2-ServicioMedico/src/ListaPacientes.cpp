/*
 * ListaPacientes.cpp
 *
 *  Created on: 17 mar 2023
 *      Author: Jose Nogales
 */

#include "ListaPacientes.h"

ListaPacientes::ListaPacientes() {
	lPacientes = new ListaDPI <Paciente *>();
}

void ListaPacientes::insertar(Paciente *p) {
	bool enc = false;
	Paciente *pAux;
	lPacientes->moverPrimero();

	while(!lPacientes->alFinal() && !enc){
		pAux = lPacientes->consultar();
		if(pAux->getDNI() < p->getDNI()){
			enc = true;
		} else
			lPacientes->avanzar();
	}
	lPacientes->insertar(p);
}

bool ListaPacientes::existe(string DNI) {
	bool enc = false;
	Paciente *pAux;
	lPacientes->moverPrimero();

	while(!lPacientes->alFinal() && !enc){
		pAux = lPacientes->consultar();
		if (DNI == pAux->getDNI()){
			enc = true;
		}	else
		lPacientes->avanzar();
	}
	return enc;
}

void ListaPacientes::obtenerPaciente(string DNI, Paciente *&p) {
	bool enc = false;

	lPacientes->moverPrimero();
	while(!lPacientes->alFinal() && !enc){
		p = lPacientes->consultar();
		if (DNI == p->getDNI()){
			enc = true;
		}	else
		lPacientes->avanzar();
	}
	if (lPacientes->alFinal() && !enc){
		p = nullptr;
	}
}

void ListaPacientes::obtenerPrimero(Paciente *&p) {
	lPacientes->moverPrimero();
	p = lPacientes->consultar();
	lPacientes->eliminar();
}

bool ListaPacientes::estaVacia() {
	bool vacia = false;
	lPacientes->moverPrimero();
	if(lPacientes->alFinal()){
		vacia = true;
	}
	return vacia;
}

int ListaPacientes::contar() {
	int numElementos = 0;

	lPacientes->moverPrimero();
	while (!lPacientes->alFinal()){
		numElementos++;
		lPacientes->avanzar();
	}
	return numElementos;
}

void ListaPacientes::mostrar() {
	Paciente *pAux;

	lPacientes->moverPrimero();
	while(!lPacientes->alFinal()){
		pAux = lPacientes->consultar();
		pAux->mostrar();
		lPacientes->avanzar();
	}
}

void ListaPacientes::mostrarRec(ListaDPI<Paciente*> *l) {
	Paciente *pAux;
	if (!l->alFinal()){
		pAux = l->consultar();
		pAux->mostrar();
		l->avanzar();
		mostrarRec(l);
	}
}

void ListaPacientes::mostrarR() {
	if(!lPacientes->estaVacia()){
		lPacientes->moverPrimero();
		mostrarRec(lPacientes);
	}
}

ListaPacientes::~ListaPacientes() {
	while (!lPacientes->estaVacia()){
		lPacientes->moverPrimero();
		lPacientes->eliminar();
	}
	delete lPacientes;
}


