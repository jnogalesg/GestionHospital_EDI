/*
 * Hospital.cpp
 *
 *  Created on: 27 feb 2023
 *      Author: Jose Nogales
 */

#include "Hospital.h"

Hospital::Hospital() {
    nombre = "";
    pacientes = new VoVPacientes;
    medicos = new VoVMedicos;
    consultas = new VoVConsultas;

    this->cargarMedicos();
    this->cargarPacientes();
    this->cargarConsultas();
}

Hospital::Hospital(string nombre) {
    this->nombre = nombre;
    pacientes = new VoVPacientes;
    medicos = new VoVMedicos;
    consultas = new VoVConsultas;

    this->cargarMedicos();
    this->cargarPacientes();
    this->cargarConsultas();
}



void Hospital::mostrarPacientes() {
    Paciente *p = nullptr;
    int i;
    for (i = 0; i < this->pacientes->getOcupadas(); i++) {
        p = this->pacientes->getPosicion(i);
        p->mostrar();
    }
}

void Hospital::mostrarMedicos() {
    Medico *m = nullptr;
    int i;
    for (i = 0; i < this->medicos->getOcupadas(); i++) {
        m = this->medicos->getPosicion(i);
        m->mostrar();
    }
}

void Hospital::mostrarConsultas() {
    Consulta *c = nullptr;
    int i;
    for (i = 0; i < this->consultas->getOcupadas(); i++) {
        c = this->consultas->getPosicion(i);
        c->mostrar();
    }
}

void Hospital::cargarPacientes() {
    ifstream ifs;
    string nombre;
    string apellido;
    string DNI;
    string genero;
    string edad;
    Paciente *p = nullptr;

    ifs.open("pacientes.csv");
    if (ifs.fail()) {
        cerr << "ERROR: fichero no encontrado." << endl;
    }	else{
        while (!ifs.eof()) {
            getline(ifs, DNI, ';');
            if (!ifs.eof()) {
                getline(ifs, nombre, ';');
                getline(ifs, apellido, ';');
                getline(ifs, genero, ';');
                getline(ifs, edad, '\n');

                p = new Paciente(nombre, apellido, DNI, Genero ((stoi(genero))), (stoi(edad)));
                this->pacientes->insertar(p);
            }
        }
        ifs.close();
    }
}

void Hospital::cargarMedicos () {
    ifstream ifs;
    string nombre;
    string apellidos;
    string especialidad;
    Medico *m = nullptr;
    ifs.open("medicos.csv");
    if (ifs.fail()) {
        cerr << "ERROR: fichero no encontrado." << endl;
    } else {
        while (!ifs.eof()) {
            getline(ifs, nombre, ';');
            if (!ifs.eof()) {
                getline(ifs, apellidos, ';');
                getline(ifs, especialidad, '\n');
                m = new Medico(nombre, apellidos, especialidad);
                this->medicos->insertar(m);
            }
        }
        ifs.close();
    }
}

Paciente* Hospital::buscarPaciente(string DNI) {
	Paciente *p = nullptr;
	bool enc = false;
	for (int i=0; i < pacientes->getOcupadas(); i++){
		if(pacientes->getPosicion(i)->getDNI() == DNI && !enc){
			p = pacientes->getPosicion(i);
			enc = true;
		}
	}
	return p;
}

Medico* Hospital::buscarMedico(string apellido) {
	Medico *m = nullptr;
	bool enc = false;
	for (int i=0; i < medicos->getOcupadas(); i++){
		if(medicos->getPosicion(i)->getApellidos() == apellido && !enc){
			m = medicos->getPosicion(i);
			enc = true;
		}
	}
	return m;
}

void Hospital::cargarConsultas() {
    ifstream ifs;
    string DNIPaciente;
    string apellidoMedico;
    string tipo;
    string fecha;
    Paciente *p;
    Medico *m;
    Consulta *c;

    ifs.open("consultas.csv");
    if (ifs.fail()) {
        cerr << "ERROR: fichero no encontrado." << endl;
    } else {
        while (!ifs.eof()) {
            getline(ifs, DNIPaciente, ';');
            if (!ifs.eof()) {
            	getline(ifs, apellidoMedico, ';');
            	getline(ifs, tipo, ';');
            	getline(ifs, fecha, '\n');

            	p = buscarPaciente(DNIPaciente);
            	m = buscarMedico(apellidoMedico);

                c = new Consulta(p, m, FechaYHora (fecha), tipoConsulta ((stoi(tipo))));

                this->consultas->insertarEnOrden(c);
            }
        }
        ifs.close();
    }
}

string Hospital::getNombre() {
	return nombre;
}

void Hospital::mostrarEstadisticas() {
	cout<<"Estadisticas del hospital: "<<nombre<<endl;

	cout<<"Numero de pacientes: "<<pacientes->getOcupadas()<<endl;
	cout<<"Numero de medicos: "<<medicos->getOcupadas()<<endl;
	cout<<"Numero de consultas: "<<consultas->getOcupadas()<<endl;
}

void Hospital::crearFicheroPaciente(Paciente *p) {
	ofstream ofs;
	ifstream ifs;
	string DNIPaciente;
	Consulta *c;
	Medico *m;
	FechaYHora fh;

	DNIPaciente = p->getDNI();
	ofs.open(DNIPaciente+".txt", ios::trunc);
	if (ifs.fail()){
		cerr<<"ERROR: "<<DNIPaciente<<".txt no encontrado"<<endl;
	}else{
		ofs << "Consultas del paciente "+p->getNombre()+" "+p->getApellido()<<endl;
	   for (int i = 0; i< consultas->getOcupadas(); i++){
	    	c = consultas->getPosicion(i);
	    	if (c->getPaciente() == p){

	    		m = c->getMedico();
	    		fh = c->getFecha();
	    		ofs << "-----Consulta "<<i<<"-----"<<endl;
		    	ofs << m->getNombre() << " " << m->getApellidos() << endl;
		    	ofs << m->getEspecialidad() << endl;
		    	ofs << fh.toString() << endl;
	    	}
	    }
	 cout << "Archivo "<<DNIPaciente+".txt creado"<<endl;
	}
	ofs.close();
}

Hospital::~Hospital() {
    for (int i = 0; i< pacientes->getOcupadas(); i++){
    	delete pacientes->getPosicion(i);
    }
	delete pacientes;
    for (int i = 0; i< medicos->getOcupadas(); i++){
    	delete medicos->getPosicion(i);
    }
    delete medicos;
    for (int i = 0; i< consultas->getOcupadas(); i++){
    	delete consultas->getPosicion(i);
    }
    delete consultas;
}
