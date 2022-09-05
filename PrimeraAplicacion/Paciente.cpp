#include "Paciente.h"

Paciente::Paciente(string id, string nombre, string telefono, string correo, string secuencia) :
	id(id), nombre(nombre), telefono(telefono), correo(correo), secuencia(secuencia) {
	enfermedadPaci = new Arreglo<Enfermedad>(30);
}


Paciente::Paciente(const Paciente& pa) {
	this->id = pa.id;
	this->nombre = pa.nombre;
	this->telefono = pa.telefono;
	this->correo = pa.correo;
	this->secuencia = pa.secuencia;
}

void Paciente::setId(string ced) {
	id = ced;
}

void Paciente::setNombre(string nom) {
	nombre = nom;
}

void Paciente::setTelefono(string cel) {
	telefono = cel;
}

void Paciente::setCorreo(string mail) {
	correo = mail;
}

void Paciente::setSecuencia(string secuancia) {
	secuencia = secuancia;
}

void Paciente::setEnfermedadPaci(Arreglo<Enfermedad>* enfermedadPaci) {
	this->enfermedadPaci = enfermedadPaci;
}


string Paciente::getId() {
	return id;
}

string Paciente::getNombre() {
	return nombre;
}

string Paciente::getTelefono() {
	return telefono;
}

string Paciente::getCorreo() {
	return correo;
}

string Paciente::getSecuencia() {
	return secuencia;
}

Arreglo<Enfermedad>* Paciente::getEnfermedadPaci() {
	return enfermedadPaci;
}



Paciente& Paciente::operator=(const Paciente& pa) {
	if (this != &pa) {
		this->id = pa.id;
		this->nombre = pa.nombre;
		this->telefono = pa.telefono;
		this->correo = pa.correo;
		this->secuencia = pa.secuencia;
		//this->enfermedadPaci = pa.enfermedadPaci;
	}
	return *this;
}

ostream& operator << (ostream& out, Paciente& pa) {
	return out
		<< "Cedula: " << pa.getId() << endl
		<< "Nombre: " << pa.getNombre() << endl
		<< "Numero telefonico: " << pa.getTelefono() << endl
		<< "Correo electronico: " << pa.getCorreo() << endl
		<< "Secuencia ADN: " << pa.getSecuencia() << endl;
	//<< "Enfermedades del paciente: " << pa.getEnfermedadPaci() << endl;
}

void Paciente::agregarEnfermedad(Enfermedad* en) {
	enfermedadPaci->ingresaAlArreglo(en);
}

string Paciente::toString() {
	stringstream s;
	s << "Datos del paciente. " << endl << endl;
	s << "Cedula: " << getId() << endl;
	s << "Nombre: " << getNombre() << endl;
	s << "Numero Telefonico: " << getTelefono() << endl;
	s << "Correo electronico: " << getCorreo() << endl;
	s << "Secuencia ADN: " << getSecuencia() << endl;
	s << "Enfermedades del paciente:  " << endl;
	s << enfermedadPaci->toString();
	s << endl;
	return s.str();
}

Paciente::~Paciente() {}



