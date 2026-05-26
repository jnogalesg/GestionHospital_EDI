/*
 * Consulta.h
 *
 *  Created on: 13 feb. 2023
 *      Author: Jose Nogales
 */

#ifndef CONSULTA_H_
#define CONSULTA_H_
#include <iostream>
#include <string>
#include "Medico.h"
#include "Paciente.h"
#include "FechaYHora.h"
using namespace std;

enum tipoConsulta {Pendiente, Urgente, Externa};

class Consulta {
private:
	Paciente *p; //atributo dinámico, puntero al paciente (previamente creado)
	Medico *m; //atrib. dinámico, puntero al médico (previamente creado)
	FechaYHora fecha; //atrib. estático
	tipoConsulta tipo;
	bool alta;
	string informe;

public:
    // PRE: ---
    // DES: Constructor por defecto
    // POST: Crea una consulta con todos sus datos en valores por defecto
    // COM: O(1)
	Consulta();
    // PRE: p inicializado correctamente
    // DES: Constructor parametrizado
    // POST: Crea una consulta a partir del paciente p introducido, y sus demás campos con valores por defecto
    // COM: O(1)
    Consulta(Paciente *p);
    // PRE: p y m correctamente inicializados
    // DES: Constructor parametrizado
    // POST: Crea una consulta a partir del paciente p y medico m introducidos, y sus demás campos con valores por defecto
    // COM: O(1)
    Consulta(Paciente *p, Medico *m);
    // PRE: p, m y fh correctamente inicializados
    // DES: Constructor parametrizado
    // POST: Crea una consulta a partir de los parametros introducidos
    // COM: O(1)
	Consulta(Paciente *p, Medico *m, const FechaYHora &fh, const tipoConsulta &tipo);

	//------------setters-----------
    // PRE: unMedico inicializado correctamente
    // DES: asigna al medico m a la consulta
    // POST: modifica this->m = unMedico
    // COM: O(1)
	void asignarMedico(Medico *unMedico);
    // PRE: fecha inicializada correctamente
    // DES: cambia la fecha de la consulta a la fecha introducida como parametro
    // POST: modifica this->fecha = fecha
    // COM: O(1)
	void agendarFecha(FechaYHora fecha);
    // PRE: ---
    // DES: da de alta al paciente
    // POST: modifica this->alta = true
    // COM: O(1)
	void darDeAlta();
    // PRE: ---
    // DES: adjunta el informe introducido como parámetro a la consulta
    // POST: modifica this->informe = informe
    // COM: O(1)
	void adjuntarInforme(string informe);

    // PRE: ---
    // DES: Muestra por pantalla la información de la consulta
    // POST: ---
    // COM: O(1)
	void mostrar();

    // PRE: ---
    // DES: Devuelve el paciente apuntado por el puntero p
    // POST: return p
    // COM: O(1)
    Paciente *getPaciente();
    // PRE: ---
    // DES: Devuelve el medico apuntado por el puntero m
    // POST: return m
    // COM: O(1)
    Medico *getMedico();
    // PRE: ---
    // DES: Devuelve la fecha de la consulta
    // POST: return fecha
    // COM: O(1)
    FechaYHora getFecha();
    // PRE: ---
    // DES: Devuelve el tipo de consulta
    // POST: return tipo
    // COM: O(1)
    tipoConsulta getTipo();
    // PRE: ---
    // DES: Devuelve true si el paciente tiene el alta, false en caso contrario
    // POST: return alta
    // COM: O(1)
    bool getAlta();
    // PRE: ---
    // DES: Devuelve el informe de la consulta
    // POST: ---
    // COM: O(1)
    string getInforme();

    ~Consulta();
};

#endif /* CONSULTA_H_ */
