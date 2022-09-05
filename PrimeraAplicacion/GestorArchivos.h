#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "Arreglo.h"
#include "Enfermedad.h"
#include "Paciente.h"
#include "json/json.h"
using namespace std;

class GestorArchivos {
public:
	GestorArchivos();
	void leerPacientes(Arreglo<Paciente>*);
	void leerEnfermedades(Arreglo<Enfermedad>*);
	void guardaPacientesJson(Arreglo<Paciente>*);
	void guardaEnfermedadesJson(Arreglo<Enfermedad>*);
	void enfermedadPaciente(Arreglo<Enfermedad>*, Arreglo<Paciente>*);
	string Analisis2(Arreglo<Paciente>* pacientito, string id);
};
