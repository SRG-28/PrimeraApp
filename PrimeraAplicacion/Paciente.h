#pragma once
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "Arreglo.h"
#include "Enfermedad.h"
using namespace std;

class Paciente;
class Paciente {
private:
	string id;
	string nombre;
	string telefono;
	string correo;
	string secuencia;
	Arreglo <Enfermedad>* enfermedadPaci;
public:
	Paciente(string = "", string = "", string = "", string = "", string = ""); Paciente(const Paciente&);
	void setId(string);
	void setNombre(string);
	void setTelefono(string);
	void setCorreo(string);
	void setSecuencia(string);
	void setEnfermedadPaci(Arreglo<Enfermedad>*);
	string getId();
	string getNombre();
	string getTelefono();
	string getCorreo();
	string getSecuencia();
	Arreglo <Enfermedad>* getEnfermedadPaci();
	Paciente& operator=(const Paciente&);
	friend ostream& operator << (ostream&, Paciente&);
	void agregarEnfermedad(Enfermedad*);
	string toString();
	virtual ~Paciente();
};