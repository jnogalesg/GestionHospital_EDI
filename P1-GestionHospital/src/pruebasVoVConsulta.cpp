/*
 * pruebasVoVConsulta.cpp
 *
 *  Created on: 09 mar 2023
 *      Author: Jose Nogales
 */
#include "pruebasVoVConsulta.h"
void pruebasConstructorVoVConsulta(){
    cout << "Inicio: pruebasConstructorVoVConsulta" << endl;

	VoVConsultas *vc1 = new VoVConsultas();	// Constructor por defecto

    if ( vc1->getOcupadas( ) != 0 ) {
        cerr << "ERROR: Un vector recién creado debe tener ocupadas = 0" << endl;
    }
    cout << "Fin: pruebasConstructorVoVConsulta" << endl;

}
void pruebasVacioLlenoInsertarVoVConsulta(){
    cout << "Inicio: pruebasVacioLlenoInsertarVoVConsulta" << endl;

    VoVConsultas *VConsultas = new VoVConsultas();
    Consulta *c;

    if ( !VConsultas->estaVacio ( ) ) {
        cerr << "ERROR: Un vector recién creado debe estar vacío" << endl;
    }
    if ( VConsultas->estaLleno ( ) ) {
        cerr << "ERROR: Un vector recién creado no puede estar lleno" << endl;
    }

    for ( int i = 0; i < MAX; i++ ) {
        c = new Consulta;
        VConsultas->insertarEnOrden ( c );
    }

    if ( VConsultas->estaVacio ( ) ) {
        cerr << "ERROR: Un vector en el que se han insertado MAX elementos no puede estar vacío" << endl;
    }
    if ( !VConsultas->estaLleno ( ) ) {
        cerr << "ERROR: Un vector en el que se han insertado MAX elementos debe estar lleno" << endl;
    }

    for ( int i = 0; i < MAX; i++ ) {
        delete VConsultas->getPosicion( i );
    }
    cout << "Fin: pruebasVacioLlenoInsertarVoVConsulta" << endl;
}
void pruebasInsertarEnOrden(){
    cout << "Inicio: pruebasInsertarEnOrden" << endl;

	Paciente *p = new Paciente();
	Medico *m = new Medico();
	FechaYHora fh1(9,3,2023,12,30);
	FechaYHora fh2(9,3,2023,13,30);

	Consulta *c1 = new Consulta(p, m, fh1, Urgente);
	Consulta *c2 = new Consulta(p, m, fh2, Urgente);

    VoVConsultas *VConsultas = new VoVConsultas;

    VConsultas->insertarEnOrden(c2);
    VConsultas->insertarEnOrden(c1);

    if (VConsultas->getOcupadas() != 2){
    	cerr <<"ERROR: obtener ocupadas debe ser = 2"<<endl;
    }
    VConsultas->mostrar();

    cout <<"Resultado esperado: Fecha consulta 1 - 9/3/2023 12:30"<<endl;
    cout <<"                    Fecha consulta 2 - 9/3/2023 13:30"<<endl;
    cout <<endl;
    cout << "Fin: pruebasInsertarEnOrden" << endl;
}

void pruebasVoVConsulta(){
    pruebasConstructorVoVConsulta();
    pruebasInsertarEnOrden();
    pruebasVacioLlenoInsertarVoVConsulta();
}
