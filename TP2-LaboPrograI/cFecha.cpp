#include "gbl.h"
#include "cFecha.h"

// implementacion cFecha

cFecha::cFecha(sh _dia, sh _mes, sh _anio, sh _hora) {
	// inicializacion de los atributos
	try {
		if (isValid(_dia, _mes, _anio, _hora)) {
			this->dia = _dia;
			this->mes = _mes;
			this->anio = _anio;
			this->hora = _hora;
		}
		else
			throw "Se esta especificando una fecha invalida";
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
}

cFecha::~cFecha() {
	// no tengo nada que eliminar
}

bool cFecha::isValid(sh _dia, sh _mes, sh _anio, sh _hora) {
	// posibles errores comunes en la fecha
	if (_hora < 0 || _hora > 24) 
		return false;
	else if (_anio != 2022)
		return false;
	else if (_mes < 1 || _mes > 12)
		return false;
	else if (_dia < 1 || _dia > 31)
		return false;

	// manejo del mes de Febrero
	if (_mes == 2) {
		if (dia <= 28)
			return true;
		else return false;
	}

	// los meses de Abril, Junio, Septiembre y Noviembre tienen 30 dias
	else if (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11) {
		if (_dia <= 30)
			return true;
		return false;
	}
	return true;
}

string cFecha::to_string()const {
	stringstream stc;
	stc << "Dia: " << this->dia << endl;
	stc << "Mes: " << this->mes << endl;
	stc << "Anio: " << this->anio << endl;
	stc << "Hora: " << this->hora << endl;
	return stc.str();
}