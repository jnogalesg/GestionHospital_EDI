/*
 * pruebasVoVMedicos.h
 *
 *  Created on: 9 mar 2023
 *      Author: Jose Nogales
 */

#ifndef PRUEBASVOVMEDICOS_H_
#define PRUEBASVOVMEDICOS_H_
#include <iostream>
#include "VoVMedicos.h"
using namespace std;

//Se crea un vector vacio
//ocupadas debe ser = 0
void pruebasConstructorVoVMedico();
//Caso 1: Creamos un vector vacio
//comprobamos que estaVacio == TRUE, y estaLleno == FALSE
//Caso 2: insertamos MAX consultas al vector
//comprobamos que estaVacio == FALSO, y estaLLeno == TRUE
void pruebasInsertarVoVMedico();
//Llamada a todos los modulos de prueba
void pruebasVoVMedico();

#endif /* PRUEBASVOVMEDICOS_H_ */
