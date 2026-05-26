/*
 * ListaMedicos.h
 *
 *  Created on: 20 mar 2023
 *      Author: Jose Nogales
 */

#ifndef LISTAMEDICOS_H_
#define LISTAMEDICOS_H_
#include "Medico.h"
#include "ListaDPI.h"

class ListaMedicos {
private:
	ListaDPI <Medico *> *lMedicos;
	void mostrarRec(ListaDPI <Medico *> *l);
public:

	//PRE = ---
	//DESC = Constructor por defecto
	//POST = Inicializa los atributos a su valor por defecto, haciendo new al vector lista de medicos
	//COM = ---
	ListaMedicos ( );
	//PRE = m inicializado correctamente
	//DESC = Inserta un nuevo medico en la lista, ordenado por su apellido
	//POST = Insercion en orden del paciente p
	//COM = O(n)
	void insertar(Medico *m);
	//PRE = ---
	//DESC = Comprueba si existe un medico con el apellido introducido como parametro
	//POST = Devuelve TRUE si se encuentra un medico con ese apellido, FALSE en caso contrario
	//COM = O(n)
	bool existe(string apellido);
	//PRE = ---
	//DESC = Devuelve el medico cuyo apellido coincida con el apellido introducido como parametro
	//POST = ---
	//COM = O(n)
	void obtenerMedico(string apellido, Medico *&m);
	//PRE = ---
	//DESC = Devuelve el medico cuya especialidad coincida con la especialidad introducida como parametro
	//POST = ---
	//COM = O(n)
	void obtenerMedicoEsp(string especialidad, Medico *&m);
	//PRE = ---
	//DESC = Devuelve el primer medico de la lista y lo elimina
	//POST = ---
	//COM = O(n)
	void obtenerPrimero(Medico *&m);
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
	//POST =  ---
	//COM = O(n)
	void mostrar();

	void mostrarR();

	~ListaMedicos();
};

#endif /* LISTAMEDICOS_H_ */
