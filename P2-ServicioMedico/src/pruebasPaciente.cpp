//
// Created by Jose Nogales on 06/02/2023.
// pruebasPaciente.cpp
//
#include "pruebasPaciente.h"
#include <iostream>
using namespace std;

void pruebaPaciente(){

	//caso 1:
    cout <<"-----Inicio: Prueba Paciente constructor por defecto-----"<<endl;
	Paciente p1;

	if (p1.getNombre() != ""){
		cerr <<"error en getNombre"<<endl;
	}
	if (p1.getApellido() != ""){
		cerr <<"error en getApellido"<<endl;
	}
	if (p1.getDNI() != ""){
		cerr <<"error en getDNI"<<endl;
	}
	if (p1.getGenero() != noDefinido){
		cerr <<"error en getGenero"<<endl;
	}
	if (p1.getEdad() != 0){
		cerr <<"error en getEdad"<<endl;
	}
    cout <<"-----Fin: Prueba Paciente constructor por defecto-----"<<endl;
    cout<<endl;

	//caso 2:
    cout <<"-----Inicio: Prueba Paciente constructor parametrizado-----"<<endl;

    Paciente p2("Mario", "Sanchez Anguas", "20202019F", Masculino, 19); //instancia la clase con el constructor parametrizado que coincide con los parámetros introducidos

    if (p2.getNombre() != "Mario"){
        cerr <<"error en getNombre"<<endl;
    }
    if (p2.getApellido() != "Sanchez Anguas"){
        cerr <<"error en getApellido"<<endl;
    }
    if (p2.getDNI() != "20202019F"){
        cerr <<"error en getDNI"<<endl;
    }
    if (p2.getGenero() != Masculino){
        cerr <<"error en getGenero"<<endl;
    }
    if (p2.getEdad() != 19){
        cerr <<"error en getEdad"<<endl;

    }
    cout <<"-----Fin: Prueba Paciente constructor parametrizado-----"<<endl;
    cout<<endl;

    cout <<"-----Inicio: Prueba Paciente constructor por copia-----"<<endl;
    Paciente p3(p2);

    if (p3.getNombre()!= "Mario"){
        cerr <<"error en getNombre"<<endl;
    }
    if (p3.getApellido() != "Sanchez Anguas"){
        cerr <<"error en getApellidos"<<endl;
    }
    if (p3.getDNI() != "20202019F"){
        cerr <<"error en getDNI"<<endl;
    }
    if (p3.getGenero() != Masculino){
        cerr <<"error en getGenero"<<endl;
    }
    if (p3.getEdad() != 19){
        cerr <<"error en getEdad"<<endl;
    }

    cout <<"-----Fin: Prueba Paciente constructor por copia-----"<<endl;
    cout<<endl;

    cout<<"-----Inicio: Prueba Paciente set/get-----"<<endl;
    p3.setNombre("Sara");
    p3.setApellidos("Perez Garcia");
    p3.setDNI("20202013Q");
    p3.setGenero(Femenino);
    p3.setEdad(18);
    Medico *m = new Medico("Manuel", "Carrasco", "Oftalmología");
    FechaYHora f(5, 4, 2023, 14, 47);
    Informe *inf = new Informe("Informe de prueba", f, m);
    p3.anadirInforme(inf);

    if (p3.getNombre() != "Sara"){
        cerr <<"error en set/getNombre"<<endl;
    }
    if (p3.getApellido() != "Perez Garcia"){
        cerr <<"error en set/getApellido"<<endl;
    }
    if (p3.getDNI() != "20202013Q"){
        cerr <<"error en getDNI"<<endl;
    }
    if (p3.getGenero() != Femenino){
        cerr <<"error en set/getGenero"<<endl;
    }
    if (p3.getEdad() != 18) {
        cerr << "error en set/getEdad" << endl;
    }
    p3.mostrar();
    cout<<"Resultado esperado: Nombre del paciente: Sara"<<endl;
    cout<<"Apellido del paciente: Perez Garcia"<<endl;
    cout<<"DNI del paciente: 20202013Q"<<endl;
    cout<<"Genero del paciente: Femenino"<<endl;
    cout<<"Edad del paciente: 18"<<endl;
    cout<<"Informes del paciente: "<<endl;
    cout<<"**Informe del Paciente: Informe de prueba"<<endl;
    cout<<"Fecha: 5/4/2023 14:47"<<endl;
    cout<<"\nMedico: Nombre del medico: Manuel"<<endl;
    cout<<"Apellidos del medico: Carrasco"<<endl;
    cout<<"Especialidad: Oftalmología"<<endl;

    cout<<"-----Fin: Prueba Paciente set/get-----"<<endl;

}
