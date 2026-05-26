//
//Created by Jose Nogales on 06/02/2023.
// paciente.h
//

#ifndef PRACTICA1EDI_PACIENTE_H
#define PRACTICA1EDI_PACIENTE_H
#include <iostream>
#include <string>
using namespace std;

enum Genero {Masculino, Femenino, noDefinido};   //tipo de datos enumerado

class Paciente {
private:        //atributos privados de la clase
    string nombre;
    string apellido;
    string DNI;
    Genero genero;
    int edad;

public:     //atributos publicos de la clase(metodos)
    // PRE: ---
    // DES: Constructor por defecto
    // COM: O(1)
    Paciente();
    // PRE: ---
    // DES: Constructor parametrizado
    // COM: O(1)
    Paciente(string nombre, string apellido, string DNI, Genero genero, int edad); //constructor parametrizado
    // PRE: p correctamente incializado
    // DES: contructor por copia
    // COM: O(1)
    Paciente(const Paciente &p);

    // PRE: ---
    // DES: destructor (libera los recursos asociados a los atributos, si no son dinámicos)
    // COM: O(1)
    ~Paciente();

    //-----------setters------------
    // PRE: ---
    // DES: modifica this->nombre = nombre
    // COM: O(1)
    void setNombre (string nombre);
    // PRE: ---
    // DES: modifica this->apellido = apellido
    // COM: O(1)
    void setApellidos (string apellido);
    // PRE: ---
    // DES: modifica this->DNI = DNI
    // COM: O(1)
    void setDNI (string DNI);
    // PRE: ---
    // DES: modifica this->genero = genero
    // COM: O(1)
    void setGenero (Genero genero);
    // PRE: ---
    // DES: modifica this->edad = edad
    // COM: O(1)
    void setEdad (int edad);

    //-----------getters------------
    // PRE: ---
    // DES: devuelve nombre
    // COM: O(1)
    string getNombre();
    // PRE: ---
    // DES: devuelve apellido
    // COM: O(1)
    string getApellido();
    // PRE: ---
    // DES: devuelve DNI
    // COM: O(1)
    string getDNI();
    // PRE: ---
    // DES: devuelve genero
    // COM: O(1)
    Genero getGenero();
    // PRE: ---
    // DES: devuelve edad
    // COM: O(1)
    int getEdad();
    // PRE: ---
    // DES: muestra por pantalla el nombre, apellidos, DNI y género del paciente
    // COM: O(1)
    void mostrar();

};


#endif //PRACTICA1EDI_PACIENTE_H
