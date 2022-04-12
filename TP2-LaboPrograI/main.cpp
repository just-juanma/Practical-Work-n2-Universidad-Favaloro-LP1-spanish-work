#include "gbl.h"
#include "cVuelo.h"
int main() {
	cVuelo* vuelo1 = new cVuelo(false);
	vuelo1->setDestinosPosibles();
	vuelo1->setDestino("Tel Aviv");
	delete vuelo1;
	return 0;
}