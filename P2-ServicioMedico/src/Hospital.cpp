/*
 * Hospital.cpp
 *
 *  Created on: 20 mar 2023
 *      Author: Jose Nogales
 */

#include "Hospital.h"

Hospital::Hospital() {
	nombre = "";
	lP = new ListaPacientes();
	lM = new ListaMedicos();
	ser = new Servicio();

	cargarPacientes();
	cargarMedicos();
	cargarInformes();
}

Hospital::Hospital(string nombre) {
	this->nombre = nombre;
	lP = new ListaPacientes();
	lM = new ListaMedicos();
	ser = new Servicio();

	cargarPacientes();
	cargarMedicos();
	cargarInformes();
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
				this->lP->insertar(p);

	           	// calcular prioridad
	           	int prioridad = 1 +rand()%5;
	           	ser->insertar(prioridad,p);
			}
		}
		ifs.close();
	}
}

void Hospital::cargarMedicos() {
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
                this->lM->insertar(m);
            }
        }
        ifs.close();
    }
}


void Hospital::cargarInformes() {
	ifstream ifs;
	string DNIPaciente;
	string informe;
	string apellidoMedico;
	string fecha;
	Medico *m = nullptr;
	Paciente *p = nullptr;
	Informe *inf = nullptr;

	ifs.open("informes.csv");
    if (ifs.fail()) {
        cerr << "ERROR: fichero no encontrado." << endl;
    } else {
        while (!ifs.eof()) {
            getline(ifs, DNIPaciente, ';');
            if (!ifs.eof()) {
                getline(ifs, informe, ';');
                getline(ifs, apellidoMedico, ';');
            	getline(ifs, fecha, '\n');
            	FechaYHora f(fecha);

            	if (lM->existe(apellidoMedico) && lP->existe(DNIPaciente)){
                	lM->obtenerMedico(apellidoMedico, m);
                	lP->obtenerPaciente(DNIPaciente, p);

					inf = new Informe(informe, f, m);
					p->anadirInforme(inf);
					lP->insertar(p);
            	}
            }
        }
    	ifs.close();
    }
}

void Hospital::mostrarPacientes() {
	lP->mostrar();
}

void Hospital::mostrarMedicos() {
	lM->mostrar();
}

string Hospital::getNombre() {
	return this->nombre;
}

void Hospital::mostrarEstadisticas() {
	int num = 0;
	num = lP->contar();
	cout<<"Numero de pacientes: "<< num <<endl;
	num = lM->contar();
	cout<<"Numero de medicos: "<< num <<endl;
	num = ser->contarPrioridad(1);
	cout<<"Pacientes en espera con prioridad 1: "<<num<<endl;
	num = ser->contarPrioridad(2);
	cout<<"Pacientes en espera con prioridad 2: "<<num<<endl;
	num = ser->contarPrioridad(3);
	cout<<"Pacientes en espera con prioridad 3: "<<num<<endl;
	num = ser->contarPrioridad(4);
	cout<<"Pacientes en espera con prioridad 4: "<<num<<endl;
	num = ser->contarPrioridad(5);
	cout<<"Pacientes en espera con prioridad 5: "<<num<<endl;

}

void Hospital::mostrarServicio() {
	ser->mostrarPacientes();
}

string Hospital::obtenerFechaHora() {
	time_t t = std::time(nullptr);
	tm* now = std::localtime(&t);

	char buffer[128];
	string data;
	strftime(buffer, sizeof(buffer), "%d/%m/%Y %X", now);
	return buffer;
}


Paciente* Hospital::obtenerPaciente() {
	Paciente *p;
	string DNI;
	cout<<"Introducir DNI del paciente a buscar: ";
	cin>>DNI;
	cout<<endl;
	lP->obtenerPaciente(DNI, p);
	return p;
}

Medico* Hospital::obtenerMedico() {
	Medico *m;
	string apellido;

	cout<<"Introducir APELLIDO del medico a buscar: ";
	cin>>apellido;
	cout<<endl;
	lM->obtenerMedico(apellido, m);
	return m;
}

void Hospital::asignarMedico() {
	string especialidad;
	Medico *m;
	cout<<"Introducir ESPECIALIDAD del Servicio: ";
	cin>>especialidad;
	cout<<endl;
	ser->asignarEspecialidad(especialidad);
	lM->obtenerMedicoEsp(especialidad, m);
	if (m != nullptr){
		ser->asignarMedico(m);
		cout <<"Medico asignado correctamente"<<endl;
	}	else {
		cout <<"No se ha encontrado un medico con dicha especialidad"<<endl;
	}
}

void Hospital::procesarColas() {
	 if (ser->obtenerMedico() != nullptr){
		 while (!ser->estaVacia()){
			Paciente *p;
			ser->obtenerPaciente(p);

			string sfecha;
			sfecha = obtenerFechaHora();
			FechaYHora f(sfecha);
			Medico *m = ser->obtenerMedico();

			Informe *inf = new Informe ("Paciente procesado de las colas de prioridad", f, m);
			p->anadirInforme(inf);
			p->mostrar();
		 }
	 } else {
		 cout<<"¡El servicio no tiene ningun medico asignado!"<<endl;
	 }
}

Hospital::~Hospital(){
	Paciente *p;
	Medico *m;
	while(!lP->estaVacia()){
		lP->obtenerPrimero(p);
		delete p;
	}
	delete lP;

	while(!lM->estaVacia()){
		lM->obtenerPrimero(m);
		delete m;
	}
	delete lM;
	while (!ser->estaVacia()){
		ser->obtenerPaciente(p);
		delete p;
	}
	m = ser->obtenerMedico();
	delete m;

	delete ser;
}

