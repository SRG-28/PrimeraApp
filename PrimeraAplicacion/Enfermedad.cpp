#include "Enfermedad.h"

Enfermedad::Enfermedad(string nombre, string secuencia) : nombre(nombre), secuencia(secuencia) {}

Enfermedad::Enfermedad(const Enfermedad& en) {
	this->nombre = en.nombre;
	this->secuencia = en.secuencia;
}

void Enfermedad::setNombre(string nom) {
	nombre = nom;
}

void Enfermedad::setSecuencia(string secuancia) {
	secuencia = secuancia;
}

string Enfermedad::getNombre() {
	return nombre;
}

string Enfermedad::getSecuencia() {
	return secuencia;
}

Enfermedad& Enfermedad::operator= (const Enfermedad& en) {
	if (this != &en) {
		this->nombre = en.nombre;
		this->secuencia = en.secuencia;
	}
	return *this;
}

ostream& operator<< (ostream& out, Enfermedad& en) {
	return out
		<< "Nombre: " << en.getNombre() << endl
		<< "Secuencia ADN: " << en.getSecuencia() << endl;
}

string Enfermedad::toString() {
	stringstream s;
	s << "Datos de la enfermedad. " << endl << endl;
	s << "Nombre: " << getNombre() << endl;
	s << "Secuencia ADN: " << getSecuencia() << endl;
	s << endl;
	return s.str();
}

string Enfermedad::toStringEspecial() {
	stringstream s;
	s << getNombre() << "," << getSecuencia() << "\n";
	return s.str();
}

Enfermedad::~Enfermedad() {}

