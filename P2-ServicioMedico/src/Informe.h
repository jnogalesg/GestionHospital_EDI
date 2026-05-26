/*
 * Informe.h
 *
 *  Created on: 6 mar 2023
 *      Author: Jose Nogales
 */

#ifndef INFORME_H_
#define INFORME_H_
#include <iostream>
#include "Medico.h"
#include "FechaYHora.h"
using namespace std;

class Informe {
private:
	string informe;
	FechaYHora fecha;
	Medico *m;

public:
    // PRE: ---
    // DES: contructor por defecto
	// POST: inicializa los atributos informe y medico a su valor por defecto
    // COM: O(1)
	Informe();
    // PRE: f y m correctamente inicializados
    // DES: contructor parametrizado
	// POST: modifica: this->informe = informe, this->fecha = f, this->m = m
    // COM: O(1)
	Informe(string informe, const FechaYHora &f, Medico *m);
    // PRE: f correctamente inicializado
    // DES: contructor parametrizado
	// POST: inicializa los atributos para los que no existe un valor por defecto (fecha)
	// COM: O(1)
	Informe(const FechaYHora &f);
    // PRE: inf correctamente inicializado
    // DES: contructor por copia
	// POST: copia todos los atributos de un objeto inf
	// COM: O(1)
	Informe(Informe &inf);

    // PRE: ---
    // DES: modifica this->informe = informe;
    // COM: O(1)
	void setInforme(string informe);
    // PRE: ---
    // DES: modifica this->fecha = fecha;
    // COM: O(1)
	void setFecha(FechaYHora fecha);
    // PRE: ---
    // DES: modifica this->m = m;
    // COM: O(1)
	void setMedico(Medico *m);

    // PRE: ---
	// POST: devuelve informe
    // COM: ---
	string getInforme();
    // PRE: ---
	// POST: devuelve fecha
    // COM: O(1)
	FechaYHora getFecha();
    // PRE: ---
    // DES: devuelve m
    // COM: O(1)
	Medico* obtenerMedicoInf();
    // PRE: ---
    // DES: muestra por pantalla los datos del informe
    // COM: O(1)
	void mostrar();

    // PRE: ---
    // DES: destructor
	// POST: hace delete a m
    // COM: O(1)
	~Informe();
};

#endif /* INFORME_H_ */
