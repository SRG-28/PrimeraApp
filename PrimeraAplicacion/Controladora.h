#pragma once
#include "GestorArchivos.h"
#include "Arreglo.h"
#include <Windows.h>

class Controladora{
private:
	GestorArchivos* ges;
	Arreglo<Enfermedad>* enfermedadcita;
	Arreglo<Paciente>* pacientito;
public:
	Controladora();
	virtual ~Controladora();
	void control1();
	void control2();
	void cargaPaci();
	void cargaEnfer();
	void generaJSON();

	

};