/*
 * pruebasEnsayoClinico.h
 *
 *  Created on: 11 may 2023
 *      Author: Jose Nogales
 */

#ifndef PRUEBASENSAYOCLINICO_H_
#define PRUEBASENSAYOCLINICO_H_
#include "ensayoclinico.h"
#include <iostream>
using namespace std;


/*Prueba del constructor por defecto de EnsayoClinico
* nombre = "Jose Nogales Gallardo"
* numNiveles = 8
*/
void pruebasConstructor();
//Caso 1: no se ejecuta ec->anotar(), por lo que no se debe mostrar ningun error
//Caso 2: se ejecuta ec->anotar(), debe mostrarse el resultado esperado
void pruebasMostrarErroresYAnotar();
//Debe mostrar los 12 con mayor puntuacion
void pruebaMostrarMayores();
//Caso 1 : ec->mostrarPorApellido("xzy");
//Resultado esperado: ningun apellido contiene "xzy", por lo que no se muestra ningun paciente
//Caso 2 :ec->mostrarPorApellido("Nog");
//Resultado esperado : 89020897Z # José Nogales Gallardo # 17 # noDefinido # 2
void pruebasMostrarPorApellido();
//ec->mostrarPorDNI("910");
//Resultado esperado: ningun DNI empieza por "910", por lo que no se muestra ningun paciente
//ec->mostrarPorDNI("8902");
//Resultado esperado: 89020897Z # José Nogales Gallardo # 17 # noDefinido # 2
void pruebasMostrarPorDNI();
//Llamada de todas las pruebas
void pruebasEnsayoClinico();


#endif /* PRUEBASENSAYOCLINICO_H_ */
