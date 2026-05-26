/*
 * ColaPacientes.h
 *
 *  Created on: 12 mar 2023
 *      Author: josen
 */

#ifndef COLAPACIENTES_H_
#define COLAPACIENTES_H_
#include "Cola.h"
#include "Paciente.h"
#include <iostream>
using namespace std;

class ColaPacientes {
private:
	Cola <Paciente *> *cP;
public:
    // PRE: ---
    // DES: constructor por defecto
	// POST: inicializa cP llamando al constructor por defecto de la clase cola
    // COM: O(1)
	ColaPacientes ( );
    // PRE: ---
    // DES: encola a un paciente p en cP
	// POST: ---
    // COM: O(1)
	void insertar ( Paciente *p );
    // PRE: ---
    // DES: devuelve en p al primer paciente de la cola y lo desencola
	// POST: ---
    // COM: O(1)
	void obtener ( Paciente *&p );
    // PRE: ---
    // DES: devuelve el numero de pacientes que hay en la cola
	// POST: ---
    // COM: O(1)
	int contar ();
    // PRE: ---
    // DES: devuelve al primer paciente de la cola y lo desencola
	// POST: ---
    // COM: O(1)
	Paciente * obtener ( );
    // PRE: ---
    // DES: ---
	// POST: devuelve TRUE si la cola esta vacia, FALSE en caso contrario
    // COM: O(1)
	bool estaVacia ( );
    // PRE: ---
    // DES: Muestra todos los elementos de la cola por pantalla
	// POST: ---
    // COM: O(n)
	void mostrar ( );

    // PRE: ---
    // DES: destructor
	// POST: ---
    // COM: O(1)
	~ColaPacientes();
};

#endif /* COLAPACIENTES_H_ */
