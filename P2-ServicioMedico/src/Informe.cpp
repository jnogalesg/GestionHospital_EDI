/*
 * Informe.cpp
 *
 *  Created on: 6 mar 2023
 *      Author: Jose Nogales
 */

#include "Informe.h"

Informe::Informe() {
	informe = "";
	m = nullptr;
}

Informe::Informe(string informe, const FechaYHora &f, Medico *m) {
	this-> informe = informe;
	this->fecha = f;
	this->m = m;
}


Informe::Informe(const FechaYHora &f) {
	this->informe = "";
	this->fecha = f;
	this->m = nullptr;
}

Informe::Informe(Informe &inf) {
	this->informe = inf.informe;
	this->fecha = inf.fecha;
	this->m = inf.m;
}

void Informe::setInforme(string informe) {
	this->informe = informe;
}

void Informe::setFecha(FechaYHora fecha) {
	this->fecha = fecha;
}

void Informe::setMedico(Medico *m) {
	this-> m = m;
}

string Informe::getInforme() {
	return informe;
}

FechaYHora Informe::getFecha() {
	return fecha;
}

Medico* Informe::obtenerMedicoInf() {
	return m;
}

void Informe::mostrar() {
	cout <<"Informe del Paciente: "<<informe<<endl;
	cout <<"Fecha: ";
			fecha.mostrar();
			cout<<endl;
	cout <<"Medico: ";
			m->mostrar();
			cout<<endl;
}


Informe::~Informe() {
	delete m;
}

