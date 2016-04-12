#ifndef CUADRATICA_H
#define CUADRATICA_H

#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;

class Cuadratica: public Exploracion
{
	public:
		Cuadratica();
		~Cuadratica();

		unsigned int exploracion(int i) const;
};

#endif // CUADRATICA_H
