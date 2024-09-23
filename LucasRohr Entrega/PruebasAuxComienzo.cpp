#include "PruebasAuxComienzo.h"

bool PruebaSuma(int a, int b, int output, int &nroPrueba) {
	// PRUEBA SUMA A+B
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Problema A+B nro " << nroPrueba++;
	
	std::ostringstream s;
	s << a << ", " << b;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int res = suma(a, b);

	if (res != output) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
		return false;
	}
	cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	return true;
}


bool PruebaImprimirTabla(unsigned int tabladel, unsigned int desde, unsigned int hasta, const char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Imprimir Tabla del numero " << nroPrueba++;

	stringstream ss;
	auto old_buf = cout.rdbuf(ss.rdbuf()); 
    
	std::ostringstream strss;
	strss << tabladel << ", " << desde << ", " << hasta;
	char *inputParametersFormated = FrameworkA1::copioString(strss.str().c_str());

	tablaDel(tabladel, desde, hasta);
    
	cout.rdbuf(old_buf); 
	string s = ss.str();
	unsigned long sCharL = s.length() + 1;
	char *sChar = new char[sCharL];
	strcpy_s(sChar, sCharL, s.c_str());
	if (sChar[sCharL-2] == 10) sChar[sCharL-2] = '\0'; 
	
	bool resultadoOK = strcmp(output, sChar) == 0;
	
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, sChar, inputParametersFormated);
	}
	else
		cout << " -> OK" << endl;
	
	delete [] inputParametersFormated;
	delete [] sChar;
	return resultadoOK;
}



bool PruebaSimplificar(int n, int d, const char *output, int &nroPrueba) {
	// PRUEBA SIMPLIFICAR FRACCION
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Simplificar fraccion " << nroPrueba++;

	std::ostringstream strss;
	strss << n << ", " << d;
	char *inputParametersFormated = FrameworkA1::copioString(strss.str().c_str());

	stringstream ss;
	auto old_buf = cout.rdbuf(ss.rdbuf()); //change the underlying buffer and save the old buffer

    simplificar(n, d);

    cout.rdbuf(old_buf); //reset buffer
	string s = ss.str();
	unsigned long sCharL = s.length() + 1;
	char *sChar = new char[sCharL];
	strcpy_s(sChar, sCharL, s.c_str());
	if (sChar[sCharL-2] == 10) sChar[sCharL-2] = '\0'; // elimino el fin de linea
	bool resultadoOK = strcmp(output, sChar) == 0;

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, sChar, inputParametersFormated);
	}
	else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	delete [] sChar;
	return resultadoOK;
}

bool PruebaOcuerrencias123Repetidos(const char* vector, int output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Ocurrencias 123 Repetidos " << nroPrueba++;

	std::ostringstream s;
	s << vector;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	int* vectorParseado = (int*)FrameworkA1::parsearColeccion(vector, largo);
	int* vectorParseadoCopia = (int*)FrameworkA1::parsearColeccion(vector, largo);
	int res = ocurrencias123Repetidos(vectorParseado, largo);

	bool resultadoOK = res == output;
	bool modificoParametros = !FrameworkA1::sonIguales(vectorParseado, vectorParseadoCopia, largo);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
	} else if(modificoParametros){
		cout << " -> ERROR modifico parametros" << endl;
		resultadoOK = false;
	}
	else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	FrameworkA1::destruir(vectorParseado);
	FrameworkA1::destruir(vectorParseadoCopia);
	return resultadoOK;
}

bool PruebaMaximoNumero(unsigned int n, const char* vector, int output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Maximo Numero " << nroPrueba++;

	std::ostringstream s;
	s << n << ", " << vector;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	streambuf *old_buf;
	istringstream oss(vector);
	old_buf = cin.rdbuf();
	cin.rdbuf(oss.rdbuf());

	//int* vectorParseado = (int*)parsear(vector);
	int res = maximoNumero(n);

	cin.rdbuf(old_buf); //reset buffer

	bool resultadoOK = res == output;

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
	}
	else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	return resultadoOK;
}

bool PruebaOrdenarVecInt(const char* vecStr, const char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba ordenar vector de int " << nroPrueba++;

	std::ostringstream s;
	s << vecStr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largoResultado;
	int *listaPalabras = (int *)FrameworkA1::parsearColeccion(vecStr, largoResultado);
	int largoSolucion;
	int *solucion = (int *)FrameworkA1::parsearColeccion(output, largoSolucion);

	ordenarVecInt(listaPalabras, largoResultado);

	bool resultadoOK = FrameworkA1::sonIguales(listaPalabras, solucion, largoSolucion);
	
	char* resultadoImprimir = FrameworkA1::serializar(listaPalabras, largoResultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(listaPalabras);
	FrameworkA1::destruir(solucion);
	delete[]resultadoImprimir;
	return resultadoOK;
}



bool PruebaInvertirCase(const char *substr, const char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Invertir Case de palabra " << nroPrueba++;

	std::ostringstream s;
	s << substr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	char *substringCopia = FrameworkA1::copioString(substr);

	char* res = invertirCase(substringCopia);

	bool resultadoOK = FrameworkA1::sonIguales(res, output);
	bool parametrosModificados = !FrameworkA1::sonIguales(substr, substringCopia);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
	}
	else if(parametrosModificados) {
		cout << " -> ERROR parametro modificado" << endl;
	} else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	delete[] substringCopia;
	delete[] res;
	return resultadoOK;
}

bool PruebaIslas(const char* datosMapa, int col, int fil, int output, int &nroPrueba) {
	// PRUEBA ISLAS
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Islas " << nroPrueba++;
	int contador = 0;
	int largo;

	std::ostringstream s;
	s << datosMapa << ", " << col << ", " << fil;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	
	char** cDatosMapa = (char**)FrameworkA1::parsearColeccion(datosMapa, largo);
	char** mapa = new char*[col];
	char** copiaMapa = new char*[col];
	for(int c=0; c<col; c++){
		mapa[c] = new char[fil];
		copiaMapa[c] = new char[fil];
	}
	for(int f=0; f<fil;f++){
		for(int c=0; c<col; c++){
			mapa[c][f] = cDatosMapa[contador][0];
			copiaMapa[c][f] = cDatosMapa[contador][0];
			contador++;
		}
	}
	int resultado = islas(mapa, col, fil);
	bool parametrosModificados = !FrameworkA1::sonIguales(mapa, copiaMapa, col, fil);
	bool resultadoOK = resultado == output;
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}
	else if(parametrosModificados) {
		cout << " -> ERROR parametro modificado" << endl;
		resultadoOK = false;
	} else 
		cout << " -> OK" << endl;
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(cDatosMapa, largo);
	FrameworkA1::destruir(mapa, fil);
	return resultadoOK;
}

bool PruebaOcurrenciasSubstring(const char *stringVecStr, const char *substr, int output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Ocurrencias Substring " << nroPrueba++;

	std::ostringstream s;
	s << stringVecStr << ", " << substr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largoVecStr;
	char** vecStr = (char**)FrameworkA1::parsearColeccion(stringVecStr, largoVecStr);

	char *substringCopia = FrameworkA1::copioString(substr);
	char** vecStrCopia = (char**)FrameworkA1::parsearColeccion(stringVecStr, largoVecStr);

	char *substringCopiaPasado = FrameworkA1::copioString(substr);
	int res = ocurrenciasSubstring(vecStr, largoVecStr, substringCopiaPasado);

	bool resultadoOK = res == output;

	bool modificoParametros = !((FrameworkA1::sonIguales(vecStr, vecStrCopia, largoVecStr)) || (strcmp(substringCopiaPasado, substringCopia) != 0));
	
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
	} else if(modificoParametros) {
		cout << " -> ERROR modifico parametros" << endl;
		resultadoOK = false;
	} else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	FrameworkA1::destruir(vecStr, largoVecStr);
	FrameworkA1::destruir(vecStrCopia, largoVecStr);
	delete [] substringCopia;
	delete [] substringCopiaPasado;
	return resultadoOK;
}

bool PruebaOrdenarVecStr(const char* vecStr, const char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba ordenar vector de strings " << nroPrueba++;

	std::ostringstream s;
	s << vecStr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largoResultado;
	char** listaPalabras = (char**)FrameworkA1::parsearColeccion(vecStr, largoResultado);
	char** listaPalabrasCopia = (char**)FrameworkA1::parsearColeccion(vecStr, largoResultado);
	int largoSolucion;
	char** solucion = (char**)FrameworkA1::parsearColeccion(output, largoSolucion);

	char** resultado = ordenarVecStrings(listaPalabras, largoResultado);

	bool parametrosModificados = !FrameworkA1::sonIguales(listaPalabras, listaPalabrasCopia, largoResultado);
	bool compartenMem = FrameworkA1::compartenMemoria(resultado, largoResultado, listaPalabras, largoResultado);
	bool resultadoOK = FrameworkA1::sonIguales(resultado, solucion, largoSolucion);
	
	char* resultadoImprimir = FrameworkA1::serializar(resultado, largoResultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(compartenMem) {
		cout << " -> ERROR vector devuelto comparte memoria con parametro" << endl;
		resultadoOK = false;
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(listaPalabras,largoResultado);
	FrameworkA1::destruir(listaPalabrasCopia,largoResultado);
	if(!compartenMem) FrameworkA1::destruir(resultado,largoResultado);
	FrameworkA1::destruir(solucion,largoResultado);
	delete[]resultadoImprimir;
	return resultadoOK;
}


bool PruebaIntercalarVector(const char* vector1, const char* vector2, const char* vectorOutput, int &nroPrueba)
{
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Intercalar Vectores " << nroPrueba++;
	
	std::ostringstream s;
	s << vector1 << ", " << vector2;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largoV1 = 0;
	int* vector1Parseado = (int*)FrameworkA1::parsearColeccion(vector1, largoV1);
	int* vector1ParseadoCopia = (int*)FrameworkA1::parsearColeccion(vector1, largoV1);

	int largoV2 = 0;
	int* vector2Parseado = (int*)FrameworkA1::parsearColeccion(vector2, largoV2);
	int* vector2ParseadoCopia = (int*)FrameworkA1::parsearColeccion(vector2, largoV2);

	int largoResultadoEsperado = 0;
	int* vectorResultadoEsperado = (int*)FrameworkA1::parsearColeccion(vectorOutput, largoResultadoEsperado);

	int largoRes = largoV1 + largoV2; // asumo que resultado tiene ese largo

	assert(largoRes == largoResultadoEsperado); // por si las pruebas estan mal armadas
	
	int* resultado = intercalarVector(vector1Parseado, vector2Parseado, largoV1, largoV2);
	bool parametrosModificados = false;

	parametrosModificados = !FrameworkA1::sonIguales(vector1Parseado, vector1ParseadoCopia, largoV1);
	parametrosModificados = parametrosModificados || !FrameworkA1::sonIguales(vector2Parseado, vector2ParseadoCopia, largoV2);

	bool compartenMem = FrameworkA1::compartenMemoria(resultado, vector1Parseado, largoRes, largoV1) || FrameworkA1::compartenMemoria(resultado, vector2Parseado, largoRes, largoV2);

	bool resultadoOK = FrameworkA1::sonIguales(resultado, vectorResultadoEsperado, largoResultadoEsperado);
	
	char* resultadoImprimir = FrameworkA1::serializar(resultado, largoRes);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		if (largoV1 + largoV2 == 0 && resultado != NULL)
			cout << " -> ERROR no retorna NULL cuando el vector esta vacio" << endl;
		else
			FrameworkA1::imprimirEsperadoVsRecibido(vectorOutput, resultadoImprimir, inputParametersFormated);
	}
	else if (compartenMem) {
		cout << " -> ERROR vector devuelto comparte memoria con parametro" << endl;
		resultadoOK = false;
	}
	else if (parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	}
	else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(vector1Parseado);
	FrameworkA1::destruir(vector1ParseadoCopia);
	FrameworkA1::destruir(vector2Parseado);
	FrameworkA1::destruir(vector2ParseadoCopia);
	FrameworkA1::destruir(vectorResultadoEsperado);
	if (!compartenMem) FrameworkA1::destruir(resultado);
	delete[] resultadoImprimir;
	return resultadoOK;
}

bool PruebaSubconjuntoVector(const char* vector1, const char* vector2, bool output, int &nroPrueba)
{
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Subconjunto Vector " << nroPrueba++;

	std::ostringstream s;
	s << vector1 << ", " << vector2;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largoV1 = 0;
	int* vector1Parseado = (int*)FrameworkA1::parsearColeccion(vector1, largoV1);


	int largoV2 = 0;
	int* vector2Parseado = (int*)FrameworkA1::parsearColeccion(vector2, largoV2);	

	bool resultado = subconjuntoVector(vector1Parseado, vector2Parseado, largoV1, largoV2);

	bool resultadoOK = (resultado == output);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}
	else {
		cout << " -> OK" << endl;
	}

	delete[] inputParametersFormated;
	delete[] vector1Parseado;
	delete[] vector2Parseado;
	return resultadoOK;
}

bool PruebaSplitStr(const char* entrada, char separador, const char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba split de strings " << nroPrueba++;

	std::ostringstream s;
	s << "String:" << entrada << " Separador:" << separador;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	char *entradaCopia = FrameworkA1::copioString(entrada);
	char *entradaCopiaPasado = FrameworkA1::copioString(entrada);

	int largoEsperado;
	char** esperado = (char**)FrameworkA1::parsearColeccion(output, largoEsperado);

	int largoObtenido;
	char** obtenido = splitStr(entradaCopiaPasado, separador, largoObtenido);

	bool parametrosModificados = !FrameworkA1::sonIguales(entradaCopiaPasado, entradaCopia);

	bool resultadoOK = largoEsperado == largoObtenido && FrameworkA1::sonIguales(obtenido, esperado, largoEsperado);
	
	char* resultadoImprimir = FrameworkA1::serializar(obtenido, largoObtenido);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		if (largoObtenido == 0 && obtenido != NULL)
			cout << " -> ERROR no retorna NULL cuando el vector esta vacio" << endl;
		else
			FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}

	delete[] inputParametersFormated;
	delete[] obtenido;
	delete[] entradaCopia;
	delete[] entradaCopiaPasado;
	delete[] resultadoImprimir;
	return resultadoOK;
}

bool PruebaOrdenarVecIntMergeSort(const char* vecStr, const char* output, int &nroPrueba) {
	cout << "----------------------------------------------" << endl;
	cout << "Prueba ordenar vector de int Mergesort " << nroPrueba++;

	std::ostringstream s;
	s << vecStr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largoResultado;
	int *listaPalabras = (int *)FrameworkA1::parsearColeccion(vecStr, largoResultado);
	int largoSolucion;
	int *solucion = (int *)FrameworkA1::parsearColeccion(output, largoSolucion);

	ordenarVecIntMergeSort(listaPalabras,largoResultado);

	bool resultadoOK = FrameworkA1::sonIguales(listaPalabras, solucion, largoSolucion);

	char* resultadoImprimir = FrameworkA1::serializar(listaPalabras, largoResultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	}
	else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(listaPalabras);
	FrameworkA1::destruir(solucion);
	delete[]resultadoImprimir;
	return resultadoOK;
}

