#include "EjerciciosListas.h"

/////////////////////////////////////////////              FUNCIONES AUXILIARES

//PRE: recibe una lista l, puntero fin, e int n
//POS: agrega un nuevo nodo a la lista con el elemento n
void insertarAlFinal(NodoLista*& l, NodoLista*& fin, int n) {

	NodoLista* nuevo = new NodoLista(n);
	if (l == NULL) {

		l = nuevo;
		fin = l;
		
	}
	else {

		fin->sig = nuevo; 
		fin = fin->sig;
	}
}

//PRE: recibe una lista l y entero n
//POS: inserta un nuevo nodo que contiene el int n al princio de la lista 
void insertarComienzo(NodoLista*& l, int n) {

	NodoLista* nuevoNodo = new NodoLista(n);
	nuevoNodo->sig = l;
	l = nuevoNodo;


}

//PRE: recibe una lista
//POS: retorna su largo
int largoLista(NodoLista* l) {

	int largo = 0;
	if (l == NULL) {

		largo = 0;
	}
	else {

		largo = largo + 1;
		largoLista(l->sig);
	}
	return largo;
}

//PRE: recibe una lista y un int n
//POS: modifica la lista agregando un nuevo nodo al final cuyo valor nodo->dato = n
void insertarAlFinal2(NodoLista*& l, int n) {

	NodoLista* nuevo = new NodoLista(n);
	if (l == NULL) {

		l = nuevo;
	}
	else {

		NodoLista* actual = l;
		while (actual->sig != NULL) {

			actual = actual->sig;
		}
		actual->sig = nuevo;
	}
}

//PRE: recibe una lista
//POS: retorna una copia de la misma sin compartir memoria
NodoLista* copiar(NodoLista* l) {
	
	if (l == NULL) {
		return NULL;
	}
	NodoLista* nuevo = new NodoLista(l->dato);
	nuevo->sig = copiar(l->sig);
	
	return nuevo;
}


///////////////////////////////////////////               FIN FUNCIONES AUXILIARES





NodoLista* invertirParcial(NodoLista* l) 
{
	
	NodoLista* listaInvertida = NULL;
	if (l->sig == NULL) {

		return listaInvertida;
	}
	else {

		while (l->sig != NULL) {

			insertarComienzo(listaInvertida, l->dato);
			l = l->sig;
		}
	}
	return listaInvertida;
	
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int& n) 
{
	if (lista != NULL) {

		eliminarNesimoDesdeElFinal(lista->sig, n);
		if (n == 1) {

			NodoLista* aux = lista;
			lista = lista->sig;
			delete aux;
		}
		n--;
	}
	
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	NodoLista* resultado = NULL;

	if (l == NULL) {
		return resultado;
	}
	else {

		while (l != NULL) {

			NodoLista* nuevo = new NodoLista;
			if (resultado == NULL || l->dato <= resultado->dato) {

				nuevo->dato = l->dato;
				nuevo->sig = resultado;
				resultado = nuevo;
			}
			else {

				NodoLista* aux = resultado;
				while (aux->sig != NULL && aux->sig->dato < l->dato) {

					aux = aux->sig;
				}

				nuevo->dato = l->dato;
				nuevo->sig = aux->sig;
				aux->sig = nuevo;
			}

			l = l->sig;
		}
	}
	

	return resultado;
}
	


void listaOrdenadaSelectionSort(NodoLista*& l)
{
	NodoLista* actual = l;

    while (actual != NULL) {

        int minimo = actual->dato;
		NodoLista* nodoAcomparar = actual->sig;
		NodoLista* nodoMinimo = actual;

        while (nodoAcomparar != NULL) {

            if (nodoAcomparar->dato < minimo) {
                minimo = nodoAcomparar->dato;
				nodoMinimo = nodoAcomparar;
            }

			nodoAcomparar = nodoAcomparar->sig;
        }

		if (nodoMinimo != actual) {

			int aux = actual->dato;
			actual->dato = nodoMinimo->dato;
			nodoMinimo->dato = aux;
		}

		actual = actual->sig;

    }
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	
	NodoLista* nuevo = NULL;
	NodoLista* fin = NULL;
	if (!l1 && !l2) {
		
		return nuevo;
	}
	NodoLista* aux1 = l1;
	NodoLista* aux2 = l2;
	while (aux1 && aux2) {
		if (aux1->dato > aux2->dato) {

			insertarAlFinal(nuevo, fin, aux2->dato);
			aux2 = aux2->sig;
		}
		else {

			insertarAlFinal(nuevo, fin, aux1->dato);
			aux1 = aux1->sig;
		}
		
	}
	while (aux1) {

		insertarAlFinal(nuevo, fin, aux1->dato);
		aux1 = aux1->sig;
	}
	while (aux2) {

		insertarAlFinal(nuevo, fin, aux2->dato);
		aux2 = aux2->sig;
	}
	
	return nuevo;
	
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	NodoLista* resultado = NULL;
	
	if (l1 == NULL && l2 == NULL) {

		return resultado;
	}
	if (l1 == NULL) {

		resultado = copiar(l2);		
	}
	else if (l2 == NULL) {

		resultado = copiar(l1);
	}
	else {

		if (l1->dato <= l2->dato) {

			resultado = new NodoLista(l1->dato);
			resultado->sig = intercalarRec(l1->sig, l2);
		}
		else{

			resultado = new NodoLista(l2->dato);
			resultado->sig = intercalarRec(l1, l2->sig);
		}
	}

	return resultado;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	
	NodoLista* resultado = NULL;
	NodoLista* fin = NULL;
	if (l == NULL) {

		insertarComienzo(resultado, x);
		insertarAlFinal2(resultado, x); // si l = null, agregando 1 elemento, el mismo se convierte en el principio y el final, pero agrego esta linea para que prueba 4 = OK
	}
	else {

		while (l != NULL) {
	
			insertarComienzo(resultado, l->dato);
			l = l->sig;
		}
		
		
		insertarComienzo(resultado, x);
		insertarAlFinal2(resultado, x);
	}


	return resultado;
	
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	NodoLista* nuevo = NULL;
	NodoLista* fin = NULL;
	if (!l1 && !l2) {

		return nuevo;
	}
	NodoLista* aux1 = l1;
	NodoLista* aux2 = l2;
	int numeroRepetido = -99999;
	int ultimoNumeroAgregado = -999999;
	while (aux1 && aux2) {
		if (aux1->dato < aux2->dato && aux1->dato != numeroRepetido && aux1->dato != ultimoNumeroAgregado) {

			insertarAlFinal(nuevo, fin, aux1->dato);
			ultimoNumeroAgregado = aux1->dato;
			aux1 = aux1->sig;
		}
		else if(aux2->dato < aux1->dato && aux2->dato != numeroRepetido && aux2->dato != ultimoNumeroAgregado){

			insertarAlFinal(nuevo, fin, aux2->dato);
			ultimoNumeroAgregado = aux2->dato;
			aux2 = aux2->sig;
		}
		else if(aux1->dato == aux2->dato) { // numero repetido por primera vez

			numeroRepetido = aux1->dato;
			aux1 = aux1->sig;
			aux2 = aux2->sig;

		}
		else if (aux1->dato == numeroRepetido) { // si cae en estos if(), es pq ya se evaluaron numero que eran iguales al mismo tiempo, pero esta vez aparecio ese numero en 1 sola lista posteriormente 
												//  Se guarda numeroRepetido para llevar registro de que numero ya esta en ambas listas
			aux1 = aux1->sig;
		}
		else if (aux2->dato == numeroRepetido) {

			aux2 = aux2->sig;
		}
		else if (aux1->dato == ultimoNumeroAgregado) { // agrego estos 2 ultimos else() pq no estaba iterando cuando tengo 2 numeros iguales consecutivos en la misma lista
			
			aux1 = aux1->sig;
		}
		else if (aux2->dato == ultimoNumeroAgregado) {

			aux2 = aux2->sig;
		}

	}


	while (aux1 && aux1->dato != ultimoNumeroAgregado && aux1->dato != numeroRepetido) {

		insertarAlFinal(nuevo, fin, aux1->dato);
		ultimoNumeroAgregado = aux1->dato;
		aux1 = aux1->sig;
	}
	while (aux2 && aux2->dato != ultimoNumeroAgregado && aux2->dato != numeroRepetido) {

		insertarAlFinal(nuevo, fin, aux2->dato);
		ultimoNumeroAgregado = aux2->dato;
		aux2 = aux2->sig;
	}
	

	return nuevo;
	  
}

	
void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	/*
	NodoLista* actual = NULL;
	actual = l;

	while (actual != nullptr && actual->sig != nullptr) {
		if (actual->dato == actual->sig->dato) {
			NodoLista* aux = actual;
			actual = actual->sig;
			delete aux;
		}
		else {
			actual = actual->sig;
		}
	}
	*/
}

bool palindromo(NodoLista* l)
{
	bool cumple = true;
	NodoLista* iter = l;
	NodoLista* listaInvertida = NULL;
	while (iter != NULL) {

		insertarComienzo(listaInvertida, iter->dato);
		iter = iter->sig;
	}

	NodoLista* aux1 = l;
	NodoLista* aux2 = listaInvertida;
	while (aux1 != NULL && aux2 != NULL && aux1->dato == aux2->dato) {

		aux1 = aux1->sig;
		aux2 = aux2->sig;
	}
	if (aux1 != NULL && aux2 != NULL && aux1->dato != aux2->dato) {
		
		cumple = false;
	}

	return cumple;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	if (l && secuencia) {

		if (l->dato == secuencia->dato) {

			NodoLista* auxL = l;
			NodoLista* auxS = secuencia;

			while (auxL && auxS && auxL->dato == auxS->dato) {

				auxL = auxL->sig;
				auxS = auxS->sig;
			}
			if (auxS == NULL) {

				NodoLista* borro = l;
				l = auxL; 
				delete borro; 
			}
			else {

				eliminarSecuencia(l->sig, secuencia);
			}
		}
		else {

			eliminarSecuencia(l->sig, secuencia);
		}
	}

}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{


}
