#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP

struct NodoMultiset {

	int dato;
	int ocurrencias;
	NodoMultiset* sig;
	NodoMultiset() : dato(0), ocurrencias(0), sig(NULL) {}
	NodoMultiset(int d, int o) : dato(d), ocurrencias(o), sig(NULL) {}
};

struct _cabezalMultisetInt {

	NodoMultiset* lista;
	int cantElementos;
};


/// FUNCIONES AUXILIARES


//PRE: recibe una lista NodoMultiset y un entero e
//POS: devuelve true si esta el dato e en la lista
bool auxEstaDato(NodoMultiset* lista, int e) {

	if (lista == NULL) {

		return false;
	}
	while (lista != NULL) {

		if (lista->dato == e) {

			return true;
		}
		lista = lista->sig;
	}
	return false; 
}

//PRE: recibe una lista NodoMultiset y un entero e
//POS: elimina el nodo conteniendo el elemento e de la lista
void borrarAux(NodoMultiset*& nodo, int dato) {

	if (nodo != NULL) {
		if (dato == nodo->dato) {

			NodoMultiset* aBorrar = nodo;
			nodo = nodo->sig;
			delete aBorrar;
			return;
		}
		else {

			borrarAux(nodo->sig, dato);
		}
	}
}


//PRE: recibe una lista de tipo multiset llamada nodo y un int e
//POS: devuelve la cantidad de ocurrencias del nodo que contiene el elemento e
int devolverCantOcurrencias(NodoMultiset* nodo, int e) {

	while (nodo != NULL) {
		if (nodo->dato == e)
			return nodo->ocurrencias;

		nodo = nodo->sig;
	}


}

//PRE: recibe una lista de tipo NodoMultiset*, int e, y su ocurrencia
//POS: devuelve true || false dependiendo si el elemento e tiene al menos la cantidad de ocurrencias especificada (ocurrencia)  

bool datoConOcurrenciaSuficiente(NodoMultiset* lista, int e, int ocurrencia) {

	if (lista == NULL) {

		return false;
	}
	while (lista != NULL) {
		if (lista->dato == e && lista->ocurrencias >= ocurrencia) {

			return true;
		}
		lista = lista->sig;
	}
	return false; 

}


/// FIN FUNCIONES AUXILIARES



MultisetInt crearMultisetInt() {

	MultisetInt multiSet = new _cabezalMultisetInt();
	multiSet->lista = NULL;
	multiSet->cantElementos = 0;

	return multiSet;
}

void agregar(MultisetInt& s, int e, unsigned int ocurrencias) {

	NodoMultiset* nodo = s->lista;
	if (nodo == NULL) {

		NodoMultiset* nuevo = new NodoMultiset(e, ocurrencias);
		nuevo->sig = NULL;
		s->lista = nuevo;
		s->cantElementos += ocurrencias;
		return;
	}
	else if (auxEstaDato(s->lista, e)) {

		while (nodo != NULL) {
			if (nodo->dato == e) {

				nodo->ocurrencias += ocurrencias;
				s->cantElementos += ocurrencias;
				return;
			}
			nodo = nodo->sig;
		}
	}
	else {

		NodoMultiset* nuevo = new NodoMultiset(e, ocurrencias);
		nuevo->sig = s->lista;
		s->lista = nuevo;
		s->cantElementos += ocurrencias;
	}
}


void borrar(MultisetInt& s, int e) {

	NodoMultiset* listaS = s->lista;
	if (auxEstaDato(listaS, e)) {
		
		while (listaS != NULL) {
			if (listaS->dato == e) {
				if (listaS->ocurrencias > 1) {
					
					listaS->ocurrencias--;
					s->cantElementos--;

					return;
				}
				else {
					borrarAux(s->lista, e);
					s->cantElementos--;

					return;
				}
			}
			listaS = listaS->sig;
		}
	}
}

bool pertenece(MultisetInt s, int e) {

	return (auxEstaDato(s->lista, e));
}


MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {

	MultisetInt retorno = crearMultisetInt();
	NodoMultiset* listaS1 = s1->lista;
	NodoMultiset* listaS2 = s2->lista;
	while (listaS1 != NULL) {

		agregar(retorno, listaS1->dato, listaS1->ocurrencias);
		listaS1 = listaS1->sig;
	}

	while (listaS2 != NULL) {

		if (auxEstaDato(retorno->lista, listaS2->dato)) {

			int cantidadDato = devolverCantOcurrencias(retorno->lista, listaS2->dato);
			if (cantidadDato - listaS2->ocurrencias < 0) {

				agregar(retorno, listaS2->dato, listaS2->ocurrencias - cantidadDato);
			}
		}
		else {
			agregar(retorno, listaS2->dato, listaS2->ocurrencias);
		}

		listaS2 = listaS2->sig;
	}

	return retorno;
}

MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {

	MultisetInt retorno = crearMultisetInt();
	NodoMultiset* listaS1 = s1->lista;
	NodoMultiset* listaS2 = s2->lista;

	while (listaS1 != NULL) {
		if (auxEstaDato(listaS2, listaS1->dato)) {

			int ocurrenciaPoner = devolverCantOcurrencias(listaS2, listaS1->dato);
			int ocurrenciaDevolver = (ocurrenciaPoner < listaS1->ocurrencias) ? ocurrenciaPoner : listaS1->ocurrencias;
			agregar(retorno, listaS1->dato, ocurrenciaDevolver);
		}
		listaS1 = listaS1->sig;
	}
	return retorno;
}


MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {

	MultisetInt devolver = crearMultisetInt();
	NodoMultiset* auxS1 = s1->lista;
	NodoMultiset* auxS2 = s2->lista;

	while (auxS1 != NULL) {
		if (auxEstaDato(auxS2, auxS1->dato)) {
			int ocuxs2 = devolverCantOcurrencias(auxS2, auxS1->dato);

			int ocurrenciasDato = auxS1->ocurrencias - ocuxs2;
			if (ocurrenciasDato > 0) {
				agregar(devolver, auxS1->dato, ocurrenciasDato);
			}

		}
		else {
			agregar(devolver, auxS1->dato, auxS1->ocurrencias);
		}
		auxS1 = auxS1->sig;
	}

	return devolver;
}


bool contenidoEn(MultisetInt s1, MultisetInt s2) {

	NodoMultiset* auxS1 = s1->lista;
	NodoMultiset* auxS2 = s2->lista;

		while (auxS1 != NULL) {
			if (!datoConOcurrenciaSuficiente(auxS2, auxS1->dato, auxS1->ocurrencias)) {

				return false;
			}
			auxS1 = auxS1->sig;
		}

		return true;
}

int elemento(MultisetInt s) {

	return s->lista->dato;
}

bool esVacio(MultisetInt s) {

	return s->cantElementos == 0;
}

unsigned int cantidadElementos(MultisetInt s) {

	return s->cantElementos;
}

void destruir(MultisetInt& s) {

	while (s->lista != NULL) {

		NodoMultiset* aux = s->lista;
		s->lista = s->lista->sig;
		delete aux;
	}
}


MultisetInt clon(MultisetInt s) {

	MultisetInt retorno = crearMultisetInt();
	NodoMultiset* iter = s->lista;
	while (iter) {

		agregar(retorno, iter->dato, iter->ocurrencias);
		iter = iter->sig;
	}
	return retorno;
}
#endif