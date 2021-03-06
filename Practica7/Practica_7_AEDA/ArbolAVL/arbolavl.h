#ifndef ARBOLAVL
#define ARBOLAVL

#include <iostream>
#include <vector>
#include "NodoAVL/nodoavl.h"

using namespace std;

template <class T>
class ArbolAVL
{
	private:
		NodoAVL<T> *raiz_;
		int* MB_;
		int* MI_;
		float* MP_;

	public:
		ArbolAVL();
		~ArbolAVL();

		void Insertar(T clave);
		void Buscar(T clave);
		void Eliminar(T clave);

		void Estadistica(T* secuencia, int N, int P);

		int get_min(int* &V, int P);
		int get_max(int* &V, int P);
		float get_med(int* &V, int P);

		ostream& write(ostream& os);
		ostream& write_estadistica(ostream& os, int N, int P);
};

template <class T>
ArbolAVL<T>::ArbolAVL():
	raiz_(NULL)
{}

template <class T>
ArbolAVL<T>::~ArbolAVL()
{}

template <class T>
void ArbolAVL<T>::Insertar(T clave)
{
	NodoAVL<T>* nuevo = new NodoAVL<T>(clave);
	bool crece = false;
	raiz_->Insertar_bal(raiz_, nuevo, crece);
}

template <class T>
void ArbolAVL<T>::Buscar(T clave)
{
	raiz_->Buscar(raiz_, clave);
}

template <class T>
void ArbolAVL<T>::Eliminar(T clave)
{
	bool decrece = false;
	raiz_->Eliminar_Rama(raiz_, clave, decrece);
}

template <class T>
int ArbolAVL<T>::get_min(int* &V, int P)
{
	int min = V[0];
	for(int i = 0; i < P; i++)
	{
		if (min > V[i])
			min = V[i];
	}
	return min;
}

template <class T>
int ArbolAVL<T>::get_max(int* &V, int P)
{
	int max = 0;
	for(int i = 0; i < P; i++)
	{
		if (max < V[i])
			max = V[i];
	}
	return max;
}

template <class T>
float ArbolAVL<T>::get_med(int* &V, int P)
{
	int min = 0;
	for(int i = 0; i < P; i++)
	{
		min += V[i];
	}
	return (float)min/P;
}

template <class T>
void ArbolAVL<T>::Estadistica(T* secuencia, int N, int P)
{
	MB_ = new int[P];
	MI_ = new int[P];
	MP_ = new float[6];

	for (int i = 0; i < N; i++)
		Insertar(secuencia[i]);


	for (int i = 0; i < P; i++)
	{
		Buscar(secuencia[rand()%N]);
		MB_[i] = raiz_->get_comparaciones();
	}

	int cnt = 0;
	for (int i = N; i < N+P; i++)
	{
		Buscar(secuencia[N+rand()%(N*2-N)]);
		MI_[cnt] = raiz_->get_comparaciones();
		cnt++;
	}

	MP_[0] = get_min(MB_,P);
	MP_[1] = get_med(MB_,P);
	MP_[2] = get_max(MB_,P);
	MP_[3] = get_min(MI_,P);
	MP_[4] = get_med(MI_,P);
	MP_[5] = get_max(MI_,P);

	for (int i = 0; i < N; i++)
		Eliminar(secuencia[i]);
}

template <class T>
ostream& ArbolAVL<T>::write(ostream& os)
{
	if (raiz_ != NULL){
		raiz_->write(os, raiz_);
	}
	else{
		os << "\33[1m" << "Árbol vacío" << "\33[0m" << endl;
		cout << "Nivel 0: [·]" << endl;
	}
	return os;
}

template <class T>
ostream& ArbolAVL<T>::write_estadistica(ostream& os, int N, int P)
{
	os << "\33[1m" << "\33[4m" << "\t\tN\tP\tMínimo\tMedia\tMáximo" << "\33[0m" << endl;
	cout << endl;
	os << "Busqueda\t" << N << "\t" << P << "\t";
	for (int i = 0; i < 3; i++)
		cout << MP_[i] << "\t";
	os << endl;
	os << "Inserción\t" << N << "\t" << P << "\t";
	for (int i = 3; i < 6; i++)
		os << MP_[i] << "\t";
	os << endl;
	return os;
}

#endif // ARBOLAVL

