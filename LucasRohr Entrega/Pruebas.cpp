#include "Pruebas.h"

#ifndef PRUEBAS_CPP
#define PRUEBAS_CPP

void Pruebas() {
	ManejadorSalidaPrueba manejadorSalidaPrueba = ManejadorSalidaPrueba::getInstancia();
	manejadorSalidaPrueba.crearDirectorio("SalidaDeLasPruebas");
	manejadorSalidaPrueba.crearDirectorio("Resultados");
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	system("del /Q .\\*.*");
#endif
	manejadorSalidaPrueba.setSalidaArchivo("PruebasPropias.txt");
	PruebasPropias();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasDefensa.txt");
	PruebasDefensa();	
	manejadorSalidaPrueba.setSalidaArchivo("PruebasComienzo.txt");
	PruebasComienzo();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasListas.txt");
	PruebasListas();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasArboles.txt");
	PruebasArboles();
	manejadorSalidaPrueba.setSalidaPantalla();
}

#endif