/*
 * prog_principal.cpp
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 22 Febrero 2023
 */

#include <iostream>
#include <string>

#include "Paciente.h"
#include "Medico.h"
#include "Consulta.h"
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
      cout << "     4. Mostrar Consultas                  " << endl;
      cout << "     5. Buscar Paciente (por DNI)          " << endl;
      cout << "     6. Buscar Medico (por apellido)       " << endl;
      cout << "     7. Guardar fichero de paciente        " << endl;
      cout <<                                                  endl;
      cout << "     0. Finalizar.                         " << endl;
      cout << "                        Opción:  ";
      
      cin >> opcion;
      cin.ignore();

   } while ((opcion < 0) || (opcion > 7));

   return opcion;
}


// Programa principal:
int main() {

   Hospital  *hospital  = nullptr;
   bool       fin       = false;
   int        opcion;
   string     nombre;
   string     DNIPaciente;
   string     apellidoMedico;
   Paciente  *p 		= nullptr;
   Medico 	 *m 		= nullptr;
   // 1. Crear hospital (los datos se cargan automáticamente).

   cout<<"Introduce el nombre del hospital:"<<endl;
   cin>>nombre;
   hospital = new Hospital(nombre);
   
   // 2. Muestra el menú hasta que se pulse "fin"
   do {
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
            hospital->mostrarConsultas();
            break;

         case 5:
        	 cout<<"Introducir DNI del paciente a buscar: ";
        	 cin>>DNIPaciente;

        	 p = hospital->buscarPaciente(DNIPaciente);
        	 if (p == nullptr){
        		 cout<<"Paciente con DNI "<<DNIPaciente<<" no encontrado"<<endl;
        	 } else {
        		 p->mostrar();
        	 }
        	 break;

         case 6:
        	 cout<<"Introducir apellido del medico a buscar: ";
        	 cin>>apellidoMedico;
        	 m = hospital->buscarMedico(apellidoMedico);
        	 if (m == nullptr){
        		 cout<<"Medico con apellido "<<apellidoMedico<<" no encontrado"<<endl;
        	 } else{
        		 m->mostrar();
        	 }
        	 break;

         case 7:
        	 cout<<"Introducir DNI del paciente para guardar un fichero con sus datos: ";
        	 cin>>DNIPaciente;
        	  p = hospital->buscarPaciente(DNIPaciente);

        	  if (p == nullptr){
        		 cout<<"Paciente con DNI "<<DNIPaciente<<" no encontrado"<<endl;
        	     } else {
        	    	 hospital->crearFicheroPaciente(p);
        	     }
        	 break;

            
         case 0:
            fin = true;
            break;

         default:
            break;

      }
      
   } while (!fin);
   
   // 3. Elimina hospital (los datos se almacenan automáticamente).
   delete hospital;
   delete m;
   delete p;

   return 0;
}
