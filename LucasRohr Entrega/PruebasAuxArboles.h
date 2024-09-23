#pragma once

#include <sstream>
#include <string>
#include <iostream>
#include "FuncAux.h"
#include "EjerciciosArboles.h"
#include "Definiciones.h"

bool PruebaAltura(const char* inputTree, int output, int &nroPrueba);
bool PruebaSonIguales(const char* inputArbol1, const char* inputArbol2, bool output, int &nroPrueba);
bool PruebaExisteCaminoConSuma(const char* inputArbol, int suma, bool output, int &nroPrueba);
bool PruebaEsArbolBalanceado(const char* inputArbol, bool output, int &nroPrueba);
bool PruebaEnNivel(const char* inputArbol, int k, const char* output, int &nroPrueba);
bool PruebaCantNodosEntreNiveles(const char* inputArbol, int desde, int hasta, int output, int &nroPrueba);
bool PruebaCamino(const char* inputArbol, int x, const char* output, int &nroPrueba);
bool PruebaInvertirHastak(const char* inputArbol, int k, const char* output, int &nroPrueba);
bool PruebaBorrarNodoRaiz(const char* inputArbol, const char *output, int &nroPrueba);
bool PruebaSumaABB(const char* inputArbol, int n, bool output, int &nroPrueba);
bool PruebaSucesorABB(const char* inputArbol, int n, int output, int &nroPrueba);
bool PruebaNivelMasNodos(const char* inputArbol, int nivelHasta, int output, int &nroPrueba);
bool PruebaBorrarPares(const char *inputABB, const char *outputABB, int &nroPrueba);

bool PruebaAlturaAG(const char *inputTree, int output, int &nroPrueba);
bool PruebaSumaPorNiveles(const char *inputTree, int output, int &nroPrueba);
bool PruebaEsPrefijo(const char *inputTree, const char *inputList, bool output, int &nroPrueba);
bool PruebaCaminoAG(const char *inputTree,int dato, const char* outputList, int &nroPrueba);
bool PruebaNivelConMasNodosAG(const char *inputTree, int output, int &nroPrueba);

