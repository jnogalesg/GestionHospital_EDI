/*
 * pilaInformes.cpp
 *
 *  Created on: 11 mar 2023
 *      Author: Jose Nogales
 */

#include "PilaInformes.h"

PilaInformes::PilaInformes() {
	pInf = new Pila<Informe *>;
}

void PilaInformes::anadir(Informe *inf) {
	pInf->apilar(inf);
}

void PilaInformes::getCima(Informe *&inf) {
	inf = pInf->getCima();
}

void PilaInformes::mostrarI() {
	Pila <Informe *> *pAux = new Pila<Informe*>;
	Informe *inf;

	while (!pInf->estaVacia()){
		pInf->getCima(inf);
		pInf->desapilar();
		pAux->apilar(inf);
		cout<<"**";
		inf->mostrar();
	}
	while (!pAux->estaVacia()){
		pAux->getCima(inf);
		pInf->apilar(inf);
		pAux->desapilar();
	}
	delete pAux;
}

void PilaInformes::mostrarR(Pila<Informe*> *p) {
	Informe *inf;
	if(!p->estaVacia()){
		p->getCima(inf);
		inf->mostrar();
		p->desapilar();
		mostrarR(p);
		p->apilar(inf);
	}
}

void PilaInformes::mostrarR() {
	if (!pInf->estaVacia()){
		mostrarR(pInf);
	}
}

PilaInformes::~PilaInformes() {
	while (!pInf->estaVacia()){
		pInf->desapilar();
	}
	delete pInf;
}

void PilaInformes::mostrarInfMedico(const Medico *m) {
	Pila <Informe *> *pAux = new Pila<Informe*>;
	Informe *inf;

	while (!pInf->estaVacia()){
		pInf->getCima(inf);
		pInf->desapilar();
		pAux->apilar(inf);
		if (inf->obtenerMedicoInf() == m){
			cout<<"**";
			inf->mostrar();
		}

	}
	while (!pAux->estaVacia()){
		pAux->getCima(inf);
		pInf->apilar(inf);
		pAux->desapilar();
	}
	delete pAux;
}

void PilaInformes::eliminarInfMedico(const Medico *m) {
	Pila <Informe *> *pAux = new Pila<Informe*>;
	Informe *inf;

	while (!pInf->estaVacia()){
		pInf->getCima(inf);
		pInf->desapilar();
		if (inf->obtenerMedicoInf() != m){
			pAux->apilar(inf);
		}

	}
	while (!pAux->estaVacia()){
		pAux->getCima(inf);
		pInf->apilar(inf);
		pAux->desapilar();
	}
	delete pAux;
}
