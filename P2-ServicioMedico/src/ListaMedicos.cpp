/*
 * ListaMedicos.cpp
 *
 *  Created on: 20 mar 2023
 *      Author: Jose Nogales
 */

#include "ListaMedicos.h"

ListaMedicos::ListaMedicos() {
	lMedicos = new ListaDPI <Medico *>();
}

void ListaMedicos::insertar(Medico *m) {
	bool enc = false;
	Medico *mAux;
	lMedicos->moverPrimero();

	while(!lMedicos->alFinal() && !enc){
		mAux = lMedicos->consultar();
		if(mAux->getApellidos() < m->getApellidos()){
			enc = true;
		} else
			lMedicos->avanzar();
	}
	lMedicos->insertar(m);
}

bool ListaMedicos::existe(string apellido) {
	bool enc = false;
	Medico *mAux;

	lMedicos->moverPrimero();
	while(!lMedicos->alFinal() && !enc){
		mAux = lMedicos->consultar();
		if (apellido == mAux->getApellidos()){
			enc = true;
		}	else
		lMedicos->avanzar();
	}
	return enc;
}

void ListaMedicos::obtenerMedico(string apellido, Medico *&m) {
	bool enc = false;

	lMedicos->moverPrimero();
	while(!lMedicos->alFinal() && !enc){
		m = lMedicos->consultar();
		if (apellido == m->getApellidos()){
			enc = true;
		}	else
		lMedicos->avanzar();
	}
	if (lMedicos->alFinal() && !enc){
		m = nullptr;
	}
}

void ListaMedicos::obtenerMedicoEsp(string especialidad, Medico *&m) {
	bool enc = false;

	lMedicos->moverPrimero();
	while(!lMedicos->alFinal() && !enc){
		m = lMedicos->consultar();
		if (especialidad == m->getEspecialidad()){
			enc = true;
		}	else
		lMedicos->avanzar();
	}
	if (lMedicos->alFinal() && !enc){
		m = nullptr;
	}
}

void ListaMedicos::obtenerPrimero(Medico *&m) {
	lMedicos->moverPrimero();
	m = lMedicos->consultar();
	lMedicos->eliminar();

}

bool ListaMedicos::estaVacia() {
	bool vacia = false;
	lMedicos->moverPrimero();
	if(lMedicos->alFinal()){
		vacia = true;
	}
	return vacia;
}

int ListaMedicos::contar() {
	int numElementos = 0;

	lMedicos->moverPrimero();
	while (!lMedicos->alFinal()){
		numElementos++;
		lMedicos->avanzar();
	}
	return numElementos;
}

void ListaMedicos::mostrar() {
	Medico *mAux;

	lMedicos->moverPrimero();
		while(!lMedicos->alFinal()){
		mAux = lMedicos->consultar();
		mAux->mostrar();
		lMedicos->avanzar();
	}
}

void ListaMedicos::mostrarRec(ListaDPI<Medico*> *l) {
	Medico * mAux;
	if (!l->alFinal()){
		mAux = l->consultar();
		mAux->mostrar();
		l->avanzar();
		mostrarRec(l);
	}
}

void ListaMedicos::mostrarR() {
	if(!lMedicos->estaVacia()){
		lMedicos->moverPrimero();
		mostrarRec(lMedicos);
	}
}

ListaMedicos::~ListaMedicos() {
	while (!lMedicos->estaVacia()){
		lMedicos->moverPrimero();
		lMedicos->eliminar();
	}
	delete lMedicos;
}

