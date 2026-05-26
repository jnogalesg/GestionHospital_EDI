
/*
 * pruebasPilaInformes.cpp
 *
 *  Created on: 5 abr 2023
 *      Author: Jose Nogales
 */
#include "pruebasPilaInformes.h"
#include <iostream>
using namespace std;

void pruebaConstructorPInf() {
	PilaInformes *pInf = new PilaInformes();
	pInf->mostrarI();
	//La pila esta vacia, por lo que no deberia mostrar nada

}

void pruebaAnadirCimaPInf() {
	PilaInformes *pInf = new PilaInformes();
	FechaYHora f(5, 4, 2023, 20, 35);
	Informe *inf = new Informe(f);
	Informe *infAux;

	pInf->anadir(inf);
	pInf->getCima(infAux);

	if (infAux != inf){
		cerr<<"Error en anadir/getCima"<<endl;
	}
	delete pInf;
	delete inf;
}

void pruebaObtenerEliminarMedicoPInf() {
	PilaInformes *pInf = new PilaInformes();
	Medico *m = new Medico("Conchi", "Balsera", "Neurología");
	FechaYHora f1(5, 4, 2023, 20, 35);
	FechaYHora f2(9, 4, 2022, 12, 39);
	Informe *inf1 = new Informe(f1);
	Informe *inf2 = new Informe("Informe de prueba", f2, m);

	pInf->anadir(inf1);
	pInf->anadir(inf2);

	pInf->mostrarInfMedico(m);
	cout<<"-----Resultado esperado: -----"<<endl;
	cout<<"**Informe del Paciente: Informe de prueba"<<endl;
	cout<<"Fecha: 9/4/2022 12:39"<<endl;
	cout<<endl;
	cout<<"Medico: Nombre del medico: Conchi"<<endl;
	cout<<"Apellidos del medico: Balsera"<<endl;
	cout<<"Especialidad: Neurología"<<endl;

	pInf->eliminarInfMedico(m);
	pInf->mostrarInfMedico(m);
	//los informes de este medico se han eliminado, por lo que
	//no debe mostrarse nada

}

void pruebasPilaInformes() {
	pruebaConstructorPInf();
	pruebaAnadirCimaPInf();
	pruebaObtenerEliminarMedicoPInf();
}
