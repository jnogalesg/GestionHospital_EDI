/*
 * Servicio.h
 *
 *  Created on: 13 mar 2023
 *      Author: Jose Nogales
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_
#include <string>
#include <iostream>
#include "ColaPacientes.h"
using namespace std;

const int MAX_PRIORIDAD = 5; // 1..5
class Servicio {
private:
	string especialidad;
	ColaPacientes *colaPP [MAX_PRIORIDAD];
	Medico *m;
public:
    // PRE: ---
    // DES: contructor por defecto
	// POST: inicializa especialidad a su valor por defecto y hace new para las colas de prioridad
    // COM: O(n)
	Servicio ( );
    // PRE: ---
    // DES: constructor parametrizado
	// POST: inicializa especialidad segun el parametro introducido y hace new para las colas de prioridad
    // COM: O(n)
	Servicio ( string especialidad, Medico *m );
    // PRE: p correctamente inicializado, 0 < prioridad < MAX_PRIORIDADES
    // DES: inserta un paciente p en la cola de prioridad correspondiente
	// POST: devuelve true si esta vacia, false en caso contrario
    // COM: O(1)
	void insertar ( int prioridad, Paciente *p );
    // PRE: m correctamente inicializado
    // DES: asigna el medico introducido como parametro al servicio
	// POST: ---
    // COM: O(1)
	void asignarMedico ( Medico *m );
    // PRE: ---
    // DES: asigna la especialidad introducida como parametro al servicio
	// POST: ---
    // COM: O(1)
	void asignarEspecialidad ( string especialidad );
    // PRE: 0 < prioridad < MAX_PRIORIDADES
    // DES: comprueba si una cola de prioridad especifica esta vacia
	// POST: ---
    // COM: O(1)
	bool estaVaciaPrioridad ( int prioridad );
    // PRE: ---
    // DES: comprueba si todas las colas de prioridad estan vacias
	// POST: devuelve true si todas estan vacias, false en caso contrario
    // COM: O(n)
	bool estaVacia ( );
	// PRE:	---
	// DES: obtiene el primer paciente que encuentra en las colas de prioridad
	// POST: devuelve p
	// COM: O(n)
	void obtenerPaciente(Paciente *&p);
	// PRE:	---
	// DES: devuelve el medico asignado al servicio
	// POST: devuelve m
	// COM: O(n)
	Medico * obtenerMedico();
    // PRE: 0 < prioridad < MAX_PRIORIDADES
    // DES: muestra por pantalla los pacientes de una determinada prioridad
	// POST: ---
    // COM: O(n)
	void mostrarPrioridad ( int prioridad );
    // PRE: ---
    // DES: devuelve el numero de pacientes en espera con una determinada prioridad
	// POST: ---
    // COM: O(n)
	int contarPrioridad ( int prioridad );
    // PRE: ---
    // DES: muestra por pantalla la especialidad, medico asignado y pacientes del servicio
	// POST: ---
    // COM: O(n)
	void mostrar ( );
    // PRE: ---
    // DES: muestra por pantalla los pacientes del servicio
	// POST: ---
    // COM: O(n)
	void mostrarPacientes ( );

    // PRE: ---
    // DES: destructor
	// POST: libera el espacio de las colas (delete)
    // COM: O(n)
	~Servicio ( );
};

#endif /* SERVICIO_H_ */
