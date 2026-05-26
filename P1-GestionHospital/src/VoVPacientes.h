/*
 * VoVPacientes.h
 *
 *  Created on: 27 feb 2023
 *      Author: Jose Nogales
 */

#ifndef VOVPACIENTES_H_
#define VOVPACIENTES_H_
#include "Paciente.h"
#include <iostream>
using namespace std;
const int MAXPacientes = 200;

class VoVPacientes {
private:
	Paciente *VoVPaciente[MAXPacientes];
	int ocupadas;

public:
    //PRE: ---
    //DES: Constructor por defecto
    //POST: ---
    //COMP: O(1)
	VoVPacientes();
    //PRE: ---
    //DES: Destructor
    //POST: Libera la memoria ocupada por el vector de medicos
    //COMP: ---
	~VoVPacientes();

    //PRE: p correctamente inicializado, estaLLeno == FALSE
    //DES: Inserta el medico m en la posicion [ocupadas]
    //POST: Incrementa ocupadas en 1
    //COMP: O(1)
	void insertar(Paciente *p);
    //PRE: estaVacio() == false;
    //DES: Elimina un dato en la posicion indicada del VoV
    //POST: Decrementa ocupadas en 1
    //COMP: O(n)
	void borrar(int posicion);
    //PRE: estaVacio() == false;
    //DES: Devuelve el dato almacenado en la posicion indicada del vector
    //POST: Devuelve el puntero a paciente contenido en posicion
    //COMP: O(1)
	Paciente *getPosicion(int posicion);
    //PRE: ---
    //DES: Devuelve el numero de posiciones ocupadas del vector
    //POST: Devuelve ocupadas
    //COMP: O(1)
	int getOcupadas();
    //PRE: ---
    //DES: Devuelve si el vector esta vacio o no
    //POST: Devuelve true si el vector esta vacio, false en caso contrario
    //COMP: O(1)
	bool estaVacio();
    //PRE: ---
    //DES: Devuelve si el vector esta lleno o no
    //POST: Devuelve true si el vector esta lleno, false en caso contrario
    //COMP: O(1)
	bool estaLleno();


};

#endif /* VOVPACIENTES_H_ */
