#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "GestorArchivos.h"
using namespace std;
using namespace std;

class Vista {
public:
	static void presentacionInicial();
	static int menuProcesamiento();
	static void cargaPacientes();
	static void cargaEnfermedades();
	static bool cargaCSV();
	static void despedida();
};
