/*
 * Medico.h
 *
 *  Created on: 12 feb. 2023
 *      Author: Jose Nogales
 */

#ifndef MEDICO_H_
#define MEDICO_H_
#include <iostream>
#include <string>
using namespace std;


class Medico {
private:
	string nombre;
	string apellidos;
	string especialidad;

public:
    // PRE: ---
    // DES: Constructor por defecto
    // COM: O(1)
	Medico();

    // PRE: ---
    // DES: Constructor parametrizado
    // COM: O(1)
	Medico(string nombre, string apellidos, string especialidad);
    // PRE: m correctamente incializada
    // DES: contructor por copia
    // COM: O(1)
    Medico(const Medico &m);

    // PRE: ---
    // DES: destructor
    // COM: O(1)
    ~Medico();

	//-----------setters------------
    // PRE: ---
    // DES: modifica this->nombre = nombre
    // COM: O(1)
	void setNombre (string nombre);
    // PRE: ---
    // DES: modifica this->apellidos = apellidos
    // COM: O(1)
	void setApellidos (string apellidos);
    // PRE: ---
    // DES: modifica this->especialidad = especialidad
    // COM: O(1)
	void setEspecialidad (string especialidad);

    //-----------getters------------
    // PRE: ---
    // DES: devuelve nombre
    // COM: O(1)
	string getNombre();
    // PRE: ---
    // DES: devuelve apellidos
    // COM: O(1)
	string getApellidos();
    // PRE: ---
    // DES: devuelve especialidad
    // COM: O(1)
	string getEspecialidad();
    // PRE: ---
    // DES: muestra por pantalla el nombre, apellidos y especialidad del médico
    // COM: O(1)
	void mostrar();

};

#endif /* MEDICO_H_ */
