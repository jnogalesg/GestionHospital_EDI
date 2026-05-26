//
// Created by Jose Nogales on 06/02/2023.
// pruebasPaciente.h
//


#ifndef SESION1EDI_PRUEBASPACIENTE_H
#define SESION1EDI_PRUEBASPACIENTE_H
#include "Paciente.h"

// CASO  	Constructor 				getNombre() 		getApellidos()          getDNI()            getGenero()          getEdad()
//	1		Paciente p1;				"" 			        ""                      ""                  noDefinido           0
// 	2 		Paciente p2 ("Mario",       "Mario" 			"Sanchez Anguas"        "20202019F"         Masculino            19
// 	        "Sanchez Anguas",
// 	        "20202019F", Masculino, 19)
// 	3		Paciente p3 = p2 			"Mario" 			"Sanchez Anguas"        "20202019F"         Masculino            19
//  ------------------------------------------------------------------------------------------------------------------------------------
//  4       p3.setNombre("Sara");
//          p3.setApellidos("Perez García");
//	        p3.setDNI("20202013Q");
//	        p3.setGenero(Femenino);
//	        p3.setEdad(18);

void pruebaPaciente();

#endif //SESION1EDI_PRUEBASPACIENTE_H

