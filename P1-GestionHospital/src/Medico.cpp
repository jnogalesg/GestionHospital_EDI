/*
 * Medico.cpp
 *
 *  Created on: 12 feb. 2023
 *      Author: Jose Nogales
 */

#include "Medico.h"
using namespace std;

Medico::Medico() { //constructor
	nombre = "";
	apellidos = "";
	especialidad = "";

}

Medico::Medico(string nombre, string apellidos, string especialidad) {
	this->nombre = nombre;
	this->apellidos=apellidos;
	this->especialidad=especialidad;
}

Medico::Medico(const Medico &m) {
    this->nombre = m.nombre;
    this->apellidos = m.apellidos;
    this->especialidad = m.especialidad;
}

Medico::~Medico() {
}

void Medico::setNombre(string nombre) {
	this ->nombre = nombre;
}

void Medico::setApellidos(string apellidos) {
	this->apellidos=apellidos;
}

void Medico::setEspecialidad(string especialidad) {
	this->especialidad=especialidad;
}

string Medico::getNombre() {
	return nombre;

}

string Medico::getApellidos() {
	return apellidos;

}

string Medico::getEspecialidad() {
	return especialidad;

}

void Medico::mostrar() {
	string nombre;
	string apellidos;
	string especialidad;

	nombre = getNombre();
	apellidos = getApellidos();
	especialidad = getEspecialidad();

	cout <<"Nombre del medico: "<<nombre<<endl;
	cout <<"Apellidos del medico: "<<apellidos<<endl;
	cout <<"Especialidad: "<<especialidad<<endl;
}




