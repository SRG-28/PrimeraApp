#include "GestorArchivos.h"

GestorArchivos::GestorArchivos() {}

void GestorArchivos::leerPacientes(Arreglo<Paciente>* pacientito) {
	Paciente* p = nullptr;
	string linea = "";
	string dato = "";
	fstream infile("pacientes.csv", ios::in);
	vector <string> datos_csv;
	if (infile.is_open()) {
		while (getline(infile, linea)) {
			stringstream sl(linea);
			while (getline(sl, dato, ',')) {
				datos_csv.push_back(dato);
			}
		}
		for (int unsigned i = 0; i < datos_csv.size(); i++) {
			if (i % 5 == 0) {
				p = new Paciente(datos_csv[i], datos_csv[i + 1], datos_csv[i + 2], datos_csv[i + 3], datos_csv[i + 4]);
				pacientito->ingresaAlArreglo(p);
				cout << p->toString() << endl;
			}
		}
		infile.close();
	}
	else {
		cout << "Error al abrir el archivo para lectura" << endl;
	}
}

void GestorArchivos::leerEnfermedades(Arreglo<Enfermedad>* enfermedadcita) {
	Enfermedad* enf = nullptr;
	string linea = "";
	string dato = "";
	fstream infile("enfermedades.csv", ios::in);
	vector <string> datos_csv;
	if (infile.is_open()) {
		while (getline(infile, linea)) {
			stringstream sl(linea);
			while (getline(sl, dato, ',')) {
				datos_csv.push_back(dato);
			}
		}
		for (int unsigned i = 0; i < datos_csv.size(); i++) {
			if (i % 2 == 0) {
				enf = new Enfermedad(datos_csv[i], datos_csv[i + 1]);
				enfermedadcita->ingresaAlArreglo(enf);
				cout << enf->toString() << endl;
			}
		}
		infile.close();
	}
	else {
		cout << "Error al abrir el archivo para lectura" << endl;
	}
}

void GestorArchivos::guardaEnfermedadesJson(Arreglo<Enfermedad>* enfermedadcita) {

	Enfermedad* e1 = nullptr;
	Json::StreamWriterBuilder constructor;
	constructor["commentStyle"] = "None";
	constructor["indentation"] = "  ";
	unique_ptr<Json::StreamWriter> escritor(constructor.newStreamWriter());
	ofstream archivoE("jsonEnfermedad.txt");
	Json::Value enfe;
	Json::Value ArregloE(Json::arrayValue);
	for (int i = 0; i < enfermedadcita->numElementos(); i++) {
		e1 = enfermedadcita->obtener(i);
		enfe["Nombre: "] = e1->getNombre();
		enfe["Secuencia: "] = e1->getSecuencia();
		ArregloE.append(enfe);
	}
	escritor->write(ArregloE, &archivoE);
	archivoE.close();
}


void GestorArchivos::guardaPacientesJson(Arreglo<Paciente>* pacientito) {
	Paciente* p1 = new Paciente;
	Enfermedad* e1 = new Enfermedad;
	Json::StreamWriterBuilder constructor;
	constructor["commentStyle"] = "None";
	constructor["indentation"] = "  ";
	unique_ptr<Json::StreamWriter> escritor(constructor.newStreamWriter());
	ofstream ArchivoP("jsonPaciente.txt");
	Json::Value paci;
	Json::Value ArregloP(Json::arrayValue);
	for (int i = 0; i < pacientito->numElementos(); i++) {
		p1 = pacientito->obtener(i);
		paci["Id: "] = p1->getId();
		paci["Nombre: "] = p1->getNombre();
		paci["Telefono: "] = p1->getTelefono();
		paci["Correo: "] = p1->getCorreo();
		paci["Secuencia: "] = p1->getSecuencia();
		paci["Enfermedad del paciente: "] = p1->getEnfermedadPaci();
		ArregloP.append(paci);
	}
	escritor->write(ArregloP, &ArchivoP);
	ArchivoP.close();
}

void GestorArchivos::enfermedadPaciente(Arreglo<Enfermedad>* enfermedadcita, Arreglo<Paciente>* pacientito) {
	string secuPaci = "";
	string secuEnfer = "";
	Paciente* p1 = nullptr;
	Enfermedad* e1 = nullptr;
	for (int i = 0; i < pacientito->numElementos(); i++) {
		p1 = pacientito->obtener(i);
		secuPaci = p1->getSecuencia();
		cout << "Paciente:" << p1->getNombre() << endl;
		for (int i = 0; i < enfermedadcita->numElementos(); i++) {
			e1 = enfermedadcita->obtener(i);
			secuEnfer = e1->getSecuencia();
			if (secuPaci.find(secuEnfer) != string::npos) {
				p1->agregarEnfermedad(e1);
			}
		}
		cout << p1->toString();
	}
}




string GestorArchivos::Analisis2(Arreglo<Paciente>* pacientito,string id) {
	stringstream bases;
	Paciente* carlitos = nullptr;
	string sec = "";
	string extraer = "";
	int A = 0, T = 0, G = 0, C = 0, total = 0;
	try {
	for (int i = 0; i < pacientito->numElementos(); i++) {
		carlitos = pacientito->obtener(i);
		if (carlitos->getId() == id) {
			sec = carlitos->getSecuencia();
			for (unsigned int i = 0; i < sec.size(); i++) {
				extraer = sec.substr(i, 1);
				total++;
				if (extraer == "A") {
					A++;
				}
				if (extraer == "T") {
					T++;
				}
				if (extraer == "G") {
					G++;
				}
				if (extraer == "C") {
					C++;
				}
			}
			bases << "Base nitrogenada tipo A: " << A << ". Porcentaje: " << A / total * 100 << endl;
			bases << "Base nitrogenada tipo T: " << T << ". Porcentaje: " << T / total * 100 << endl;
			bases << "Base nitrogenada tipo G: " << G << ". Porcentaje: " << G / total * 100 << endl;
			bases << "Base nitrogenada tipo C: " << C << ". Porcentaje: " << C / total * 100 << endl;
		}
	}
	return bases.str();
	if (carlitos == nullptr) {
			throw 55;
		}
	}
	catch (int exc) {
		if (exc == 5) {
			return "No se encontro ese codigo en la lista de pacientes. \n\n";
		}
	}
	//system("pause");
	return 0;
}