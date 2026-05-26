/*
 * EnsayoClinico.cpp
 *
 *  Created on: 28 abr 2023
 *      Author: Jose Nogales
 */

#include "ensayoclinico.h"

void EnsayoClinico::cargarPacientesAVector(Paciente *Vector[199]) {
	ifstream ifs;
	string nombre;
	string apellido;
	string DNI;
	string genero;
	string edad;
	Paciente *p = nullptr;
	int i = 0;

	ifs.open("pacientes_ordenados.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	}	else{
		while (!ifs.eof()) {
			getline(ifs, DNI, ';');
			if (!ifs.eof()) {
				getline(ifs, nombre, ';');
				getline(ifs, apellido, ';');
				getline(ifs, genero, ';');
				getline(ifs, edad, '\n');

				p = new Paciente(nombre, apellido, DNI, Genero ((stoi(genero))), (stoi(edad)));
				Vector[i] = p;
				i++;
			}
		}
		ifs.close();
	}
}

void EnsayoClinico::crearArbolPaciente(Paciente *Vector[199], int ini, int fin) {
	int medio;

	if (ini != fin){
		medio = ((fin-ini) / 2) + ini;
		KeyValue<string, Paciente*> kv(Vector[medio]->getDNI(), Vector[medio]);
		arbolPacientes->insertar(kv);
		crearArbolPaciente(Vector, ini, medio);
		crearArbolPaciente(Vector, medio+1, fin);
	}
}

EnsayoClinico::EnsayoClinico() {
	this->nombre = "Jose Nogales Gallardo";
	this->arbolPacientes = new BSTree<KeyValue<string, Paciente *>>() ;
	this->listaErrores = new ListaDPI <string>();

	Paciente *Vector[199];
	cargarPacientesAVector(Vector);
	crearArbolPaciente(Vector, 0, 199);
}

EnsayoClinico::~EnsayoClinico() {
	KeyValue<string, Paciente *> kv;
	Paciente *p;
	while (!arbolPacientes->estaVacio()){
		kv = arbolPacientes->getDato();
		p = kv.getValue();
		arbolPacientes->eliminar(kv);
		delete p;
	}

	delete arbolPacientes;

	while (!listaErrores->estaVacia()){
		listaErrores->moverPrimero();
		listaErrores->eliminar();
	}

	delete listaErrores;
}

void EnsayoClinico::mostrarPorApellido(string s_apellido) {
	if (!arbolPacientes->estaVacio()){
		mostrarPorApellido(this->arbolPacientes, s_apellido);
	}
}

void EnsayoClinico::mostrarPorApellido(BSTree<KeyValue<string, Paciente*> > *arbol, string s_apellido) {

	if (arbol->getIzq() != nullptr){
		mostrarPorApellido (arbol->getIzq(), s_apellido);
	}

	KeyValue<string, Paciente*> kv = arbol->getDato();
	Paciente *p = kv.getValue();
	string apellido = p->getApellido();

	if (apellido.find(s_apellido) != std::string::npos){
		p->mostrar();
	}

	if (arbol->getDer() != nullptr){
		mostrarPorApellido (arbol->getDer(), s_apellido);
	}
}

string EnsayoClinico::getNombre() {
	return nombre;
}


Paciente* EnsayoClinico::buscarPaciente(BSTree<KeyValue<string, Paciente*> > *arbol, string DNI) {
	Paciente *p;
	if ( !arbol->estaVacio ( ) ) {
		if (DNI == arbol->getDato().getKey()){
			p = arbol->getDato().getValue();
		}else if (DNI < arbol->getDato().getKey()){
			p = buscarPaciente(arbol->getIzq(), DNI);
		} else if(DNI > arbol->getDato().getKey()){
			p = buscarPaciente(arbol->getDer(), DNI);
		}
	}
	return p;
}

bool EnsayoClinico::existeListaErrores(string DNI) {
	string DNILista;
	bool enc = false;

	listaErrores->moverPrimero();
	if (listaErrores->estaVacia()){
		enc = false;
	}else {
		while(!listaErrores->alFinal() && !enc){
			DNILista = listaErrores->consultar();
			if(DNI == DNILista){
				enc = true;
			} else{
				listaErrores->avanzar();
			}
		}
	}

	return enc;
}

void EnsayoClinico::anotar() {
	ifstream ifs;
	string DNI;
	string puntuacion;

	ifs.open("ensayo.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	}	else{
		while (!ifs.eof()) {
			getline(ifs, DNI, ';');
			if (!ifs.eof()) {
				getline(ifs, puntuacion, '\n');

				KeyValue<string, Paciente*> kv(DNI, nullptr);
				if (arbolPacientes->existe(kv)){

					Paciente *p = buscarPaciente(arbolPacientes, DNI);
					p->anadirPuntuacion(stoi(puntuacion));
				} else{
					if (!existeListaErrores(DNI)){
						listaErrores->insertar(DNI);
					}
				}
			}
		}
		ifs.close();
	}
}

int EnsayoClinico::numNiveles() {
	return numNiveles (arbolPacientes);
}

void EnsayoClinico::mostrarErrores() {
	string DNI;

	listaErrores->moverPrimero();
	while (!listaErrores->alFinal()){
		DNI = listaErrores->consultar();
		cout<< DNI <<endl;
		listaErrores->avanzar();
	}
}

void EnsayoClinico::mostrarMayores(int cuantos) {

	BSTree<KeyValue<string, Paciente*> > *arbol (arbolPacientes);
	mayoresR(arbol, cuantos);
}

void EnsayoClinico::mayoresR(BSTree<KeyValue<string, Paciente*> > *arbol, int cuantos) {
	Paciente *p = new Paciente();
	if (!arbol->estaVacio() && cuantos > 0){
		if ( arbol->getDer ( ) == nullptr ) {
			p = arbol->getDato( ).getValue();
			p->mostrar();
			arbol->eliminar(arbol->getDato( ));
		}
		else {
			p = arbol->getDato().getValue();
			p->mostrar();
			arbol->eliminar(arbol->getDato( ));
			mayoresR( arbol->getDer ( ), cuantos-1 );
		}
	}
}

void EnsayoClinico::mostrarPorDNI(string s_dni) {

	if (!arbolPacientes->estaVacio()){
		mostrarEnOrdenDNI(arbolPacientes, s_dni);
	}
}

void EnsayoClinico::mostrarEnOrdenDNI(BSTree<KeyValue<string, Paciente*> > *arbol, string s_dni) {

	if (!arbol->estaVacio()){

		if(arbol->getIzq () != nullptr){
			mostrarEnOrdenDNI(arbol->getIzq(), s_dni);
		}

		KeyValue<string, Paciente*> kv = arbol->getDato();
		Paciente *p = kv.getValue();
		string DNI = p->getDNI();

		if (DNI.find(s_dni) == 0){
			p->mostrar();
		}

		if (arbol->getDer() != nullptr){
			mostrarEnOrdenDNI (arbol->getDer(), s_dni);
		}
	}
}

int EnsayoClinico::numNiveles(BSTree<KeyValue<string, Paciente*> > *arbol) {
	int nivel = 0;
	int nivel_izq = 0;
	int nivel_der = 0;
	if ( !arbol->estaVacio ( ) ) {
		if ( arbol->getIzq ( ) != nullptr )
			nivel_izq = numNiveles ( arbol->getIzq ( ) );
		if ( arbol->getDer ( ) != nullptr )
			nivel_der = numNiveles ( arbol->getDer ( ) );
		nivel = max ( nivel_izq, nivel_der ) + 1;
	}
	return nivel;
}
