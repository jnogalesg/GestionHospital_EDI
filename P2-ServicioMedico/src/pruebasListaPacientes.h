/*
 * pruebasListaPacientes.h
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */

#ifndef PRUEBASLISTAPACIENTES_H_
#define PRUEBASLISTAPACIENTES_H_
#include "ListaPacientes.h"
#include <iostream>
using namespace std;

//Prueba del constructor por defecto
// estaVacia == true
void pruebaConstructorLP();
//Prueba de los metodos de insertar y obtener
//Inserta p1 y comprueba que se devuelve correctamente tras ello
//Por ultimo comprueba que tras devolver p1, este se elimina de la lista (lP->estaVacia() = true)
void pruebaInsertarObtenerPrimeroLP();
//Prueba de los metodos contar y existe
//Inserta p1, comprueba que cuenta devuelve 1
//Inserta p2, comprueba que cuenta devuelve 2
//Comprueba que existe un paciente con el DNI "1234567T" (p2)
//Obtiene el paciente que coincide con el DNI "20212223A" y comprueba que lo ha obtenido correctamente
void pruebaContarExisteObtenerLP();
//Llamada a todos los metodos anteriores
void pruebasListaPacientes();


#endif /* PRUEBASLISTAPACIENTES_H_ */
