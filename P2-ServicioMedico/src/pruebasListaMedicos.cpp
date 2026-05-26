/*
 * pruebasListaMedicos.cpp
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */

#include "pruebasListaMedicos.h"
#include <iostream>
using namespace std;

void pruebaConstructorLM(){
	ListaMedicos *lM = new ListaMedicos();
	if (!lM->estaVacia()){
		cerr<<"Error en constructor por defecto"<<endl;
	}
	delete lM;
}


void pruebaInsertarObtenerPrimeroLM(){
	ListaMedicos *lM = new ListaMedicos();
	Medico *m;
	Medico *m1 = new Medico("Rosa", "Jimenez", "Oftalmología");

	lM->insertar(m1);
	lM->obtenerPrimero(m);
	if (m != m1){
		cerr<<"Error en insertar/obtener"<<endl;
	}
	if (!lM->estaVacia()){
		cerr<<"Error en obtener"<<endl;
	}
	delete lM;
	delete m;
	delete m1;
}

void pruebaContarExisteObtenerLM(){
	ListaMedicos *lM = new ListaMedicos();
	Medico *m;
	Medico *m1 = new Medico("Rosa", "Jimenez", "Oftalmología");
	Medico *m2 = new Medico("Nieves", "Vazquez", "Traumatología");

	lM->insertar(m1);
	if(lM->contar()!= 1){
		cerr<<"Error en contar"<<endl;
	}
	lM->insertar(m2);
	if(lM->contar()!= 2){
		cerr<<"Error en contar"<<endl;
	}

	if (!lM->existe("Vazquez")){
		cerr<<"Error en existe"<<endl;
	}
	lM->obtenerMedico("Jimenez", m);
	if (m != m1){
		cerr<<"Error en obtenerMedico"<<endl;
	}
	lM->obtenerMedicoEsp("Traumatología", m);
	if (m != m2){
		cerr<<"Error en obtenerMedicoEsp"<<endl;
	}
	delete lM;
	delete m;
	delete m1;
	delete m2;
}


void pruebasListaMedicos(){
	pruebaConstructorLM();
	pruebaInsertarObtenerPrimeroLM();
	pruebaContarExisteObtenerLM();
}
