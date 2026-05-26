/*
 * pruebasVoVConsulta.h
 *
 *  Created on: 09 mar 2023
 *      Author: Jose Nogales
 */

#ifndef EDIPRACTICAS_PRUEBASVOVCONSULTA_H
#define EDIPRACTICAS_PRUEBASVOVCONSULTA_H
#include "VoVConsultas.h"
#include <iostream>
using namespace std;

//Se crea un vector vacio
//ocupadas debe ser = 0
void pruebasConstructorVoVConsulta();
//Caso 1: Creamos un vector vacio
//comprobamos que estaVacio == TRUE, y estaLleno == FALSE
//Caso 2: insertamos MAX consultas al vector
//comprobamos que estaVacio == FALSO, y estaLLeno == TRUE
void pruebasVacioLlenoInsertarVoVConsulta();
//Creamos dos consultas, con la misma fecha y 1 hora de diferencia
//Insertamos las consultas (en orden contrario)
//Mostramos las consultas y comprobamos que están ordenadas por la fecha
//Fecha 1 - 12:30 y fecha 2 - 13:30
void pruebasInsertarEnOrden();
//Llamada a todos los modulos de prueba
void pruebasVoVConsulta();

#endif //EDIPRACTICAS_PRUEBASVOVCONSULTA_H
