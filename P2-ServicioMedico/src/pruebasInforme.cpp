/*
 * pruebasInforme.cpp
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */
#include "pruebasInforme.h"
#include <iostream>
using namespace std;

void pruebasInforme(){
	//caso 1: constructor por defecto
	Informe *inf1 = new Informe();
	if (inf1->getInforme() != ""){
		cerr<<"Error en set/getInforme"<<endl;
	}
	if (inf1->obtenerMedicoInf() != nullptr){
		cerr<<"Error en set/getMedico"<<endl;
	}

	//caso 2: constructor parametrizado
	Medico *m1 = new Medico("Chelo", "Gallardo", "Oftalmologia");
	FechaYHora f1(5, 4, 2023, 17, 45);

	Informe *inf2 = new Informe("Informe de prueba", f1, m1);

	if (inf2->getInforme() != "Informe de prueba"){
		cerr<<"Error en set/getInforme"<<endl;
	}
	if (inf2->obtenerMedicoInf() != m1){
		cerr<<"Error en set/getMedico"<<endl;
	}
	if (inf2->getFecha() == f1){
	}	else{
		cerr<<"Error en set/getFecha"<<endl;
	}

	//caso 3: constructor por copia
	Informe *inf3 = new Informe(*inf2);
	if (inf3->getInforme() != "Informe de prueba"){
		cerr<<"Error en set/getInforme"<<endl;
	}
	if (inf3->obtenerMedicoInf() != m1){
		cerr<<"Error en set/getMedico"<<endl;
	}
	if (inf3->getFecha() == f1){
	}	else{
		cerr<<"Error en set/getFecha"<<endl;
	}

	//caso 4: pruebas setter/getter
	Medico *m2 = new Medico("Matias", "Nogales", "Traumatología");
	FechaYHora f2(9, 3, 2023, 20, 45);

	inf2->setFecha(f2);
	inf2->setInforme("Prueba de Informe");
	inf2->setMedico(m2);

	if (inf2->getInforme() != "Prueba de Informe"){
		cerr<<"Error en set/getInforme"<<endl;
	}
	if (inf2->obtenerMedicoInf() != m2){
		cerr<<"Error en set/getMedico"<<endl;
	}
	if (inf2->getFecha() == f2){
	}	else{
		cerr<<"Error en set/getFecha"<<endl;
	}
	delete inf1;
	delete inf2;
	delete inf3;
	delete m1;
	delete m2;
}


