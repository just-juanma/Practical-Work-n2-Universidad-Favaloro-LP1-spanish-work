#include "gbl.h"
#include "cVuelo.h"
int main() {
	cVuelo* vuelo1 = new cVuelo(false, 1, estima);
	vuelo1->setDestinosPosibles();
	delete vuelo1;
	return 0;
}