#include "sumar.h"

int sumar(int mazo[], int * conteoCartas){
	int suma = 0;
	
	if(mazo[*conteoCartas]==1){
		suma = 11;
	}else if (mazo[*conteoCartas] == 11 || mazo[*conteoCartas] == 12 || mazo[*conteoCartas] == 13){
		suma = 10;
	} else{
		suma = mazo[*conteoCartas];
	}
	return suma;
}
