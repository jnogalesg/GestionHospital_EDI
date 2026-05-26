/*
 * pilaInformes.h
 *
 *  Created on: 6 mar 2023
 *      Author: Jose Nogales
 */

#ifndef PILAINFORMES_H_
#define PILAINFORMES_H_
#include <iostream>
#include "Pila.h"
#include "Medico.h"
#include "Informe.h"
using namespace std;

class PilaInformes {
	Pila <Informe *> *pInf;
	void mostrarR(Pila <Informe *> *p);
public:
    // PRE: ---
    // DES: constructor por defecto
	// POST: ---
    // COM: O(1)
	PilaInformes();

    // PRE: ---
    // DES: apila un informe inf a la pila de informes
	// POST: ---
    // COM: O(1)
	void anadir (Informe *inf);
    // PRE: ---
    // DES: devuelve el dato de la cima de la pila
	// POST: ---
    // COM: O(1)
	void getCima(Informe *&inf);
    // PRE: ---
    // DES: muestra la informacion de la pila de informes (version iterativa)
	// POST: ---
    // COM: O(1)
	void mostrarI();
	void mostrarR();

    // PRE: ---
    // DES: muestra todos los informes realizados por un determinado medico.
	// POST: ---
    // COM: O(1)
	void mostrarInfMedico(const Medico *m);

    // PRE: ---
    // DES: ---
	// POST: elimina todos los informes de un medico determinado
    // COM: O(1)
	void eliminarInfMedico(const Medico *m);

    // PRE: ---
    // DES: destructor
	// POST: ---
    // COM: O(1)
	~PilaInformes();
};

#endif /* PILAINFORMES_H_ */
