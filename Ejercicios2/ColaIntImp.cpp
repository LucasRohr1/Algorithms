#include "ColaInt.h"
#include "PilaInt.h"
#ifdef COLA_INT_IMP

struct _cabezalColaInt {
	NodoListaInt* ppio;
	NodoListaInt* fin;
	int cantElementos;
	

};

ColaInt crearColaInt() {
	
	ColaInt cola = new _cabezalColaInt();
	cola->ppio = NULL;
	cola->fin = NULL;
	cola->cantElementos = 0;

	return cola;
}

void encolar(ColaInt& c, int e) {
	
	NodoListaInt* nuevo = new NodoListaInt();
	nuevo->dato = e;
	nuevo->sig = NULL;

	if (c->ppio == NULL ) {

		c->ppio = c->fin = nuevo;
	}
	else {

		c->fin->sig = nuevo;
		c->fin = c->fin->sig;
	}
	c->cantElementos++;
}

int principio(ColaInt c) {
	
	return c->ppio->dato;
}

void desencolar(ColaInt& c) {
	
	NodoListaInt* aBorrar = c->ppio;
	if (c->ppio->sig == NULL) { 
		//solo 1 elemento en la cola

		c->ppio = c->fin = NULL;
		delete aBorrar;
	}
	else {

		c->ppio = c->ppio->sig;
		delete aBorrar;
	}
	c->cantElementos--;
	
}

bool esVacia(ColaInt c) {
	
	return c->cantElementos == 0;
}

unsigned int cantidadElementos(ColaInt c) {
	
	return c->cantElementos;
}

ColaInt clon(ColaInt c) {
	
	ColaInt clonC = crearColaInt();
	clonC->ppio = clonC->fin = NULL;
	NodoListaInt* iter = c->ppio;

	while (iter) {

		encolar(clonC, iter->dato);
		iter = iter->sig;
	}

	return clonC;
}

void destruir(ColaInt& c) {
	
	NodoListaInt* iter = c->ppio;
	while (iter) {

		desencolar(c);
		iter = iter->sig;
	}
}

#endif