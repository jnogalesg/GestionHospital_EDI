/*
 * pruebasListaMedicos.h
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */

#ifndef PRUEBASLISTAMEDICOS_H_
#define PRUEBASLISTAMEDICOS_H_
#include "ListaMedicos.h"
#include <iostream>
using namespace std;

//Prueba del constructor por defecto
// estaVacia == true
void pruebaConstructorLM();
//Prueba de los metodos de insertar y obtener
//Inserta m1 y comprueba que se devuelve correctamente tras ello
//Por ultimo comprueba que tras devolver m1, este se elimina de la lista (lM->estaVacia() = true)
void pruebaInsertarObtenerPrimeroLM();
//Prueba de los metodos contar y existe
//Inserta m1, comprueba que cuenta devuelve 1
//Inserta m2, comprueba que cuenta devuelve 2
//Comprueba que existe un paciente con el APELLIDO "Vazquez" (m2)
void pruebaContarExisteObtenerLM();
//Llamada a todos los metodos anteriores
void pruebasListaMedicos();






#endif /* PRUEBASLISTAMEDICOS_H_ */
