#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP_2

struct NodoABB {
	int dato;
	NodoABB* izq;
	NodoABB* der;
	NodoABB() : dato(0), izq(NULL), der(NULL) {}
	NodoABB(int d) : dato(d), izq(NULL), der(NULL) {}
};

struct _cabezalListaOrdInt {
	NodoABB* raiz;
	int cantElementos;
};


// FUNCIONES AUXILIARES

void agregarAux(NodoABB*& r, NodoABB* nuevo) {

	if (r == NULL) {

		r = nuevo;
	}
	else if (nuevo->dato < r->dato) {

		agregarAux(r->izq, nuevo);
	}
	else {

		agregarAux(r->der, nuevo);
	}
}

void borrarAux(ListaOrdInt& l, NodoABB*& r, int e) {

	if (r != NULL) {

		if (e < r->dato) {

			borrarAux(l, r->izq, e);
		}
		else if (e > r->dato) {

			borrarAux(l, r->der, e);
		}
		else {

			if (!r->izq && !r->der) { // caso 1

				delete r;
				r = NULL;
				l->cantElementos--;
			}
			else if (!r->izq || !r->der) { // caso 2

				NodoABB* aux = r;
				r = r->izq ? r->izq : r->der;
				delete aux;
				l->cantElementos--;
			}
			else { // caso 3

				NodoABB* aux = r->izq;
				while (aux->der) {

					aux = aux->der;
				}
				r->dato = aux->dato;
				borrarAux(l, r->izq, aux->dato);
			}
		}
	}
}

bool existeAux(NodoABB* r, int e) {

	if (r == NULL) {

		return false;
	}
	else if (r->dato == e) {

		return true;
	}
	else if (e < r->dato) {

		return existeAux(r->izq, e);
	}
	else {

		return existeAux(r->der, e);
	}
}

void borrarMinimoAux(NodoABB*& r) {

	if (r->izq == NULL) {

		NodoABB* aBorrar = r;
		r = r->der;
		delete aBorrar;
	}
	else {

		borrarMinimoAux(r->izq);
	}
}

void borrarMaximoAux(NodoABB*& r) {

	if (r->der == NULL) {

		NodoABB* aBorrar = r;
		r = r->izq;
		delete aBorrar;
	}
	else {

		borrarMinimoAux(r->der);
	}
}

int minimoAux(NodoABB* r) {

	while (r->izq) {
		r = r->izq;
	}
	return r->dato;
}

int maximoAux(NodoABB* r) {

	while (r->der) {
		r = r->der;
	}
	return r->dato;
}

NodoABB* clonAux(NodoABB* r) {

	if (r == NULL) {

		return NULL;
	}
	NodoABB* copia = new NodoABB(r->dato);
	copia->izq = clonAux(r->izq);
	copia->der = clonAux(r->der);

	return copia;
}

void destruirAux(NodoABB* r) {

	if (r != NULL) {

		destruirAux(r->izq);
		destruirAux(r->der);
		delete r;
	}
}

// FIN FUNCIONES AUXILIARES


ListaOrdInt crearListaOrdInt() {
	
	ListaOrdInt nuevo = new _cabezalListaOrdInt();
	nuevo->cantElementos = 0;
	nuevo->raiz = NULL;
	return nuevo;
}

void agregar(ListaOrdInt& l, int e) {
	
	NodoABB* nuevo = new NodoABB(e);
	agregarAux(l->raiz, nuevo);
	l->cantElementos++;
}

void borrarMinimo(ListaOrdInt& l) {
	
	if (l->raiz != NULL) {

		borrarMinimoAux(l->raiz);
		l->cantElementos--;
	}
}

void borrarMaximo(ListaOrdInt& l) {
	
	if (l->raiz != NULL) {

		borrarMaximoAux(l->raiz);
		l->cantElementos--;
	}
}

void borrar(ListaOrdInt& l, int e) {
	
	if (l) {

		borrarAux(l, l->raiz, e);
	}
}

int minimo(ListaOrdInt l) {
	
	return minimoAux(l->raiz);
}

int maximo(ListaOrdInt l) {
	
	return maximoAux(l->raiz);
}

bool existe(ListaOrdInt l, int e) {
	
	if (l) {

		return existeAux(l->raiz, e);
	}
	
}

bool esVacia(ListaOrdInt l) {
	
	if (l != NULL) {

		return l->cantElementos == 0;
	}
	else {

		return true;
	}
	
}

unsigned int cantidadElementos(ListaOrdInt l) {
	
	if (l != NULL) {

		return l->cantElementos;

	}else{

		return 0;
	}
	
}

ListaOrdInt clon(ListaOrdInt l) {
	
	if(l){
		ListaOrdInt nuevo = crearListaOrdInt();
		nuevo->cantElementos = l->cantElementos;
		nuevo->raiz = clonAux(l->raiz);
		return nuevo;
	}
	
}

void destruir(ListaOrdInt& l) {
	
	if (l) {

		destruirAux(l->raiz);
		delete l;
	}

}



#endif