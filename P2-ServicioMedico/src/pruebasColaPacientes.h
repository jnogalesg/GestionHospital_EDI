/*
 * pruebasColaPacientes.h
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */

#ifndef PRUEBASCOLAPACIENTES_H_
#define PRUEBASCOLAPACIENTES_H_
#include "ColaPacientes.h"
#include <iostream>
using namespace std;
//Prueba del constructor por defecto
// estaVacia == true;
void pruebasConstructor();
//Inserta un paciente p1 en la cola y lo obtiene de vuelta
void insertarObtener();
//Inserta un paciente p1, comprueba que cuenta devuelve 1
//Inserta un segundo paciente p2, y comprueba que cuenta devuelve 2
void pruebasContar();
//Pruebas del modulo que muestra la cola por pantalla
void pruebaMostrar();
//Llama a todos los modulos anteriores
void pruebasColaPacientes();


#endif /* PRUEBASCOLAPACIENTES_H_ */
