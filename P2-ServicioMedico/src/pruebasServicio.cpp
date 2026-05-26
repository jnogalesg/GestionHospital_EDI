/*
 * pruebasServicio.cpp
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */

#include "pruebasServicio.h"
#include <iostream>
using namespace std;

void pruebasConstructoresAsignarSer() {
	Servicio *ser1 = new Servicio();
	if (!ser1->estaVacia()){
		cerr<<"Error en constructor por defecto"<<endl;
	}
	ser1->asignarEspecialidad ("Neurología");
	ser1->mostrar();
	cout<<"Resultado esperado: Especialidad del Servicio: Neurología"<<endl;

	Medico *m = new Medico("Conchi", "Nogales", "Psicologia");
	Servicio *ser2 = new Servicio("Psicologia", m);
	ser2->mostrar();

	delete ser1;
	delete ser2;
}

void pruebasInsertarContar() {
	Medico *m = new Medico("Conchi", "Nogales", "Psicologia");
	Medico *mAux;
	Servicio *ser = new Servicio("Psicologia", m);
    Paciente *p = new Paciente("Mario", "Sanchez Anguas", "20202019F", Masculino, 19);
    Paciente *p1 = new Paciente("Maria", "Gutierrez", "1234567A", Femenino, 22);

    ser->insertar(1, p);
    if (ser->estaVaciaPrioridad(1)){
    	cerr<<"Error en insertar"<<endl;
    }
    if (ser->contarPrioridad(1) != 1){
    	cerr<<"Error en contar"<<endl;
    }
    ser->insertar(1, p1);
    if (ser->contarPrioridad(1) != 2){
    	cerr<<"Error en contar"<<endl;
    }
    mAux = ser->obtenerMedico();
    if(m != mAux){
    	cerr<<"Error en obtenerMedico"<<endl;
    }
}

void pruebasServicio() {
	//pruebasConstructoresAsignarSer();
	pruebasInsertarContar();
}
