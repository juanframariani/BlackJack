#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include "sumar.h"


using namespace std;

void cartas(int mazo[], int conteoCartas){

	if (mazo[conteoCartas] == 1){
		cout << "AS" << endl;
	} else if (mazo[conteoCartas] == 11){
		cout << "J" << endl;
	} else if (mazo[conteoCartas] == 12){
		cout << "Q" << endl;
	} else if (mazo[conteoCartas] == 13){
		cout << "K" << endl;
	} else{
		cout << mazo[conteoCartas] << endl;
	}
}

