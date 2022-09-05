#pragma once
#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;

class Enfermedad;
class Enfermedad {
private:
	string nombre;
	string secuencia;
public:
	Enfermedad(string = "", string = "");
	Enfermedad(const Enfermedad&);
	void setNombre(string);
	void setSecuencia(string);
	string getNombre();
	string getSecuencia();
	Enfermedad& operator= (const Enfermedad&);
	friend ostream& operator<< (ostream&, Enfermedad&);
	string toString();
	string toStringEspecial();
	virtual ~Enfermedad();
};


