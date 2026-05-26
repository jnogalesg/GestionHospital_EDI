/*
 * Consulta.cpp
 *
 *  Created on: 13 feb. 2023
 *      Author: Jose Nogales
 */

#include "Consulta.h"

#include <iostream>
using namespace std;

Consulta::Consulta() {
	this->p = nullptr; //puntero nulo
	this->m = nullptr;
	this->tipo = Pendiente;
	this->alta = false;
	this->informe = "";
}

Consulta::Consulta(Paciente *p) {
    this->p = p;
    this->m = nullptr;
    this->tipo = Pendiente;
    this->alta = false;
    this->informe = "";
}

Consulta::Consulta(Paciente *p, Medico *m) {
    this->p = p;
    this->m = m;
    this->tipo = Pendiente;
    this->alta = false;
    this->informe = "";
}

Consulta::Consulta(Paciente *p, Medico *m, const FechaYHora &fh,  const tipoConsulta &tipo) {
	this->p = p;
	this->m = m;
	this->alta = false;
	this->fecha = fh;
    this->tipo = tipo;
    this->informe = "";
}

void Consulta::asignarMedico(Medico *unMedico) {
    this->m = unMedico;
}

void Consulta::agendarFecha(FechaYHora fecha) {
    this->fecha = fecha;
}

void Consulta::darDeAlta() {
    this->alta = true;
}

void Consulta::adjuntarInforme(string informe) {
    this->informe = informe;
}

Paciente *Consulta::getPaciente(){
    return p;
}

Medico *Consulta::getMedico(){
    return m;
}

FechaYHora Consulta::getFecha(){
    return fecha;
}

tipoConsulta Consulta::getTipo(){
    return tipo;
}

bool Consulta::getAlta(){
    return alta;
}

string Consulta::getInforme(){
    return informe;
}

void Consulta::mostrar() {
	cout <<"--------Consulta--------"<<endl;
    if (p == nullptr){
        cout<<"nullptr"<<endl;
    }   else{
	p->mostrar();
    }
	cout <<"Medico: ";
    if (m == nullptr){
        cout<<"nullptr"<<endl;
    }   else{
    m->mostrar();
    }
	cout <<"Fecha y hora: ";
	fecha.mostrar();
	cout <<"Tipo de consulta: ";
		if(tipo == Pendiente){
			cout<<"Pendiente"<<endl;
		} else if(tipo == Urgente){
			cout<<"Urgente"<<endl;
		} else {
			cout<<"Externa"<<endl;
		}
		if (alta == true){
			cout <<"El paciente tiene el Alta"<<endl;
		}	else cout <<"El paciente no tiene el Alta"<<endl;

	cout<<"Informe: "<<informe<<endl;

}

Consulta::~Consulta() {
    delete p;
    delete m;
}




