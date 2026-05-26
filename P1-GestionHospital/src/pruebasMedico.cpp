/*
 * pruebasMedico.cpp
 *
 *  Created on: 12 feb. 2023
 *      Author: Jose Nogales
 */

#include "pruebasMedico.h"

void pruebasMedico(){

	//caso 1:
	cout <<"-----Inicio: Prueba Medico constructor por defecto:-----"<<endl;
	Medico m1;

	if (m1.getNombre() != ""){
		cerr <<"error en getNombre"<<endl;
	}
	if (m1.getApellidos() != ""){
		cerr <<"error en getApellidos"<<endl;
	}
	if (m1.getEspecialidad() != ""){
		cerr <<"error en getEspacialidad"<<endl;
	}
	cout <<"-----Fin: Prueba Medico constructor por defecto-----"<<endl;
    cout <<endl;

	//caso 2:
	cout <<"-----Inicio: Prueba Medico constructor parametrizado-----"<<endl;

	Medico m2("Maria", "Hidalgo Tena", "Psicologia");

    if (m2.getNombre() != "Maria"){
        cerr <<"error en getNombre"<<endl;
    }
    if (m2.getApellidos() != "Hidalgo Tena"){
        cerr <<"error en getApellidos"<<endl;
    }
    if (m2.getEspecialidad() != "Psicologia"){
        cerr <<"error en getEspecialidad"<<endl;
    }

    cout <<"-----Fin: Prueba Medico constructor parametrizado-----"<<endl;
    cout<<endl;

    //caso 3:
    cout <<"-----Inicio: Prueba Medico constructor por copia:-----"<<endl;

    Medico m3 (m2);

    if (m3.getNombre()!= "Maria"){
        cout <<"error en set/get"<<endl;
    }
    if (m3.getApellidos() != "Hidalgo Tena"){
        cout <<"error en set/get"<<endl;
    }
    if (m3.getEspecialidad() != "Psicologia"){
        cout <<"error en set/get"<<endl;
    }
    cout <<"-----Fin: Prueba Medico constructor por copia-----"<<endl;
    cout<<endl;
    //caso 4
    cout <<"-----Inicio: Prueba Medico set/get-----"<<endl;
    m3.setNombre("Aroa");
    m3.setApellidos("Valor");
    m3.setEspecialidad("Trauma");

    if (m3.getNombre()!= "Aroa"){
        cerr <<"error en set/get"<<endl;
    }
    if (m3.getApellidos() != "Valor"){
        cerr <<"error en set/get"<<endl;
    }
    if (m3.getEspecialidad() != "Trauma"){
        cerr <<"error en set/getEspecialidad"<<endl;
    }
    cout <<"-----Fin: Prueba Medico set/get-----"<<endl;
    cout<<endl;


}



