//
// Created by Jose Nogales on 06/02/2023.
// paciente.cpp
//

#include "Paciente.h"

Paciente::Paciente() {  //contructor por defecto, inicializa
    nombre = ""; //asignamos cadena vacía.
    apellido = "";
    DNI = "";
    genero = noDefinido;
    edad = 0;
}

Paciente::Paciente(string nombre, string apellido, string DNI, Genero genero, int edad) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->DNI = DNI;
    this->genero = genero;
    this->edad = edad;
}

Paciente::Paciente(const Paciente &p) {
    this->nombre = p.nombre;
    this->apellido = p.apellido;
    this-> DNI = p.DNI;
    this->genero = p.genero;
    this->edad = p.edad;
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

void Paciente::mostrar() {
	string nombre;
	string apellido;
	string DNI;
	Genero genero;
	int edad;

	nombre = getNombre();
	apellido = getApellido();
	DNI = getDNI();
	genero = getGenero();
	edad = getEdad();

	cout <<"Nombre del paciente: "<<nombre<<endl;
	cout <<"Apellido del paciente: "<<apellido<<endl;
	cout <<"DNI del paciente: "<<DNI<<endl;
	cout <<"Genero del paciente: ";
    if (genero == 0){
        cout<<"Masculino"<<endl;
    } else if (genero == 1){
        cout<<"Femenino"<<endl;
    } else cout<<"noDefinido"<<endl;
    cout <<"Edad del paciente: "<<edad<<endl;

}


Paciente::~Paciente() {

}
