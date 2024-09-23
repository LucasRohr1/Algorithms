#include "Ejercicios.h"

// FUNCIONES AUXILIARES

// PRE: recibe dos pilas aux y p2
// POS: traspasa todos los datos de aux a p2 y deja aux vacia
void traspasarDatos(PilaInt aux, PilaInt p2) {

	while (!esVacia(aux)) {

		push(p2, top(aux));
		pop(aux);
	}

}


// FIN FUNCIONES AUXILIARES
ListaOrdInt Enlistar(NodoABInt* a)
{
	ListaOrdInt retorno = crearListaOrdInt();
	if (!a) {

		return retorno;
	}
	else {

		retorno = Enlistar(a->der);
		agregar(retorno, a->dato);
		ListaOrdInt listaIzq = Enlistar(a->izq);

		while (!esVacia(listaIzq)) {

			agregar(retorno, maximo(listaIzq));
			borrarMaximo(listaIzq);
		}

		destruir(listaIzq);
		return retorno;
	}
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	ListaOrdInt retorno = crearListaOrdInt();

	while (!esVacia(l1)) {

		agregar(retorno, minimo(l1));
		borrarMinimo(l1);

	}
	while (!esVacia(l2)) {

		agregar(retorno, minimo(l2));
		borrarMinimo(l2);

	}

	return retorno;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	
	bool pertenece = true;
	PilaInt clonP1 = clon(p1);
	PilaInt clonP2 = clon(p2);
	PilaInt aux = crearPilaInt();

	if (!esVacia(clonP1) && esVacia(clonP2)) {

		return false;
	}
	else {

		while (!esVacia(clonP1)) {

			int largoP1 = cantidadElementos(clonP1);
			while (!esVacia(clonP2)) {

				if (top(clonP1) == top(clonP2)) {

					pop(clonP1);
					pop(clonP2);
					traspasarDatos(aux, clonP2);
					break;
				}
				else {

					push(aux, top(clonP2));
					pop(clonP2);
				}
			}
			if (largoP1 == cantidadElementos(clonP1)) { // recorri todo clonP2, y aun tengo datos en clonP1

				return false;
			}
		}
		if (!esVacia(clonP1) && esVacia(clonP2)) {

			return false;
		}
		if (cantidadElementos(clonP1) == 0) { // si clonP1 tiene 0 elementos, quiere decir que p1 esta contenida en p2

			return true;
		}
	}	

	return false;
}


ListaOrdInt ObtenerRepetidos(MultisetInt m) 
{
	
	ListaOrdInt elementosRepetidos = crearListaOrdInt();
	while (!esVacio(m)) {

		int elementoActual = elemento(m);
		borrar(m, elementoActual);
		if (pertenece(m, elementoActual)) {
			// Si elementoActual sigue estando en m luego de borrarlo, es porque tiene mas de una ocurrencia
			if (!existe(elementosRepetidos, elementoActual)) {
				// si entra aca es porque
				agregar(elementosRepetidos, elementoActual);
			}
		}
	}

	return elementosRepetidos;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	MultisetInt diferencia1;
	MultisetInt diferencia2;

	diferencia1 = diferenciaConjuntos(m1, m2);
	diferencia2 = diferenciaConjuntos(m2, m1);

	return unionConjuntos(diferencia1, diferencia2);
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {

	ColaPrioridadInt clon1 = clon(c);
	ColaPrioridadInt clon2 = clon(c);

	// Encuentra la menor prioridad en clon1
	int menorPrioridad = principioPrioridad(clon1);
	while (!esVacia(clon1)) {

		menorPrioridad = principioPrioridad(clon1);
		desencolar(clon1);
	}
	// Cuento cuantos elementos hay con la minima prioridad para luego crear retorno con cota = cantElementosDeMenorPrioridad
	int cantElementosDeMenorPrioridad = 0;
	while (!esVacia(clon2)) {

		if (principioPrioridad(clon2) == menorPrioridad) {

			cantElementosDeMenorPrioridad++;
		}
		desencolar(clon2);
	}

	ColaPrioridadInt retorno = crearColaPrioridadInt(cantElementosDeMenorPrioridad);
	// reinicio clon2
	clon2 = clon(c);

	// Encola todos los elementos (por si hay mas de uno con la misma minima prioridad) con la menor prioridad en retorno
	while (!esVacia(clon2)) {

		if (principioPrioridad(clon2) == menorPrioridad) {

			encolar(retorno, principio(clon2), principioPrioridad(clon2));
		}
		desencolar(clon2);
	}

	destruir(clon1);
	destruir(clon2);

	return retorno;
}

