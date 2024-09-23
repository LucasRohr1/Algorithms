#pragma once

#include "FuncAux.h"
#include "EjerciciosComienzo.h"

bool PruebaSuma(int a, int b, int output, int &nroPrueba);
bool PruebaImprimirTabla(unsigned int tablaDel, unsigned int desde, unsigned int hasta, const char* output, int &nroPrueba);

bool PruebaSimplificar(int n, int d, const char *output, int &nroPrueba);
bool PruebaOcuerrencias123Repetidos(const char* vector, int output, int &nroPrueba);
bool PruebaMaximoNumero(unsigned int n, const char* vector, int output, int &nroPrueba);
bool PruebaOrdenarVecInt(const char* vecStr, const char* output, int &nroPrueba);

bool PruebaInvertirCase(const char *substr, const char* output, int &nroPrueba);
bool PruebaIslas(const char* datosMapa, int col, int fil, int output, int &nroPrueba);
bool PruebaOcurrenciasSubstring(const char *stringVecStr, const char *substr, int output, int &nroPrueba);
bool PruebaOrdenarVecStr(const char* vecStr, const char* output, int &nroPrueba);
bool PruebaIntercalarVector(const char* vector1, const char* vector2, const char* vectorOutput, int &nroPrueba);
bool PruebaSubconjuntoVector(const char* vector1, const char* vector2, bool output, int &nroPrueba);
bool PruebaSplitStr(const char* entrada, char separador, const char* output, int &nroPrueba);
bool PruebaOrdenarVecIntMergeSort(const char* inputVector, const char* output, int&nroPrueba);
