/*
 * pruebasEnsayoClinico.cpp
 *
 *  Created on: 11 may 2023
 *      Author: Jose Nogales
 */

#include "pruebasEnsayoClinico.h"
#include <iostream>
using namespace std;

void pruebasConstructor() {
	EnsayoClinico *ec = new EnsayoClinico();

	if (ec->numNiveles() != 8){
		cerr << "Error al obtener el numero de niveles"<<endl;
	}
	if (ec->getNombre() != "Jose Nogales Gallardo"){
		cerr << "Error al obtener el nombre del ensayo"<<endl;
	}
}


void pruebasMostrarErroresYAnotar() {
	EnsayoClinico *ec = new EnsayoClinico();
	ec->mostrarErrores();
	cout <<"Caso 1: No se muestra ningun error, porque no se ejecuta ec->anotar()"<<endl;
	ec->anotar();
	ec->mostrarErrores();
	cout <<"Caso 2: Resultado esperado Errores en pacientes:"<<endl;
	cout <<"17281002S"<<endl;
	cout <<"11324230Z"<<endl;
	cout <<"99217882B"<<endl;
	cout <<"99812892J"<<endl;
	cout <<"73092301G"<<endl;
}

void pruebaMostrarMayores() {
	EnsayoClinico *ec = new EnsayoClinico();
	ec->mostrarMayores(10);
	cout <<"Resultado esperado: "<<endl;
	cout <<"47595928T # Daniel Jiménez Fernández # 22 # Femenino # 181002S"<<endl;
	cout <<"77580810V # Víctor Serrano Pérez # 21 # noDefinido # 0"<<endl;
	cout <<"90216452V # Miguel Prieto Prieto # 25 # noDefinido # 1"<<endl;
	cout <<"95724631E # Pablo Fernández Rollán # 26 # Femenino # 0"<<endl;
	cout <<"97358547N # David Conesa Cañamero # 21 # Hombre # 1"<<endl;
	cout <<"98911238Q # Adrián Miranda García # 24 # Hombre # 0"<<endl;
	cout <<"99939379X # Joel Estrella Berrocal # 17 # noDefinido # 0"<<endl;
}

void pruebasMostrarPorApellido() {
	EnsayoClinico *ec = new EnsayoClinico();
	ec->mostrarPorApellido("xzy");
	cout<<"Resultado esperado caso 1: no se muestra ningun paciente (ningun apellido contiene la subcadena xyz)"<<endl;
	ec->mostrarPorApellido("Nog");
	cout << "Resultado esperado caso 2 : 89020897Z # José Nogales Gallardo # 17 # noDefinido # 2"<<endl;
}

void pruebasMostrarPorDNI() {
	EnsayoClinico *ec = new EnsayoClinico();
	ec->mostrarPorDNI("910");
	cout<<"Resultado esperado caso 1: no se muestra ningun paciente (ningun DNI comienza por la subcadena 910)"<<endl;
	ec->mostrarPorDNI("8902");
	cout<<"Resultado esperado caso 2: 89020897Z # José Nogales Gallardo # 17 # noDefinido # 2"<<endl;
}

void pruebasEnsayoClinico() {
	pruebasConstructor();
	pruebasMostrarErroresYAnotar();
	pruebaMostrarMayores();
	pruebasMostrarPorApellido();
	pruebasMostrarPorDNI();
}

