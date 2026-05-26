//============================================================================
// Name        : Entrega 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Hospital.h"
using namespace std;

// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu(string nombre) {

   int opcion;

   do {
      cout << endl;
      cout << "--------  " << nombre << "  --------"  << endl << endl;

      cout << "     1. Mostrar Estadísticas               " << endl;
      cout << "     2. Mostrar Pacientes                  " << endl;
      cout << "     3. Mostrar Médicos                    " << endl;
      cout << "     4. Mostrar Pacientes en espera a ser atendidos" << endl;
      cout << "     5. Buscar Paciente (por DNI)          " << endl;
      cout << "     6. Buscar Medico (por apellido)       " << endl;
      cout << "     7. Asignar Medico a Servicio          " << endl;
      cout << "     8. Procesar colas de espera           " << endl;

      cout << "     0. Finalizar.                         " << endl;
      cout << "                        Opción:  ";

      cin >> opcion;
      cin.ignore();

   } while ((opcion < 0) || (opcion > 8));

   return opcion;
}


// Programa principal:
int main() {

   Hospital  *hospital  = nullptr;
   bool       salir       = false;
   int        opcion;
   string	  nombre;
   Medico     *m 		= nullptr;
   Paciente   *p 		= nullptr;

   cout<<"Introducir nombre del hospital: "<<endl;
   cin>>nombre;
   hospital = new Hospital(nombre);

   while (!salir) {

      opcion = menu(hospital->getNombre());

      switch (opcion) {
         case 1:
            hospital->mostrarEstadisticas();
            break;

         case 2:
            hospital->mostrarPacientes();
            break;

         case 3:
            hospital->mostrarMedicos();
            break;
         case 4:
        	 hospital->mostrarServicio();
        	break;
         case 5:
        	 p = hospital->obtenerPaciente();
        	 if (p != nullptr){
        		 p->mostrar();
        	 } else {
        		 cout<<"El DNI introducido no coincide con ningun paciente."<<endl;
        	 }
        	break;
         case 6:
        	 m = hospital->obtenerMedico();
        	if (m != nullptr){
        		m->mostrar();
        	} else {
        		cout<<"El APELLIDO introducido no coincide con ningun medico."<<endl;
        	}
        	break;
         case 7:
        	 hospital->asignarMedico();
        	break;

         case 8:
        	 hospital->procesarColas();
        	break;

         case 0:
            salir = true;
            break;

         default:
            break;

      }

   }

   // 3. Elimina hospital (los datos se almacenan automáticamente).
   delete hospital;
   delete m;
   delete p;

   return 0;
}
