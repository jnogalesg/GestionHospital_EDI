/*
 * Hospital.h
 *
 *  Created on: 27 feb 2023
 *      Author: Jose Nogales
 */

#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include <iostream>
#include "VoVConsultas.h"
#include "VoVPacientes.h"
#include "VoVMedicos.h"
#include <string>
#include <fstream>
using namespace std;

class Hospital {
private:
	string nombre;

	VoVPacientes *pacientes;
	VoVMedicos *medicos;
	VoVConsultas *consultas;

public:
    // PRE: ---
    // DES: Constructor por defecto
    // POST: Crea un objeto de la clase hospital con sus atributos inicializados a valores por defecto
    // COM: O(1)
	Hospital();
    // PRE: ---
    // DES: Constructor parametrizado
    // POST: Crea un objeto de la clase hospital con this->nombre = nombre
	// 		 e inicializa el resto de atributos a sus valores por defecto
    // COM: O(1)
	Hospital(string nombre);
    // PRE: ---
    // DES: Destructor
    // POST: Libera la memoria ocupada por los atributos del hospital
    // COM: O(n)
	~Hospital();


    // PRE: pacientes->estaVacio == false
    // DES: Muestra por pantalla la información de los pacientes
    // POST: ---
    // COM: O(n)
	void mostrarPacientes();
    // PRE: medicos->estaVacio == false
    // DES: Muestra por pantalla la información de los medicos
    // POST: ---
    // COM: O(n)
	void mostrarMedicos();
    // PRE: consultas->estaVacio == false
    // DES: Muestra por pantalla la información de las consultas
    // POST: ---
    // COM: O(n)
	void mostrarConsultas();
    // PRE: pacientes->estaVacio == false
    // DES: Busca y devuelva al paciente cuyo DNI coincida con el introducido como parametro
    // POST: ---
    // COM: O(n)
	Paciente * buscarPaciente(string DNI);
    // PRE: medicos->estaVacio == false
    // DES: Busca y devuelva al medico cuyos apellidos coincidan con el apellido introducido como parametro
    // POST: ---
    // COM: O(n)
	Medico * buscarMedico(string apellido);
    // PRE: ---
    // DES: Carga la informacion del fichero pacientes.csv al vector pacientes
    // POST: el vector pacientes contiene a los pacientes del fichero
    // COM: O(n)
	void cargarPacientes();
    // PRE: ---
    // DES: Carga la informacion del fichero medicos.csv al vector medicos
    // POST: el vector medicos contiene a los medicos del fichero
    // COM: O(n)
	void cargarMedicos();
    // PRE: ---
    // DES: Carga la informacion del fichero consultas.csv al vector consultas
    // POST: el vector consultas contiene las consultas del fichero
    // COM: O(n)
	void cargarConsultas();
    // PRE: ---
    // DES: Muestra por pantalla el numero de pacientes, medicos y consultas del hospital
    // POST: ---
    // COM: O(1)
	void mostrarEstadisticas();
    // PRE: ---
    // DES: Devuelve el nombre del hospital
    // POST: return nombre
    // COM: O(1)
	string getNombre();
    // PRE: ---
    // DES: Guarda en un fichero (DNIPaciente.txt) todas las consultas programadas de ese paciente
    // POST: Crea un fichero con las consultas, incluyendo nombre y apellidos del medico, especialidad y la fecha
    // COM: O(n)
	void crearFicheroPaciente(Paciente *p);


};

#endif /* HOSPITAL_H_ */
