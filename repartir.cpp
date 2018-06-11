#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include "cartas.h"
#include "sumar.h"
#include "repartir.h"


using namespace std;

void repartir (int mazo[], int cantJugadores, int * indiceCartas, int * sumaJugadores){
	
	for (int i=0; i<cantJugadores;i++){
		for(int j=0; j<2;j++){
			
			cout << "Jugador " << i+1 << " Carta " << j+1 << ": ";
			cartas(mazo, indiceCartas);
			sumaJugadores[i] += sumar(mazo, indiceCartas);
			*indiceCartas++;
		}
		cout << "Total Jugador " << i+1 << " : " << sumaJugadores[i] << endl << endl;	
	}
}
