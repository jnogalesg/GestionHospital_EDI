/*
 * pruebasServicio.h
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */

#include "Servicio.h"
#include <iostream>
using namespace std;

//Prueba de los constructores
//Prueba el constructor por defecto y comprueba que esta vacio
//Prueba el constructor parametrizado y comprueba que inicializa bien los parametros
void pruebasConstructoresAsignarSer();
//Pruebas de modulos insertar, contar, obtenerMedico
//Inserta un paciente, comprueba que la cola de prioridad no esta vacia, y comprueba que contar es 1
//Inserta otro paciente y comprueba que contar es 2
//Obtiene el medico y comprueba que es igual que el introducido por parametro
void pruebasInsertarContar();
//Llama a los demas modulos de prueba
void pruebasServicio();




