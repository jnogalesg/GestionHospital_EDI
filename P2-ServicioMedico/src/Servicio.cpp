/*
 * Servicio.cpp
 *
 *  Created on: 13 mar 2023
 *      Author: Jose Nogales
 */

#include "Servicio.h"

Servicio::Servicio() {
	especialidad = "";

	for (int i=0; i<MAX_PRIORIDAD; i++){
		colaPP[i] = new ColaPacientes( );
	}
	m = nullptr;
}

Servicio::Servicio(string especialidad, Medico *m) {
	this->especialidad = especialidad;
	this->m = m;

	for (int i=0; i<MAX_PRIORIDAD; i++){
		colaPP[i] = new ColaPacientes;
	}
}

void Servicio::insertar(int prioridad, Paciente *p) {
	colaPP[prioridad - 1]->insertar(p);
}

void Servicio::asignarMedico(Medico *m) {
	this->m = m;
}

void Servicio::asignarEspecialidad(string especialidad) {
	this->especialidad = especialidad;
}

bool Servicio::estaVaciaPrioridad(int prioridad) {
	return colaPP[prioridad - 1]->estaVacia();
}

bool Servicio::estaVacia() {
	bool vacia = true;
	for (int i=0; i<MAX_PRIORIDAD; i++){
		if (!colaPP[i]->estaVacia()){
			vacia = false;
		}
	}
	return vacia;
}

void Servicio::mostrarPrioridad(int prioridad) {
	colaPP[prioridad - 1]->mostrar();
}

void Servicio::mostrar() {
	cout<<"Especialidad del Servicio: "<<especialidad<<endl;
	cout<<endl;
	cout<<"*Medico asignado al Servicio: "<<endl;
	m->mostrar();

	cout<<endl;
	cout<<"Pacientes en espera de ser atendidos: "<<endl;
	for (int i=0; i<MAX_PRIORIDAD; i++){
		cout<<"------------- Pacientes con prioridad "<< i <<": -------------"<<endl;
		colaPP[i]->mostrar();
	}
}

void Servicio::mostrarPacientes() {
	cout<<"Pacientes en espera de ser atendidos: "<<endl;
	for (int i=0; i<MAX_PRIORIDAD; i++){
		cout<<"------------- Pacientes con prioridad "<< i <<": -------------"<<endl;
		colaPP[i]->mostrar();
	}
}

void Servicio::obtenerPaciente(Paciente *&p) {
	bool encontrado = false;

	for (int i = 0; i<MAX_PRIORIDAD; i++){
		if (!encontrado && !colaPP[i]->estaVacia()){
			p = colaPP[i]->obtener();
			encontrado = true;
		}
	}
}

Medico* Servicio::obtenerMedico() {
	return m;
}

int Servicio::contarPrioridad(int prioridad) {
	int cuenta = 0;
	cuenta = colaPP[prioridad-1]->contar();

	return cuenta;
}

Servicio::~Servicio() {
	for (int i=0; i<MAX_PRIORIDAD; i++){
		delete colaPP[i];
	}
	delete m;
}

