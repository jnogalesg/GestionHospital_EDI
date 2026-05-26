//
// pruebasConsulta.h
// Autor: Jose Nogales
// Fecha: 06/03/2023
//

#ifndef EDIPRACTICAS_PRUEBASCONSULTA_H
#define EDIPRACTICAS_PRUEBASCONSULTA_H
#include <iostream>
#include "Consulta.h"
using namespace std;
//         -------PRUEBAS-------
//
//         Paciente p1 = new Paciente ("Victoria", "Ortiz", "20541353E", Femenino, 23)
//         Medico m1 = new Medico ("Sara","Perez","Psicologia")
//
//         Medico m2 = new Medico ("Jose","Nogales","Fisiologia")
//
// CASO  	Constructor 				Paciente 		             Medico                 FechaYHora fecha            tipoConsulta tipo       getAlta()           getInforme()
//	1		Consulta c1;                nullptr                      nullptr                 0/0/0 0:0                  Pendiente               false               ""
// 	2 		Consulta c2 (p1)            p1("Victoria",               nullptr                 0/0/0 0:0                  Pendiente               false               ""
// 	                                    "Ortiz", "20541353E",
// 	                                    Femenino, 23);
// 	3		Consulta c3 (p1,m1) 	    p1                          m1("Sara",               0/0/0 0:0                  Pendiente               false               ""
// 	                                                                "Perez", "Psicologia")
//  4       Consulta c4 (p1, m1,        p1                          m1                       9/3/2023 11:42             Externa                 false               ""
//          fecha1, Externa)
//
//--------------------------------------------------------------------------------------------------------
//  5      c4.darDeAlta()
//         c4.adjuntarInforme("Radiografia pendiente)
//	       c4.asignarMedico(m2("Jose","Nogales","Fisiologia"))
//         c4.agendarFecha(fecha2("12/5/2023 8:30"))
//
//		   c4.mostrar
//Se muestra la consulta y el resultado esperado (prueba supervisada)
void pruebasConsulta();

#endif //EDIPRACTICAS_PRUEBASCONSULTA_H
