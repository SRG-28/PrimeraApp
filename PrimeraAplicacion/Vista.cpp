#include "Vista.h"
#include <Windows.h>
#include "Enfermedad.h"
#include "Paciente.h"
#include "GestorArchivos.h"

void Vista::presentacionInicial() {
	cout << "--------------Bienvenidos------------------" << endl;
	cout << "---------A NUESTRA APLICACION 1------------" << endl;
	cout << "-------------------------------------------" << endl;
	Sleep(1500);
	system("cls");
}


int Vista::menuProcesamiento() {
	int opcion;
	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "-----------MENU PROCESAMIENTO-------------" << endl;
	cout << "------------------------------------------" << endl;
	cout << "    1- Cargar datos del archivo pacientes.csv" << endl;
	cout << "    2- Cargar datos del archivo enfermedades.csv" << endl;
	cout << "    3- Generar archivo datos_geneticas.json" << endl;
	cout << "    4- Salir                              " << endl;
	cout << "------------------------------------------" << endl;
	cout << "     Digite la opcion..: ";
	cin >> opcion;
	system("cls");
	return opcion;
}


void Vista::cargaPacientes() {
	cout << "------Bienvenido al programa de carga de datos de Pacientes------" << endl;
	cout << " Archivos:  pacientes.csv" << endl;
	cout << " Registros encontrados: 100 " << endl;
	cout << "--------------------Datos cargados: Pacientes--------------------" << endl;
	Sleep(1500);
}

void Vista::cargaEnfermedades() {
	cout << "------Bienvenido al programa de carga de datos de Enfermedades------" << endl;
	cout << " Archivos:  enfermedades.csv" << endl;
	cout << " Registros encontrados: 30 " << endl;
	cout << "--------------------Datos cargados: Enfermedades--------------------" << endl;
	Sleep(1500);
}

bool Vista::cargaCSV() {
	bool opcion = false;
	cout << "------Primero debe cargar los datos------" << endl;
	cout << "-----Digite '1' para cargar los datos----" << endl;
	Sleep(3000);
	cin >> opcion;
	system("cls");
	if (opcion != 1) {
		throw "La aplicacion debe cargar sus datos primero. \n\n";
		return 0;
	}
	else {
		return opcion;
	}
}

void Vista::despedida() {
	cout << "------------------------------------" << endl;
	cout << "-----------MUCHAS GRACIAS-----------" << endl;
	cout << "---POR UTILIZAR NUESTRA APLICACION--" << endl;
	cout << "------------------------------------" << endl;
}

