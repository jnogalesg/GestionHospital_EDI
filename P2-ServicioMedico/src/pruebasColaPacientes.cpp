/*
 * pruebasColaPacientes.cpp
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */

#include "pruebasColaPacientes.h"
#include <iostream>
using namespace std;

void pruebasConstructor() {
	ColaPacientes *cP = new ColaPacientes();
	if (!cP->estaVacia()){
		cerr<<"Error en constructor por defecto"<<endl;
	}
	delete cP;
}

void insertarObtener() {
	ColaPacientes *cP = new ColaPacientes();
	Paciente *p1 = new Paciente("Joaquin", "Palomo", "20212223A", Masculino, 27);
	cP->insertar(p1);
	if (cP->obtener() != p1){
		cerr<<"Error en insertar/obtener"<<endl;
	}
	delete cP;
	delete p1;
}

void pruebasContar(){
	ColaPacientes *cP = new ColaPacientes();
	Paciente *p1 = new Paciente("Joaquin", "Palomo", "20212223A", Masculino, 27);
	Paciente *p2 = new Paciente("Jaime", "Moreno", "21222324B", Masculino, 27);

	cP->insertar(p1);
	if (cP->contar() != 1){
		cerr<<"Error en contar"<<endl;
	}
	cP->insertar(p2);
	if (cP->contar() != 2){
		cerr<<"Error en contar"<<endl;
	}
	delete cP;
	delete p1;
	delete p2;
}

void pruebaMostrar(){
	ColaPacientes *cP = new ColaPacientes();
	Paciente *p1 = new Paciente("Joaquin", "Palomo", "20212223A", Masculino, 27);
	Paciente *p2 = new Paciente("Jaime", "Moreno", "21222324B", Masculino, 27);
	cP->insertar(p1);
	cP->insertar(p2);
	cP->mostrar();
	cout<<endl;
	cout<<"---------Resultado esperado: ---------"<<endl;
	cout<<"**Nombre del paciente: Joaquin"<<endl;
	cout<<"Apellido del paciente: Palomo"<<endl;
	cout<<"DNI del paciente: 20212223A"<<endl;
	cout<<"Genero del paciente: Masculino"<<endl;
	cout<<"Edad del paciente: 27"<<endl;
	cout<<"Informes del paciente: "<<endl;
	cout<<endl;
	cout<<"**Nombre del paciente: Jaime"<<endl;
	cout<<"Apellido del paciente: Moreno"<<endl;
	cout<<"DNI del paciente: 21222324B"<<endl;
	cout<<"Genero del paciente: Masculino"<<endl;
	cout<<"Edad del paciente: 27"<<endl;
	cout<<"Informes del paciente: "<<endl;

	delete cP;
	delete p1;
	delete p2;
}
void pruebasColaPacientes() {
	pruebasConstructor();
	insertarObtener();
	pruebasContar();
	pruebaMostrar();
}
