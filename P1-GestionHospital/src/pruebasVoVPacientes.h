//
// pruebasVoVPacientes.h
// Created by Jose Nogales on 09/03/2023.
//

#ifndef EDIPRACTICAS_PRUEBASVOVPACIENTES_H
#define EDIPRACTICAS_PRUEBASVOVPACIENTES_H
#include "VoVPacientes.h"
#include <iostream>
using namespace std;

//Se crea un vector vacio
//ocupadas debe ser = 0
void pruebasConstructorVoVPaciente();
//Caso 1: Creamos un vector vacio
//comprobamos que estaVacio == TRUE, y estaLleno == FALSE
//Caso 2: insertamos MAX consultas al vector
//comprobamos que estaVacio == FALSO, y estaLLeno == TRUE
void pruebasInsertarVoVPaciente();
//Llamada a todos los modulos de prueba
void pruebasVoVPaciente();

#endif //EDIPRACTICAS_PRUEBASVOVPACIENTES_H
