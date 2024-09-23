#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct _cabezalListaPosInt {
	int* Vector;
	unsigned int cantidadDatos;
	int tamañoVector;
};

ListaPosInt crearListaPosInt()
{
	ListaPosInt cabezal = new _cabezalListaPosInt;
	cabezal->Vector = new int[1];
	cabezal->cantidadDatos = 0;
	cabezal->tamañoVector = 1;


	return cabezal;
}

//duplica los lugares del mismo
void duplicarTamVector(ListaPosInt& l) {
	//clono el vector antes lo agrando y elimino el viejo
	int tamaño = l->tamañoVector;
	int tamañoNuevo = (tamaño + tamaño);
	int* vectorClon = new int[tamañoNuevo];
	for (int i = 0; i < tamaño; i++) {
		vectorClon[i] = l->Vector[i];

	}
	delete[] l->Vector;
	l->Vector = vectorClon;
	l->tamañoVector = tamañoNuevo;

}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	if (l->cantidadDatos + 1 == l->tamañoVector) {
		duplicarTamVector(l);// duplicaTamañoDelVector
	}

	if (l->cantidadDatos == 0 || pos >= l->cantidadDatos) {
		int tam = l->cantidadDatos;
		l->Vector[tam] = e;//antes decia e
	}
	else {
		for (int i = l->cantidadDatos - 1; i >= pos; i--) {
			l->Vector[i + 1] = l->Vector[i];
		}
		l->Vector[pos] = e;
	}
	l->cantidadDatos++;
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	if (pos >= l->cantidadDatos)
		return;
	for (int i = pos; i < l->cantidadDatos; i++) {
		if (i < l->cantidadDatos)
			l->Vector[i] = l->Vector[i + 1];

	}

	l->cantidadDatos--;
}

int elemento(ListaPosInt l, unsigned int pos)
{
	return l->Vector[pos];
}

bool esVacia(ListaPosInt l)
{
	return (l->cantidadDatos == 0);
}

unsigned int cantidadElementos(ListaPosInt l)
{
	return l->cantidadDatos;
}

int* copVector(int* a, int tam) {
	int* clon = new int[tam];
	for (int i = 0; i < tam; i++) {
		clon[i] = a[i];
	}
	return clon;
}

ListaPosInt clon(ListaPosInt l)
{
	ListaPosInt retorno = crearListaPosInt();
	retorno->cantidadDatos = l->cantidadDatos;
	retorno->Vector = copVector(l->Vector, l->cantidadDatos);
	retorno->tamañoVector = l->tamañoVector;
	return retorno;

}

void destruir(ListaPosInt& l)
{
	delete[] l->Vector;
}


#endif