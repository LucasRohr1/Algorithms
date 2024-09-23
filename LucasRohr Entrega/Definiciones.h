#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include <iostream>
using namespace std;
#include <string.h>
#include <assert.h>


struct NodoLista {
	int dato;
	NodoLista *sig;
	NodoLista() : dato(0), sig(NULL) {}
	NodoLista(int d) : dato(d), sig(NULL) {}
};

struct NodoAB {
	int dato;
	NodoAB *izq;
	NodoAB *der;
	NodoAB() : dato(0), izq(NULL), der(NULL) {}
	NodoAB(int d) : dato(d), izq(NULL), der(NULL) {}
};

struct NodoAG {
	int dato;
	NodoAG *ph;
	NodoAG *sh;
	NodoAG() : dato(0), ph(NULL), sh(NULL) {}
	NodoAG(int d) : dato(d), ph(NULL), sh(NULL) {}
};

struct NodoListaDobleDato {
	int dato1;
	int dato2;
	NodoListaDobleDato *sig;
	NodoListaDobleDato() : dato1(0), dato2(0), sig(NULL) {}
	NodoListaDobleDato(int d1, int d2) : dato1(d1), dato2(d2), sig(NULL) {}
};

struct NodoABDobleDato {
	int dato1;
	int dato2;
	NodoABDobleDato *izq;
	NodoABDobleDato *der;
	NodoABDobleDato() : dato1(0), dato2(0), izq(NULL), der(NULL) {}
	NodoABDobleDato(int d1, int d2) : dato1(d1), dato2(d2), izq(NULL), der(NULL) {}
};

#endif