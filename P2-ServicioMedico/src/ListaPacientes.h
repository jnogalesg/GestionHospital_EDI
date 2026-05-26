/*
 * ListaPacientes.h
 *
 *  Created on: 17 mar 2023
 *      Author: Jose Nogales
 */

#ifndef LISTAPACIENTES_H_
#define LISTAPACIENTES_H_
#include "ListaDPI.h"
#include "Paciente.h"

class ListaPacientes {
private:
	ListaDPI <Paciente *> *lPacientes;
	void mostrarRec(ListaDPI <Paciente *> *l);
public:

	//PRE = ---
	//DESC = Constructor por defecto
	//POST = Inicializa los atributos a su valor por defecto, haciendo new al vector lista de pacientes
	//COM = O(1)
	ListaPacientes ( );
	//PRE = p inicializado correctamente
	//DESC = Inserta un nuevo paciente en la lista, ordenado por su DNI
	//POST = Insercion en orden del paciente p
	//COM = O(n)
	void insertar(Paciente *p);
	//PRE = ---
	//DESC = Comprueba si existe un paciente con el DNI introducido como parametro
	//POST = Devuelve TRUE si se encuentra un paciente con ese DNI, FALSE en caso contrario
	//COM = O(n)
	bool existe(string DNI);
	//PRE = ---
	//DESC = Devuelve el paciente cuyo DNI coincida con el DNI introducido como parametro
	//POST = ---
	//COM = O(n)
	void obtenerPaciente(string DNI, Paciente *&p);
	//PRE = ---
	//DESC = Devuelve el primer paciente de la lista y lo elimina
	//POST = ---
	//COM = O(n)
	void obtenerPrimero(Paciente *&p);
	//PRE = ---
	//DESC = Comprueba si la lista esta vacia
	//POST = Devuelve TRUE si la lista esta vacia, FALSE en caso contrario
	//COM = O(n)
	bool estaVacia();
	//PRE = ---
	//DESC = Devuelve el numero de elementos que hay en la lista
	//POST = devuelve numElementos
	//COM = O(n)
	int contar();

	//PRE = ---
	//DESC = Muestra por pantalla el contenido de la lista
	//POST = ---
	//COM = O(n)
	void mostrar();

	void mostrarR();

	~ListaPacientes();
};

#endif /* LISTAPACIENTES_H_ */
