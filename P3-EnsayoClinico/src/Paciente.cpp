/*
 * Paciente.cpp
 *
 *  Created on: 6 mar 2023
 *      Author: Jose Nogales
 */

#include "Paciente.h"

Paciente::Paciente() {  //contructor por defecto, inicializa
    nombre = ""; //asignamos cadena vacía.
    apellido = "";
    DNI = "";
    genero = noDefinido;
    edad = 0;
    puntuacion = 0;
}

Paciente::Paciente(string nombre, string apellido, string DNI, Genero genero,
		int edad) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->DNI = DNI;
    this->genero = genero;
    this->edad = edad;
    this->puntuacion = 0;
}

Paciente::Paciente(const Paciente &p) {
    this->nombre = p.nombre;
    this->apellido = p.apellido;
    this-> DNI = p.DNI;
    this->genero = p.genero;
    this->edad = p.edad;
    this->puntuacion = p.puntuacion;
}

void Paciente::setNombre(string nombre) {
	this -> nombre = nombre;
}

void Paciente::setApellidos(string apellido) {
	this -> apellido = apellido;
}

void Paciente::setDNI(string DNI) {
	this -> DNI = DNI;
}

void Paciente::setGenero(Genero genero) {
	this -> genero = genero;
}

void Paciente::setEdad(int edad) {
	this->edad = edad;
}

string Paciente::getNombre() {
	return nombre;
}

string Paciente::getApellido() {
	return apellido;
}

string Paciente::getDNI() {
	return DNI;
}

Genero Paciente::getGenero() {
	return genero;
}

int Paciente::getEdad() {
	return edad;
}

int Paciente::getPuntuacion() {
	return this->puntuacion;
}

void Paciente::anadirPuntuacion(int puntuacion) {
	this->puntuacion = puntuacion;
}

void Paciente::mostrar() {
	string nombre;
	string apellido;
	string DNI;
	Genero genero;
	int edad;
	int puntuacion;

	nombre = getNombre();
	apellido = getApellido();
	DNI = getDNI();
	genero = getGenero();
	edad = getEdad();
	puntuacion = getPuntuacion();

	cout << DNI << " # " <<
			nombre << " " <<
			apellido << " # " <<
			edad << " # ";
	if (genero == Masculino){
			cout <<"Hombre"<< " # ";
	} else if (genero == Femenino){
		cout <<"Femenino"<< " # ";
	} else{
		cout <<"noDefinido"<< " # ";
	}
	cout << puntuacion<<endl;

}


Paciente::~Paciente() {
}
