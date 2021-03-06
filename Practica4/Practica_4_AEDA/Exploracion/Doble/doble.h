#ifndef DOBLE_H
#define DOBLE_H

#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;

class Doble: public Exploracion
{
	public:
		Doble();
		~Doble();

		unsigned int funcion() const;

		unsigned int exploracion(const DNI& dni, int nCeldas, int i) const;
};

#endif // DOBLE_H
