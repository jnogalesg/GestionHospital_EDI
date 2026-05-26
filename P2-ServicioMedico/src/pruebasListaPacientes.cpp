/*
 * pruebasListaPacientes.cpp
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */

#include "pruebasListaPacientes.h"
#include <iostream>
using namespace std;

void pruebaConstructorLP() {
	ListaPacientes *lP = new ListaPacientes();
	if (!lP->estaVacia()){
		cerr<<"Error en constructor por defecto"<<endl;
	}
	delete lP;
}

void pruebaInsertarObtenerPrimeroLP() {
	ListaPacientes *lP = new ListaPacientes();
	Paciente *p;
	Paciente *p1 = new Paciente("Gema", "Gomez", "20212223A", Femenino, 16);

	lP->insertar(p1);
	lP->obtenerPrimero(p);
	if (p != p1){
		cerr<<"Error en insertar/obtener"<<endl;
	}
	if (!lP->estaVacia()){
		cerr<<"Error en obtener"<<endl;
	}

	delete lP;
	delete p;
	delete p1;
}

void pruebaContarExisteObtenerLP() {
	ListaPacientes *lP = new ListaPacientes();
	Paciente *p;
	Paciente *p1 = new Paciente("Gema", "Gomez", "20212223A", Femenino, 16);
	Paciente *p2 = new Paciente("Lucia", "Davila", "1234567T", Femenino, 21);

	lP->insertar(p1);
	if(lP->contar()!= 1){
		cerr<<"Error en contar"<<endl;
	}
	lP->insertar(p2);
	if(lP->contar()!= 2){
		cerr<<"Error en contar"<<endl;
	}

	if (!lP->existe("1234567T")){
		cerr<<"Error en existe"<<endl;
	}
	lP->obtenerPaciente("20212223A", p);
	if (p != p1){
		cerr<<"Error en obtenerPaciente"<<endl;
	}
	delete lP;
	delete p;
	delete p1;
	delete p2;
}

void pruebasListaPacientes(){
	pruebaConstructorLP();
	pruebaInsertarObtenerPrimeroLP();
	pruebaContarExisteObtenerLP();
}


