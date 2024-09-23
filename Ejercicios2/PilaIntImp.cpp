#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct _cabezalPilaInt {
	
	NodoListaInt* cima;
	NodoListaInt* fin;
	unsigned int largo;
	
};

/* FUNCIONES AUXILIARES:
*/

void insertarAlFinal(PilaInt &pila, int n) {

	NodoListaInt* nuevo = new NodoListaInt(n);
	if (pila->fin == NULL) {

		pila->fin = pila->cima = nuevo;
		pila->largo++;

	}
	else {

		pila->fin->sig = nuevo;
		pila->fin =nuevo;
		pila->largo++;
	}
}

/* FIN FUNCIONES AUXILIARES:
*/

PilaInt crearPilaInt(){
	
	PilaInt nuevo = new _cabezalPilaInt();
	nuevo->cima = NULL;
	nuevo->fin = NULL;
	nuevo->largo = 0;

	return nuevo;
	
	
	return NULL;
}

void push(PilaInt& p, int e) {
	
	NodoListaInt* nuevo = new NodoListaInt();
	nuevo->dato = 0;
	nuevo->sig = NULL;
	if (p->cima == NULL) {

		nuevo->dato = e;
		p->cima = nuevo;
		p->fin = nuevo;
		p->largo++;
	
	}
	else {

		//siempre inserto al principio
		nuevo->dato = e;
		nuevo->sig = p->cima;
		p->cima = nuevo;
		p->largo++;
	}
	
	
}

int top(PilaInt p) {
	
	if (p->cima != NULL) {
		return p->cima->dato;
	}
	
	

}

void pop(PilaInt& p) {
	
	if(p->cima != NULL){
		NodoListaInt* aBorrar = p->cima;
		p->cima = p->cima->sig;
		delete aBorrar;
		p->largo--;
	}
	
}

unsigned int cantidadElementos(PilaInt p) {
	
	return p->largo;	
}

bool esVacia(PilaInt p) {
	
	return (p->largo == 0);
}

PilaInt clon(PilaInt p) {
	
	PilaInt nuevo = crearPilaInt();
	NodoListaInt* iter = p->cima;
	
	if (!p) {

		nuevo = crearPilaInt();
	}
	else {

		while (iter) {

			insertarAlFinal(nuevo ,iter->dato);
			iter = iter->sig;
		}
	
	}
	return nuevo;
	
}

void destruir(PilaInt& p) {
	if (p) {

		while (p->cima) {

			NodoListaInt* aBorrar = p->cima;
			p->cima = p->cima->sig;
			delete aBorrar;
			p->largo--; 
		}

	}
	
}


#endif