/*
 * VoVConsultas.h
 *
 *  Created on: 23 feb 2023
 *      Author: Jose Nogales
 */

#ifndef VOVCONSULTAS_H_
#define VOVCONSULTAS_H_
#include "Consulta.h"
const int MAX = 200;

class VoVConsultas {
private:

	Consulta *VoVConsulta[MAX];
	int ocupadas;

public:
    //PRE: ---
    //DES: Constructor por defecto
    //POST: ---
    //COMP: O(1)
	VoVConsultas();
    //PRE: ---
    //DES: Destructor
    //POST: Libera la memoria ocupada por el vector de punteros
    //COMP: ---
	~VoVConsultas();

    //PRE: c correctamente inicializado, estaLLeno == FALSE
    //DES: Añade un dato ordenado por su fecha al VoV
    //POST: Incrementa ocupadas en 1
    //COMP: O(n)
    void insertarEnOrden(Consulta *c);
    //PRE: estaVacio() == false;
    //DES: Elimina un dato en la posicion indicada del VoV
    //POST: Decrementa ocupadas en 1
    //COMP: O(n)
	void borrar(int posicion);
    //PRE: estaVacio() == false;
	//DES: Devuelve el dato almacenado en la posicion indicada del vector
    //POST: Devuelve el puntero a consulta contenido en posicion
    //COMP: O(1)
	Consulta *getPosicion(int posicion);
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
    //PRE: ---
    //DES: Muestra por pantalla la informacion contenida en el vector
    //POST: ---
    //COMP: O(n)
    void mostrar();

};

#endif /* VOVCONSULTAS_H_ */
