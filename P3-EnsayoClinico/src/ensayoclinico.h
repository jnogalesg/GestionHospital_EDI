/*
 * ensayoclinico.h
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 15 abril 2023
 */

#ifndef ENSAYO_CLINICO_H_
#define ENSAYO_CLINICO_H_

#include <iostream>
#include <string>
#include <fstream>

#include "Paciente.h"
#include "BSTree.h"
#include "KeyValue.h"
#include "ListaDPI.h"
// Si necesitas alguna ED o clase adicional, puedes incluirla aqui



using namespace std;


class EnsayoClinico {

private:

   string  nombre; // Inicializa con tu NOMBRE Y APELLIDOS en el constructor

   BSTree<KeyValue<string, Paciente *>> *arbolPacientes;
   ListaDPI <string> *listaErrores;

   //PRE = ---
   //DESC = Carga los pacientes del archivo pacientes_ordenados.csv al vector
   //POST = Vector[199] contiene los pacientes del archivo pacientes_ordenados.csv
   //COM = O(n)
   void cargarPacientesAVector(Paciente *Vector[199]);
   //PRE = ---
   //DESC = Crea el arbol de pacientes a partir del vector de pacientes
   //POST = arbolPacientes contiene a los pacientes de Vector
   //COM = ---
   void crearArbolPaciente(Paciente *Vector[199], int ini, int fin);
   //PRE = ---
   //DESC = comprueba si el DNI introducido como parametro existe en la listaErrores
   //POST = devuelve TRUE si el DNI esta en la lista, FALSE en caso contrario
   //COM = O(n)
   bool existeListaErrores(string DNI);
   //PRE = ---
   //DESC = Muestra por pantalla los pacientes por orden de DNI del arbol
   //POST = ---
   //COM = ---
   void mostrarEnOrdenDNI (BSTree<KeyValue<string, Paciente *>> *arbol, string s_dni);
   //PRE = ---
   //DESC = Modulo Recursivo
   //POST = Devuelve el nº de niveles que tiene el arbol
   //COM = ---
   int numNiveles (BSTree<KeyValue<string, Paciente *>> *arbol);
   //PRE = ---
   //DESC = Modulo Recursivo
   //POST = Muestra al paciente cuyo apellido contiene la subcadena s_apellido
   //COM = ---
   void mostrarPorApellido (BSTree<KeyValue<string, Paciente *>> *arbol, string s_apellido);
   //PRE = ---
   //DESC = Modulo Recursivo, muestra los "cuantos" pacientes con mayor puntuacion
   //POST = Devuelve los pacientes con mayor puntuacion del arbol
   //COM = ---
   void mayoresR(BSTree<KeyValue<string, Paciente *>> *arbol, int cuantos);
   //PRE = ---
   //DESC = Busca el paciente que coincide con el DNI introducido por parametro
   //POST = Devuelve el paciente cuyo DNI coincide con el parametro DNI introducido
   //COM = ---
   Paciente * buscarPaciente(BSTree<KeyValue<string, Paciente *>> *arbol, string DNI);

public:

   //PRE = ---
   //DESC = Constructor por defecto
   //POST = Pone el nombre del alumno al ensayo y crea lo necesario
   //COM = O(n)
          EnsayoClinico      ();
   //PRE = ---
   //DESC = Destructor
   //POST = libera la memoria ocupada por EnsayoClinico y sus atributos
   //COM = O(n)
         ~EnsayoClinico      ();


   //PRE = nombre debe tener un valor
   //DESC = devuelve el nombre del alumno
   //POST = return this->nombre
   //COM = O(1)
   string getNombre          ();

   //PRE = arbolPacientes creado correctamente
   //DESC = Lee el archivo ensayo.csv y añade la puntuación de los pacientes.
   //POST = ---
   //COM = ---
   void   anotar             ();

   //PRE = ---
   //DESC = ---
   //POST = Muestra por pantalla el numero de niveles del arbol
   //COM = ---
   int    numNiveles         ();

   //PRE = ---
   //DESC = ---
   //POST = Muestra los DNI de los pacientes de ensayo.csv que no existen
   //COM = ---
   void   mostrarErrores     ();

   //PRE = cuantos > 0
   //DESC = Muestra "cuantos" pacientes con mayor puntuacion
   //POST = ---
   //COM = ---
   void   mostrarMayores     (int cuantos);

   //PRE = ---
   //DESC = ---
   //POST = Muestra pacientes cuyo apellido contiene subcadena "s_apellido"
   //COM = ---
   void   mostrarPorApellido (string s_apellido);

   //PRE = ---
   //DESC = ---
   //POST = Muestra pacientes cuyo DNI empieza por subcadena "s_dni"
   //COM = ---
   void   mostrarPorDNI      (string s_dni);

};

#endif /* ENSAYO_CLINICO_H_ */
