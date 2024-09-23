#include "DiccionarioInt.h"

#ifdef DICCIONARIO_INT_IMP

int f_hash(int posicion, int cota) { 
	
	return abs(posicion % cota);
} 

struct nodoHash {
	int dato;
	nodoHash* sig;
};


struct _cabezalDiccionarioInt {
	
	nodoHash** tabla;
	int cantElementos; 
	int cota;
};


//////////////// FUNCIONES AUXILIARES

// PRE: recibe un puntero al principio de la lista en el bucket correspondiente donde esta "d" 
// POS: elimina "d" de la lista

void borrarAux(nodoHash*& lista, int e) {

	if (lista != NULL) {
		if (lista->dato == e) {

			nodoHash* aBorrar = lista;
			lista = lista->sig;
			delete aBorrar;
		}
		else {
			borrarAux(lista->sig, e);
		}
	}
}

void destruirLista(nodoHash*& lista) {

	if (lista != NULL) {

		destruirLista(lista->sig);
		delete lista;
		lista = NULL;
	}
}

////////////// FIN FUNCIONES AUXILIARES





DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	
	DiccionarioInt d = new _cabezalDiccionarioInt();
	d->tabla = new nodoHash * [esperados];
	for (int i = 0; i < esperados; i++) {
		d->tabla[i] = NULL;
	}
	d->cantElementos = 0;
	d->cota = esperados;

	return d;
}

void agregar(DiccionarioInt& d, int e) {
	
	if (d) {
		if (!pertenece(d, e)) {

			nodoHash* nuevo = new nodoHash;
			nuevo->dato = e;
			int pos = f_hash(e, d->cota);
			nuevo->sig = d->tabla[pos];
			d->tabla[pos] = nuevo;

			d->cantElementos++;
		}
	}
}


void borrar(DiccionarioInt& d, int e) {
	
	if (d && pertenece(d, e)) {

		int pos = f_hash(e, d->cota);
		borrarAux(d->tabla[pos], e);
		d->cantElementos--;
	}
}

bool pertenece(DiccionarioInt d, int e) {

	if (d) {

		int pos = f_hash(e, d->cota);
		nodoHash* lista = d->tabla[pos];
		while (lista != NULL && lista->dato != e) {

			lista = lista->sig;
		}  
		return lista != NULL;
	}
}

int elemento(DiccionarioInt d) {
	

	for (int i = 0; i < d->cota; i++) {

		nodoHash* iter = d->tabla[i];
		while (iter) {

			return iter->dato;
		}
	}
}

bool esVacio(DiccionarioInt d) {

	return d && d->cantElementos == 0;	
}

unsigned int cantidadElementos(DiccionarioInt d) {
	
	return d ? d->cantElementos : 0;	
}

DiccionarioInt clon(DiccionarioInt d) {
	
	DiccionarioInt clonD = crearDiccionarioInt(d->cota);

	for (int i = 0; i < d->cota; i++) {

		nodoHash* iter = d->tabla[i];
		while (iter) {

			agregar(clonD, iter->dato);
			iter = iter->sig;
		}
	}
	return clonD;
}

void destruir(DiccionarioInt& d) {
	
	for (int i = 0; i < d->cota; i++) {

		destruirLista(d->tabla[i]);
	}
	delete[] d->tabla;
	delete d;
}


#endif