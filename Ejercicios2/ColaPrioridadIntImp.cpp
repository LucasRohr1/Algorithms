#include "ColaPrioridadInt.h"

#ifdef COLAPRIORIDAD_INT_IMP

struct NodoPrioridad {

	int dato;
	int prioridad;
	NodoPrioridad* sig;
	NodoPrioridad() : dato(0), prioridad(0), sig(NULL) {}
	NodoPrioridad(int d, int p) : dato(d), prioridad(p), sig(NULL) {}
};

struct _cabezalColaPrioridadInt {
	
	NodoPrioridad* lista;
	unsigned int cota;
	int cantElementos;
};


/* FUNCIONES AUXILIARES:
*/

// PRE: Recibe lista de NodoPrioridad no vacia y un nodoPrioridad
// POS: Agrega el nodo a su lugar correspondiente en la lista
void encolarAux(NodoPrioridad*& lista, NodoPrioridad* nodo) {

	if (!lista || nodo->prioridad > lista->prioridad) {
		//insertarComienzo
		nodo->sig = lista;
		lista = nodo;
	}
	else {
		encolarAux(lista->sig, nodo);
	}
}

/* FIN FUNCIONES AUXILIARES:
*/

ColaPrioridadInt crearColaPrioridadInt(unsigned int cota) {
	
	ColaPrioridadInt nuevo = new _cabezalColaPrioridadInt();
	nuevo->lista = NULL;
	nuevo->cota = cota;
	nuevo->cantElementos = 0;

	return nuevo;
}

void encolar(ColaPrioridadInt& c, int e, int p) {
	
	if (c && c->cantElementos < c->cota && c->cota > 0) { // por las dudas verifico esto

		NodoPrioridad* nuevo = new NodoPrioridad(e, p);
		//nuevo->sig = NULL;
		if (esVacia(c)) { 

			c->lista = nuevo;
		}
		else {

			encolarAux(c->lista, nuevo);
		}
		c->cantElementos++;
	}
}

int principio(ColaPrioridadInt c) {
	
	return c && c->lista != NULL ? c->lista->dato : NULL;
}

int principioPrioridad(ColaPrioridadInt c) {
	
	return c && c->lista != NULL ? c->lista->prioridad : NULL;
}

void desencolar(ColaPrioridadInt& c) {
	
	NodoPrioridad* aBorrar = c->lista;
	c->lista = c->lista->sig;
	delete aBorrar;
	c->cantElementos--;
}

bool esVacia(ColaPrioridadInt c) {
	
	return c && c->cantElementos == 0;
}

bool esLlena(ColaPrioridadInt c) {
	
	return c && c->cantElementos == c->cota;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	
	return c ? c->cantElementos: 0;

}


ColaPrioridadInt clon(ColaPrioridadInt c) {
	
	ColaPrioridadInt clonC = crearColaPrioridadInt(c->cota);
	NodoPrioridad* iter = c->lista;
	while (c && iter != NULL) {

		encolar(clonC, iter->dato, iter->prioridad);
		iter = iter->sig;
	}
	return clonC;
}


void destruir(ColaPrioridadInt& c) {
	
	while (c && c->lista != NULL) {
		desencolar(c);
	}
	delete c;
	c = NULL;
	
}

#endif