#include "PruebasComienzo.h"


void PruebasComienzo() {
	int nroPrueba = 1;
	int correctos = 0, error = 0;
	int correctosTotal = 0, errorTotal = 0, ejCorrectosTotal = 0, ejErrorTotal = 0;

	FrameworkA1::ver(PruebaSuma(2, 7, 9, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSuma(-8, 6, -2, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaSuma", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaImprimirTabla(7, 0, 6, "0*7=0;1*7=7;2*7=14;3*7=21;4*7=28;5*7=35;6*7=42", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(11, 1, 5, "1*11=11;2*11=22;3*11=33;4*11=44;5*11=55", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(0, 0, 0, "0*0=0", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(12, 10, 15, "10*12=120;11*12=132;12*12=144;13*12=156;14*12=168;15*12=180", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(5, 9, 9, "9*5=45", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(10, 0, 1, "0*10=0;1*10=10", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaImprimirTabla", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaSimplificar(2, 7, "2/7", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(30, 6, "5/1", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(6, 30, "1/5", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(1024, 32, "32/1", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(1, 1, "1/1", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(-1, 1, "-1/1", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(1, -1, "-1/1", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(-1024, 32, "-32/1", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(1024, -32, "-32/1", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(-1024, -32, "32/1", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaSimplificar", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,3]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[3]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,3,1]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,2,3]", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,2,2,2,3]", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,1,2,3]", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,1,2,1,3]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,2,3,1,2,3,1,2,3,2,3]", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,2,1,2,1,2,1,3,2,3,1,2,3,1,2,2,3,2,3,1,2,3,1,1,2]", 3, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaOcuerrencias123Repetidos", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaMaximoNumero(3, "2 4 8", 8, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(2, "1 1", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(6, "2 2 8 5 6 7", 8, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(1, "2", 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(10, "2 11 20 90 465 45 34 767 32 1", 767, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(4, "-17 89 12 11", 89, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(3, "-28923 -2229 -1122", -1122, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaMaximoNumero", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaOrdenarVecInt("[]", "[]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[5]", "[5]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[1,2,3,4,5]", "[1,2,3,4,5]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[9,5,1]", "[1,5,9]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[1,6,4,9,2,4,9,1]", "[1,1,2,4,4,6,9,9]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[9,9,5,5,5,1,1]", "[1,1,5,5,5,9,9]", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaOrdenarVecInt", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaInvertirCase("","", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("hola","HOLA", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("Write in C","wRITE IN c", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("es UNA cosa DE locos","ES una COSA de LOCOS", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("EsCrIbIR asi Es MoLeSTOOO","eScRiBir ASI eS mOlEstooo", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("1434","1434", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("#&/()|A","#&/()|a", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaInvertirCase", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);


	FrameworkA1::ver(PruebaIslas(
		"['T','A','T','A','T','A']", 6, 1, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['T','A','T','A','T','A',"\
		 "'T','T','T','T','T','T']", 6, 2, 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['T','A','T','A','T','T','T','A','T','A',"\
		 "'A','T','T','A','A','T','T','T','T','A']", 10, 2, 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['T','A','T','A','T','A',"\
		 "'A','T','A','T','A','T',"\
		 "'T','A','A','T','A','T',"\
		 "'T','T','T','A','T','T']", 6, 4, 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['A','A','A','A','A','A','A','A','A','A',"\
		 "'A','T','T','A','T','T','A','T','T','A',"\
		 "'A','T','T','A','T','T','A','T','T','A',"\
		 "'A','A','A','A','A','A','A','A','A','A']", 10, 4, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['A','T','T','T','T','T','A','T','T','T',"\
		 "'A','T','A','A','A','T','A','T','A','T',"\
		 "'A','T','A','A','T','T','A','T','A','T',"\
		 "'A','T','T','T','T','A','A','A','T','A']", 10, 4, 2, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaIslas", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaOcurrenciasSubstring("['hola']", "hola", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcurrenciasSubstring("['abc','ab','ab']", "ab", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcurrenciasSubstring("['holaho','holahol','holahola','holaholahola','holaholaholaho']", "holahola", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcurrenciasSubstring("['abcjsdf','sagsdfg','afgadfg','afgadfg12','wertewrt','tyafgadfgsegfdxv','jo']", "afgadfg", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcurrenciasSubstring("['solsol']", "sol", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcurrenciasSubstring("['ababac','aabaca','abaabaca']", "abac", 3, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaOcurrenciasSubstring", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaOrdenarVecStr("['paso','pasa','pasado','pasaron']" , "['pasa','pasado','pasaron','paso']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['hola']", "['hola']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['string','strings','substring','strong','strength']", "['strength', 'string', 'strings', 'strong','substring']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['1234','15324567','1563248','5132135']", "['1234', '15324567', '1563248', '5132135']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['153243','1532468','153246','15324679']", "['153243', '153246', '15324679', '1532468']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['algoritmos','algoritmia','algoritmo','algo']", "['algo', 'algoritmia', 'algoritmo', 'algoritmos']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['123456','123546','123645','123598','123754','12365498','1232','12','123','12911']", "['12','123', '1232', '123456', '123546','123598', '123645', '12365498', '123754', '12911']", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaOrdenarVecStr", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaIntercalarVector("[1,2,3]", "[1,2,3]", "[1,1,2,2,3,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[1,3,5]", "[2,4]", "[1,2,3,4,5]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[1,100]", "[2,53]", "[1,2,53,100]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[]", "[]", "[]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[2]", "[4]", "[2,4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[1,2,3,4,5]", "[6,7,8]", "[1,2,3,4,5,6,7,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[6,7,8]", "[1,2,3,4,5]", "[1,2,3,4,5,6,7,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[]", "[1,2,3]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[1,2,3]", "[]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaIntercalarVector", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaSubconjuntoVector("[100,400,200,300,300,400,400]", "[100,400,200]", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[1,2,3]", "[1,2,3,4,5,6]", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[2,2,2,3,54,6,7]", "[1,2,3,4]", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[2,2,2,3,54,6,7]", "[7,6,54,6,3,2]", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[1,1,1,4,2]", "[1,2,5]", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[]", "[]", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[]", "[2,3,1]", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[2,3,4]", "[]", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[1]", "[1]", true, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaSubconjuntoVector", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaSplitStr("", '@', "[]", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr(" ", '@', "[' ']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@", '@', "[]", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@@ @@ @@ @@ @@", '@', "[' ', ' ', ' ', ' ']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("A@B", '@', "['A','B']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("A@B@C", '@', "['A','B', 'C']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("A@", '@', "['A']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@B", '@', "['B']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@@@", '@', "[]", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@@@A", '@', "['A']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("A@@@B", '@', "['A','B']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("The-Lannisters-send-their-regards", '-', "['The','Lannisters','send','their','regards']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("Hola@Mundo", '-', "['Hola@Mundo']", nroPrueba),  correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaSplitStr", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[]", "[]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[4]", "[4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,1,1]", "[1,1,1]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,2,3]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,4,2]", "[1,2,4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[2,3,1]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[-2,-3,-1]", "[-3,-2,-1]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,1,4,1,3,8]", "[1,1,1,3,4,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[-2,3,1]", "[-2,1,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[3,5,2,1,0]", "[0,1,2,3,5]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[9,2,2,5,1]", "[1,2,2,5,9]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[3,1,-1,1,0]", "[-1,0,1,1,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[10,9,8,7,6,5,4,3,2,1,0,-1,-2]", "[-2,-1,0,1,2,3,4,5,6,7,8,9,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[7,3,7,10,-1,1,-6,0,-10,2,1,2]", "[-10,-6,-1,0,1,1,2,2,3,7,7,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[10,9,8,7,6,5,4,3,2,1,0,-1,-2]", "[-2,-1,0,1,2,3,4,5,6,7,8,9,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[8,7,5,2,-3,-1]", "[-3,-1,2,5,7,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,2,0,10,3,4]", "[0,1,2,3,4,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,2,4,3]", "[1,2,3,4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[-2,0,3,1,1]", "[-2,0,1,1,3]", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaOrdenarVecIntMergeSort", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);


	cout << "----------------------------------------------"<<endl;
	cout << "----------------------------------------------"<<endl;
	cout << "PRUEBAS FUNCIONES " << endl;
	cout << "PRUEBAS FUNCIONES " << setw(48) << std::right << "RESULTADO VARIOS =>" << " CORRECTAS: " << setw(2) << std::right << ejCorrectosTotal << " INCORRECTAS: " << setw(2) << std::right << ejErrorTotal << endl;
	cout << "PRUEBAS FUNCIONES " << endl;
}
