#include"Controladora.h"
#include"Vista.h"
#include <Windows.h>

Controladora::Controladora() : ges(new GestorArchivos()), enfermedadcita(new Arreglo<Enfermedad>(30)), pacientito(new Arreglo<Paciente>(100)){

}

void Controladora::control1() {

	try {
		Vista::presentacionInicial();
		int opcion;
		do {
			opcion = Vista::menuProcesamiento();
			switch (opcion) {
			case 1:
				cargaPaci();
				break;
			case 2:
				cargaEnfer();
				break;
			case 3:
				generaJSON();
				break;
			case 4:
				Vista::despedida();
				break;
			default:
				cout << "Debe digitar un numero del 1 al 4" << endl;
			}
		} while (opcion != 4);
	}
	catch (const char* excepcion) {
		cout << excepcion << endl;
	}
	catch (...) {
		cout << "Hubo un problema inesperado. " << endl;
	}
}


void Controladora::control2() {
	Vista::despedida();
}

void Controladora::cargaPaci() {
	Vista::cargaPacientes();
	ges->leerPacientes(pacientito);
	system("pause");
}

void Controladora::cargaEnfer() {
	Vista::cargaEnfermedades();
	ges->leerEnfermedades(enfermedadcita);
	system("pause");
}

void Controladora::generaJSON() {
	cout << "-----------Generando Archivo JSON---------------" <<endl;
	cout << "-----------------Datos Cargados-----------------" << endl;
	ges->guardaPacientesJson(pacientito);
	ges->guardaEnfermedadesJson(enfermedadcita);
	ges->enfermedadPaciente(enfermedadcita, pacientito);
	cout << "Archivos JSON generados: " << endl;
	cout << "Archivo #1 = jsonPaciente.txt" <<endl;
	cout << "Archivo #2 = jsonEnfermedad.txt" <<endl <<endl;
	cout << "-----------------------------------------------" << endl;
	system("pause");
}

Controladora::~Controladora() {
	delete enfermedadcita;
	delete pacientito;
	delete ges;
}

