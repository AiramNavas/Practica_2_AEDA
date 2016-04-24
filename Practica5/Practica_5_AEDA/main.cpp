#include <iostream>
#include <unistd.h>
#include "DNI/dni.h"
#include "Ordenacion/ordenacion.h"
#include "Algoritmos_Ord/insercion.h"

using namespace std;

template <class T>
void generar_v_aleatorio(T* secuencia, int tam)
{
	srand(time(0));
	// Formula a + rand() % (b-a+1)
	for(int i=0; i < tam; i++){
		T num = (2+rand()%(50-2+1));
		if(i>0){
			for(int j=0; j < i; j++)
				if(num==secuencia[j]){
					num = 2 + rand()%(50-2+1);
					j=-1;
				}
		}
		secuencia[i] = num;
	}
}

int main()
{

//////////////////////////////////////////////////////////		PEDIR POR PANTALLA

	int nPruebas = 5;
	int tam = 5;
	int metodo = 2;
	int algoritmo = 4;

//////////////////////////////////////////////////////////		PRACTICA 5

	Ordenacion<int> ordena(nPruebas);





	int secuencia[tam];

	if (metodo == 1)
	{
		generar_v_aleatorio(secuencia, tam);
		ordena.demostracion(secuencia, tam, algoritmo);
	}

	if (metodo == 2){
		for (int i = 0; i < nPruebas; i++)
		{
			generar_v_aleatorio(secuencia, tam);
			ordena.estadistica(secuencia, tam, i, nPruebas);
			for(int k = 0; k < tam; k++)
				cout << secuencia[k] << "  ";
			cout << "Prueba" << i+1 << endl;
			usleep(1000000);
		}
	}


	if (metodo == 2)
		ordena.write(cout);

	return 0;
}
