#include "EjerciciosArboles.h"

/////////////////////////////////////////////              FUNCIONES AUXILIARES


// PRE: recibe un arbol general, y un entero representando un nivel del arbol
// POS: devuelve la suma o resta del valor de los nodos dependiendo si estan en nivel par, o no
int sumaPorNivelesAux(NodoAG* raiz, int nivel) {

	if (raiz) {

		if (nivel % 2 == 0) {

			return raiz->dato + sumaPorNivelesAux(raiz->sh, nivel) + sumaPorNivelesAux(raiz->ph, nivel + 1);
		}
		else {

			return -1 * raiz->dato + sumaPorNivelesAux(raiz->sh, nivel) + sumaPorNivelesAux(raiz->ph, nivel + 1);
		}
	}
	else {

		return 0;
	}
}

// PRE: recibe un arbol general, y un entero representando un nivel del arbol
// POS: devuelve la cantidad de nodos en ese nivel
int cantNodosEnNivel(NodoAG* raiz, int nivel) {

	if (!raiz || nivel < 1) {

		return 0;
	}
	if (nivel == 1) {

		return 1 + cantNodosEnNivel(raiz->sh, nivel);
	}

	return cantNodosEnNivel(raiz->ph, nivel - 1) + cantNodosEnNivel(raiz->sh, nivel);
}

// PRE: Recibe un arbol, el nivel donde estoy parado, y el rango de enteros desde - hasta
//POS: devuelve la suma de nodos que se encuentrar entre los niveles desde - hasta
int contarNodosEntreNiveles(NodoAB* raiz, int nivelActual, int desde, int hasta) {

	if (raiz == nullptr) {
		return 0;
	}

	if (nivelActual >= desde && nivelActual <= hasta) {
		return 1 + contarNodosEntreNiveles(raiz->izq, nivelActual + 1, desde, hasta) + contarNodosEntreNiveles(raiz->der, nivelActual + 1, desde, hasta);
	}
	else {
		return contarNodosEntreNiveles(raiz->izq, nivelActual + 1, desde, hasta) + contarNodosEntreNiveles(raiz->der, nivelActual + 1, desde, hasta);
	}
}

/////////////////////////////////////////////            FIN FUNCIONES AUXILIARES


int altura(NodoAB* raiz){
	
	if (!raiz) {

		return 0;
	}
	else {

		return 1 + max(altura(raiz->izq), altura(raiz->der));
	}
	
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	/*
	if (p == NULL && q == NULL) {

		return true;
	}

	if (p == NULL || q == NULL) {
	
		return false;
	}

	if (p->dato != q->dato) {
	
		return false;
	}

	return sonIguales(p->izq, q->izq) && sonIguales(p->der, q->der);
	*/

	if (p == NULL && q == NULL) {

		return true;
	}
	else if (p && q && p->dato == q->dato) {

		return sonIguales(p->izq, q->izq) && sonIguales(p->der, q->der);
	}
	else {

		return false;
	}
	
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {

	if (raiz == NULL) {

		return sum == 0;
	}
	if (sum - raiz->dato == 0 && !raiz->der && !raiz->izq) {

		return true;
	}
	else {

		if (raiz->der && raiz->izq) {

			return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);
		}

		if (raiz->der) {

			return existeCaminoConSuma(raiz->der, sum - raiz->dato);
		}

		if (raiz->izq) {

			return existeCaminoConSuma(raiz->izq, sum - raiz->dato);
		}

		return false;
	}
	
}

bool esArbolBalanceado(NodoAB *raiz) {
	
	if (raiz == NULL) {

		return true;
	}

	int alturaDer = altura(raiz->der);
	int alturaIzq = altura(raiz->izq);
	int diferencia = alturaDer - alturaIzq;

	if (diferencia > 1 || diferencia < -1) {

		return false;
	}

	return esArbolBalanceado(raiz->der) && esArbolBalanceado(raiz->izq);
}

NodoLista* enNivel(NodoAB *a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	/*
	if (desde > hasta) {
		return 0; // Caso en el que 'desde' es mayor que 'hasta'
	}
	return contarNodosEntreNiveles(a, 1, desde, hasta);
	*/
	return 0;
}

NodoLista* camino(NodoAB *arbol, int x) {
	
	NodoLista* retorno = NULL;
	if (arbol == NULL) {

		return retorno;
	}
	if (arbol->dato > x && arbol->izq) {

		retorno = new NodoLista(arbol->dato);
		retorno->sig = camino(arbol->izq, x);

	}
	else if (arbol->dato < x && arbol->der) {

		retorno = new NodoLista(arbol->dato);
		retorno->sig = camino(arbol->der, x);
	}
	else {
		
		if (arbol->dato == x) {

			retorno = new NodoLista(arbol->dato);
		}
	
	}

	return retorno;
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB * & A) {
	
	if (!A->izq && !A->der) {

		delete A;
		A = NULL;
	}
	else if (!A->izq && A->der) {

		NodoAB* aux = A;
		A = A->der;
		delete aux;
		aux = NULL;
	}
	else if (A->izq && !A->der) {

		NodoAB* aux = A;
		A = A->izq;
		delete aux;
		aux = NULL;
	}
	else if (A->izq && A->der) {

		NodoAB* aux = A->izq;
		A = A->der;
		if (A->izq) {

			NodoAB* iter = A;
			while (iter->izq) {

				iter = iter->izq;
			}
			iter->izq = aux;
		}
		else {

			A->izq = aux;
		}
	
	}

}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	if (a == NULL) {

		return -1;
	}
	if (a->dato > n) {

		int retorno = sucesor(a->izq, n);
		return retorno != -1 ? retorno: a->dato;
	}
	else {

		return sucesor(a->der, n);
	}
}


int nivelMasNodos(NodoAB* raiz, int nivelHasta) {

	return 0;
}

void borrarPares(NodoAB* & a){
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{

	if (!raiz) {

		return 0;
	}
	
	int alutraHijos = alturaAG(raiz->ph) + 1;
	int alutraHermanos = alturaAG(raiz->sh);
	return max(alutraHijos, alutraHermanos);
}

int sumaPorNiveles(NodoAG* raiz){
	
	if (raiz) {

		return sumaPorNivelesAux(raiz, 1);
	}
	else {

		return 0;
	}
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{
	if (a) {

		if (l) {

			if (a->dato == l->dato) {

				return esPrefijo(a->ph, l->sig);
			}
			else {

				return esPrefijo(a->sh, l);
			}
		}
		else {

			return true;
		}
	}
	else {

		return l == NULL;
	}
}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	
	if (!arbolGeneral) {

        return NULL;
    }
    else {

        NodoLista* lista = NULL;
        if (arbolGeneral->dato == dato) {

            lista = new NodoLista(dato);
            return lista;
        }
        else {

            lista = caminoAG(arbolGeneral->ph, dato);
            if (lista) {

                NodoLista* nuevo = new NodoLista(arbolGeneral->dato);
                nuevo->sig = lista;
                lista = nuevo;
            }
            else {

                lista = caminoAG(arbolGeneral->sh, dato);
            }

            return lista;
        }
    }
}


int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	
	int nivelMinimo = 0;
	int maximo = 0;
	int nivelHasta = alturaAG(arbolGeneral);
	for (int i = 1; i <= nivelHasta; i++) {
		
		int cantNodos = cantNodosEnNivel(arbolGeneral, i);
		if (maximo < cantNodos) {

			maximo = cantNodos;
			nivelMinimo = i;
		}
	}
	return nivelMinimo;
}
