#include "TablaIntString.h"

#ifdef TABLA_INT_STRING_IMP


int funcion_hash(int posicion, int cota) {

	return abs(posicion % cota);
}

struct nodoHash {

	unsigned int dominio;
	const char* rango;
	nodoHash* sig;
};

struct _cabezalTablaIntString {
	
	nodoHash** tabla;
	int cantElementos;
	int cota;
};

/// FUNCIONES AUXILIARES

// Pre: recibe una tabla "t" y un dominio "d" donde estaDefinida(t, d)
// Pos: retorna un puntero apuntando al nodo con dominio d
nodoHash* obtenerPtrNodo(TablaIntString t, int d) {

	if (t) {

		int bucketD = funcion_hash(d, t->cota);
		nodoHash* ptrNodo = t->tabla[bucketD];
		while (ptrNodo) {

			if (ptrNodo->dominio == d) {

				return ptrNodo;
			}
			else {

				ptrNodo = ptrNodo->sig;
			}
		}
		return NULL;
	}
}

// PRE: recibe un puntero al principio de la lista en el bucket correspondiente donde esta "d" 
// POS: elimina "d" de la lista

void borrarAuxT(nodoHash*& lista, int d) {

	if (lista != NULL) {

		if (lista->dominio == d) {

			nodoHash* aBorrar = lista;
			lista = lista->sig;
			delete aBorrar;
			aBorrar = NULL;
			

		}
		else {

			borrarAuxT(lista->sig, d);
		}
	}
}


/// FIN FUNCIONES AUXILIARES




TablaIntString crearTablaIntString(unsigned int esperados) {
	
	TablaIntString d = new _cabezalTablaIntString();
	d->tabla = new nodoHash* [esperados];
	for (int i = 0; i < esperados; i++) {
		d->tabla[i] = NULL;
	}
	d->cantElementos = 0;
	d->cota = esperados;

	return d;
}


void agregar(TablaIntString& t, int d, const char* r) {
	
	if(t){
		if (estaDefinida(t, d)) {

			nodoHash* nodoD = obtenerPtrNodo(t, d);
			nodoD->rango = r;
		}
		else {

			nodoHash* nuevo = new nodoHash;
			nuevo->dominio = d;
			nuevo->rango = r;
			nuevo->sig = t->tabla[funcion_hash(d, t->cota)];
			t->tabla[funcion_hash(d, t->cota)] = nuevo;

			t->cantElementos++;
		}
	}
}

bool estaDefinida(TablaIntString t, int d) {
	
	if (t) {
		int bucketD = funcion_hash(d, t->cota);
		nodoHash* ptrNodo = t->tabla[bucketD];
		while (ptrNodo) {

			if (ptrNodo->dominio == d) {

				return true;
			}
			else {

				ptrNodo = ptrNodo->sig;
			}
		}
		return false;

	}
	else {

		return false;
	}
}

const char* recuperar(TablaIntString t, int d) {
	
	nodoHash* nodoRecuperado = obtenerPtrNodo(t, d);
	if (nodoRecuperado != NULL) {

		return nodoRecuperado->rango; // pide retornar T(d), esta bien?
	}
	else {

		return NULL;
	}
}

void borrar(TablaIntString& t, int d) {
	
	if (t && estaDefinida(t, d)) {

		borrarAuxT(t->tabla[funcion_hash(d, t->cota)], d);
		t->cantElementos--;
	}
}

int elemento(TablaIntString t) {
	
	for (int i = 0; i < t->cota; i++) {

		nodoHash* iter = t->tabla[i];
		if (iter) {

			return iter->dominio;
		}
	}
}

bool esVacia(TablaIntString t) {
	
	if (t) {

		return t->cantElementos == 0;
	}
}

unsigned int cantidadElementos(TablaIntString t) {
	
	if (t) {

		return t->cantElementos;
	}
}

void destruir(TablaIntString& t) {
	
	if (t) {
		if (!esVacia(t)) {

			for (int i = 0; i < t->cota; i++) {

				nodoHash* iter = t->tabla[i];
				while (iter != NULL) {

					borrar(t, iter->dominio);
					if (t->tabla[i] == NULL) {

						break;
					}
					else {
						iter = t->tabla[i];
					}
				}
			}
		}
		delete[] t->tabla; 
		delete t; 
		t = NULL;
	}
}

TablaIntString clon(TablaIntString t) {
	
	TablaIntString clonT = crearTablaIntString(t->cota);
	if (t) {

		for (int i = 0; i < t->cota; i++) {

			nodoHash* iter = t->tabla[i];
			while (iter) {

				agregar(clonT, iter->dominio, iter->rango);
				iter = iter->sig;
			}
		}
		return clonT;
	}
	else {

		return clonT;
	}
}

#endif