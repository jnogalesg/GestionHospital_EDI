/*
 * Hospital.h
 *
 *  Created on: 20 mar 2023
 *      Author: Jose Nogales
 */

#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "ListaPacientes.h"
#include "ListaMedicos.h"
#include "PilaInformes.h"
#include "Servicio.h"
using namespace std;

class Hospital {
private:
	string nombre;
	ListaPacientes *lP;
	ListaMedicos *lM;
	Servicio *ser;

	void cargarPacientes ( );
	void cargarMedicos ( );
	void cargarInformes ( );
public:
	//PRE = ---
	//DESC = Constructor por defecto
	//POST = Inicializa los atributos a sus valores por defecto (hace new a las listas)
	//COM = O(1)
	Hospital ( );
	//PRE = ---
	//DESC = Constructor parametrizado
	//POST = Inicializa el atributo this->nombre = nombre, y hace new a las listas
	//COM = O(1)
	Hospital ( string nombre );
	//PRE = ---
	//DESC = Muestra por pantalla las estadisticas del hospital
	//POST = Muestra por pantalla el nº de pacientes, medicos y pacientes en cada lista de prioridad
	//COM = O(1)
	void mostrarEstadisticas( );
	//PRE = ---
	//DESC = Muestra por pantalla todos los pacientes de la lista
	//POST = ---
	//COM = O(1)
	void mostrarPacientes ( );
	//PRE = ---
	//DESC = Muestra por pantalla todos los medicos de la lista
	//POST = ---
	//COM = O(1)
	void mostrarMedicos ( );
	//PRE = ---
	//DESC = Muestra por pantalla todos los pacientes en espera a ser atendidos en el Servicio
	//POST = ---
	//COM = O(1)
	void mostrarServicio ( );
	//PRE = ---
	//DESC = devuelve al paciente de la lista de pacientes con el dni introducido
	//POST = devuelve p
	//COM = O(1)
	Paciente * obtenerPaciente ( );
	//PRE = ---
	//DESC = Devuelve al medico de la lista de medicos con el apellido introducido
	//POST = devuelve m
	//COM = O(1)
	Medico * obtenerMedico ( );
	//PRE = ---
	//DESC = Asigna al servicio a un medico de la especialidad de este
	//POST = ---
	//COM = o(1)
	void asignarMedico ( );
	//PRE = ---
	//DESC = Procesa la cola de pacientes del servicio
	//POST = Obtiene a los pacientes, les genera un informe
	//COM = O(n)
	void procesarColas ( );
	//PRE = ---
	//DESC = devuelve un string con la fecha y hora actual del sistema
	//POST = ---
	//COM = O(1)
	string obtenerFechaHora ( );
	//PRE = ---
	//DESC = devuelve el nombre del hospital
	//POST = devuelve this->nombre
	//COM = O(1)
	string getNombre ( );

	~Hospital ( );
};

#endif /* HOSPITAL_H_ */
