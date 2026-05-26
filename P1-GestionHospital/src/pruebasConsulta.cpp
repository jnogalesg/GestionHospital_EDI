//
// pruebasConsulta.cpp
// Autor: Jose Nogales
// Fecha: 06/03/2023
//
#include "pruebasConsulta.h"

void pruebasConsulta(){
    cout <<"Inicio: Pruebas Consulta"<<endl;

    cout<<"-----Caso 1-----"<<endl;
    Consulta c1;

    if (c1.getPaciente() != nullptr){
    	cerr <<"ERROR: el constructor por defecto debe inicializar paciente a nullptr"<<endl;
    }
    if (c1.getMedico() != nullptr){
    	cerr <<"ERROR: el constructor por defecto debe inicializar medico a nullptr"<<endl;
    }
    if (c1.getFecha().toString() != "0/0/0 0:0"){
    	cerr <<"ERROR: el constructor por defecto debe inicializar fecha a 0/0/0 0:0"<<endl;
    }
    if (c1.getTipo() != Pendiente){
    	cerr <<"ERROR: el constructor por defecto debe inicializar el tipo de consulta a Pendiente"<<endl;
    }
    if (c1.getAlta() != false){
    	cerr <<"ERROR: el constructor por defecto debe inicializar alta a FALSE"<<endl;
    }
    if (c1.getInforme() != ""){
    	cerr <<"ERROR: el constructor por defecto debe inicializar informe a cadena vacia"<<endl;
    }

    cout<<"-----Caso 2-----"<<endl;
    Paciente *p1= new Paciente("Victoria", "Ortiz", "20541353E", Femenino, 23);
    Consulta c2 (p1);

    if (c2.getPaciente() != p1){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar paciente a p1"<<endl;
    }
    if (c2.getMedico() != nullptr){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar medico a nullptr"<<endl;
    }
    if (c2.getFecha().toString() != "0/0/0 0:0"){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar fecha a 0/0/0 0:0"<<endl;
    }
    if (c2.getTipo() != Pendiente){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar el tipo de consulta a Pendiente"<<endl;
    }
    if (c2.getAlta() != false){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar alta a FALSE"<<endl;
    }
    if (c2.getInforme() != ""){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar informe a cadena vacia"<<endl;
    }

    cout<<"-----Caso 3-----"<<endl;
    Medico *m1 = new Medico("Sara", "Perez", "Psicologia");
    Consulta c3(p1, m1);

    if (c3.getPaciente() != p1){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar paciente a p1"<<endl;
    }
    if (c3.getMedico() != m1){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar medico a m1"<<endl;
    }
    if (c3.getFecha().toString() != "0/0/0 0:0"){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar fecha a 0/0/0 0:0"<<endl;
    }
    if (c3.getTipo() != Pendiente){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar el tipo de consulta a Pendiente"<<endl;
    }
    if (c3.getAlta() != false){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar alta a FALSE"<<endl;
    }
    if (c3.getInforme() != ""){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar informe a cadena vacia"<<endl;
    }

    cout<<"-----Caso 4-----"<<endl;
    FechaYHora fecha1("9/3/2023 11:42");
    Consulta c4(p1, m1, fecha1, Externa);

    if (c4.getPaciente() != p1){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar paciente a p1"<<endl;
    }
    if (c4.getMedico() != m1){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar medico a m1"<<endl;
    }
    if (c4.getFecha().toString() != "9/3/2023 11:42"){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar fecha a fecha1"<<endl;
    }
    if (c4.getTipo() != Externa){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar el tipo de consulta a Externa"<<endl;
    }
    if (c4.getAlta() != false){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar alta a FALSE"<<endl;
    }
    if (c4.getInforme() != ""){
    	cerr <<"ERROR: el constructor parametrizado debe inicializar informe a cadena vacia"<<endl;
    }

    cout<<"\n-----Caso 5-----"<<endl;
    c4.darDeAlta();
    c4.adjuntarInforme("Radiografia pendiente");
    Medico *m2 = new Medico("Jose","Nogales","Fisiologia");
    c4.asignarMedico(m2);
    FechaYHora fecha2("12/5/2023 8:30");
    c4.agendarFecha(fecha2);

    if (c4.getMedico() != m2){
    	cerr <<"ERROR: asignarMedico debe asignar m2 como medico de la consulta"<<endl;
    }
    if (c4.getFecha().toString() != "12/5/2023 8:30"){
    	cerr <<"ERROR: agendarFecha debe asignar fecha2 como fecha de la consulta"<<endl;
    }
    if (c4.getAlta() != true){
    	cerr <<"ERROR: darDeAlta debe establecer alta a TRUE"<<endl;
    }
    if (c4.getInforme() != "Radiografia pendiente"){
    	cerr <<"ERROR: adjuntarInforme debe adjuntar el informe Radiografia pendiente a la consulta"<<endl;
    }

    c4.mostrar();
    cout<<"\nResultados esperados: Paciente: Nombre del paciente: Victoria\n"
          "Apellido del paciente: Ortiz\n"
          "DNI del paciente: 20541353E\n"
          "Genero del paciente: Femenino\n"
          "Edad del paciente: 23"<<endl;
    cout<<"Medico: Nombre del medico: Jose\n"
          "Apellidos del medico: Nogales\n"
          "Especialidad: Fisiologia"<<endl;
    cout<<"Fecha y hora: 12/5/2023 8:30"<<endl;
    cout<<"Tipo de consulta: Externa"<<endl;
    cout<<"Alta: El paciente tiene el Alta"<<endl;
    cout<<"Informe: Radiografia pendiente"<<endl;

    delete p1;
    delete m1;
    delete m2;

    cout <<"Fin: Pruebas Consulta"<<endl;

}
