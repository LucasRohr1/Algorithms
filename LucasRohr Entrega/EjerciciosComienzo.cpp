#include "EjerciciosComienzo.h"


/////////////////////////////////////////////              FUNCIONES AUXILIARES

//PRE: recibe una vector de chars
//POS: retorna su copia sin compartir memoria
	char* copia(char* str) {

		int largo = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			largo++;
		}
		char* nuevo = new char[largo+1];
		for (int i = 0; str[i] != '\0'; i++) {

			nuevo[i] = str[i];
		}
		nuevo[largo] = '\0';
		return nuevo;
	}



	//////////////////////////////////////////            FIN FUNCIONES AUXILIARES



int suma(int a, int b) {
	
	return a + b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
 	// IMPLEMENTAR SOLUCION
}

void simplificar(int n, int d) {
	// IMPLEMENTAR SOLUCION
}

int ocurrencias123Repetidos(int* vector, int largo) {
	
	int ocurrencias = 0;
	bool unoYdos = false;
	for (int i = 0; i < largo; i++) {
		if (vector[i] == 1 && vector[i+1] == 2) {
			unoYdos = true;
			for (int j = i + 2; j < largo && unoYdos; j++) {
				if (vector[j] == 3) {
					ocurrencias++;
					unoYdos = false;
					i = j;
				}
				else if (vector[j] == 1) {
					unoYdos = false;
					i = j;
				}

			}
		}
		
	}
	return ocurrencias;
}

int maximoNumero(unsigned int n) {
	// IMPLEMENTAR SOLUCION
	if (n == 0)
		return 0;

	int mayor;
	cin >> mayor;

	int numero;
	for (int i = 1; i < n; i++) {

		//cout << "Ingrese un numero";
		cin >> numero;

		if (numero > mayor) {
			mayor = numero;
		}
	}

	return mayor;
}

void ordenarVecInt(int *vec, int largoVec) {
	
	for (int i = 0; i < largoVec; i++) {

		for (int j = i + 1; j <= largoVec-1; j++) {

			if (vec[i] > vec[j]) {

				int aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}




char* invertirCase(char* str)
{

	char* retorno = copia(str);
	for (int i = 0; retorno[i] != '\0'; i++) {

		if (str[i] > 64 && str[i] < 91) {  // es mayuscula

			retorno[i] = retorno[i] + 32;

		}
		else if (str[i] > 96 && str[i] < 123) { // es minuscula

			retorno[i] = retorno[i] - 32;

		}
	}
	
	return retorno;
}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION

    return NULL;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	
	int sumaLargo = l1 + l2;
	int minLargo = (l1 >= l2) ? minLargo = l2 : minLargo = l1;

	int* resultado = new int[sumaLargo];

	for (int i = 0; i < sumaLargo; i++) {

		resultado[i] = NULL;
	}

	if (sumaLargo == 0) {

		return NULL;
	}
	int i = 0;
	int j = 0;
	int pos = 0;

	while (i < l1 && j < l2) {

		if (v1[i] <= v2[j]) {

			resultado[pos] = v1[i];
			i++;
			pos++;
		}
		else {

			resultado[pos] = v2[j];
			j++;
			pos++;
		}
	}
	while (i < l1) {
		
		resultado[pos] = v1[i];
		i++;
		pos++;
	}
	while (j < l2){
		
		resultado[pos] = v2[j];
		j++;
		pos++;
	}
	
	return resultado;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	if (l1 == 0) {

		return true;
	}

	for (int i = 0; i < l1; i++) {

		bool encontrado = false;
		for (int j = 0; j < l2; j++) {

			if (v1[i] == v2[j]) {

				encontrado = true;
				break;
			}
		}
		if (!encontrado) {

			return false;
		}
	}

	return true;

}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}
