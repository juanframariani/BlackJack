#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include "cartas.h"
#include "sumar.h"
#include "repartir.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	int cantJugadores=0;
	int mazo[52];
	int contador=0;
	int temp;
	int randomIndex;
	int jugadores[5];			//vector de cantidad de jugadores
	int indiceCartas = 0;		//acumulador a medida que se reparten las cartas
	int sumaJugadores[5];		//suma de las cartas de los jugadores
	int opcionDeJuego=1;		//opcion para pedir o plantarse de cada jugador
	int sumaCroupier=0;			//suma de las cartas del croupier
	int opcionInicio=0;
	
	//Creacion del Mazo de 52 Cartas, sin pinta
	for (int i=0; i<4; i++){											
		for(int j=0; j<13; j++){
			mazo[contador] = (j+1);
			contador++;
		}
	}
	//Random del Mazo
	srand(time(NULL));
	for(int i=0; i<52; i++){		              
		randomIndex = rand() % 52;	              
		temp = mazo[i];				
		mazo[i] = mazo[randomIndex];
		mazo[randomIndex] = temp;	
	}
		
	
	//MENU
//	cout << "MENU BLACKJACK" << endl;
//	cout << "Ingrese la opcion deseada: " << endl;
//	cout << "1- UN JUGADOR." << endl;
//	cout << "2- MULTIJUGADOR." << endl;
//	cout << "3- SALIR." << endl;
	cout << "Ingrese la cantidad de Jugadores: " << endl;
	cin >> cantJugadores;
	
//	switch(opcionInicio){
//	case 1:
//	
//	break;
//	
//	case 2:
//		
//	break;
//	
//	case 3:
//		
//	break;
//	}
	
	//pone en cero el vector de las sumas
	for(int i=0; i<cantJugadores;i++){
		sumaJugadores[i] = 0;
	}
	
	//reparte 2 cartas a cada jugador
//	repartir(mazo, cantJugadores, &indiceCartas, sumaJugadores);				//falla el indiceCartas
	
	for (int i=0; i<cantJugadores;i++){
		for(int j=0; j<2;j++){
			
			cout << "Jugador " << i+1 << " Carta " << j+1 << ": ";
			cartas(mazo, &indiceCartas);
			sumaJugadores[i] += sumar(mazo, &indiceCartas);
			indiceCartas++;
		}
		cout << "Total Jugador " << i+1 << " : " << sumaJugadores[i] << endl << endl;	
	}
	
	//primera carta y suma croupier
		cout << "Carta Croupier: ";
		indiceCartas++;
		cartas(mazo, &indiceCartas);
		sumaCroupier += sumar(mazo,&indiceCartas);
		cout << endl;

	
	//bucle para opcion de juego de cada jugador
	for(int i=0;i<cantJugadores;i++){		//una iteracion por cada jugador
		do{					
			if(sumaJugadores[i] == 21){
				cout << "Jugador " << i+1 << " tiene BlackJack!!" << endl;
			}else{
				cout << "Jugador " << i+1 << ", Total: " << sumaJugadores[i] << endl;
				cout << "Que desea hacer: 1- Pedir o 2- Plantarse" << endl;
				cin >> opcionDeJuego;
				switch(opcionDeJuego){
				case 1:
					++indiceCartas;
					cartas(mazo, &indiceCartas);
					sumaJugadores[i] += sumar(mazo, &indiceCartas);
				break;
				
				case 2:
					cout << "Total Jugador " << i+1 << " : " << sumaJugadores[i] << endl << endl;
				break;
				}
			}
		}while(opcionDeJuego == 1 && sumaJugadores[i]<21);		//habria que agregar condicion de salida cuando sale mas de 21
	}
	
	//segunda carta y suma croupier
	cout << "Segunda Carta Croupier: ";
	indiceCartas++;
	cartas(mazo, &indiceCartas);
	sumaCroupier += sumar(mazo, &indiceCartas);
	cout << "Total Croupier: " << sumaCroupier;
	cout << endl;
	
	//condicion del croupier para pedir o plantarse
 	while(sumaCroupier<17){
		cout << "El Croupier tiene menos de 17, pedira otra carta" << endl;
		indiceCartas++;
		cout << "Carta: ";
		cartas(mazo, &indiceCartas);
		sumaCroupier += sumar(mazo, &indiceCartas);
		cout << "Total Croupier: " << sumaCroupier << endl;
	}
	
	//comparacion de puntaje entre los jugadores y el croupier
	for (int i = 0; i < cantJugadores; i++){
		cout << endl;
		if((sumaCroupier == 21) && (sumaJugadores[i]>21)) {
			cout << "Puntaje Jugador " << i+1 << " : " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El croupier gana - Tiene BlackJack" << endl;
		
		}
		if((sumaCroupier > 21) && (sumaJugadores[i] > 21)) {
			cout << "Puntaje Jugador " << i+1 << " : " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "Empate - Ambos se pasaron de 21" << endl;
			
		}
		if((sumaCroupier >= sumaJugadores[i]) && (sumaCroupier < 21)) {
			cout << "Puntaje Jugador " << i+1 << " : " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El croupier gana" << endl;
		
		} 
		if((sumaJugadores[i] > 21) && (sumaCroupier < 21)) {
			cout << "Puntaje Jugador " << i+1 << " : " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El croupier gana" << endl;
		
		} 
		if((sumaJugadores[i] < 21) && (sumaCroupier > 21)) {
			cout << "Puntaje Jugador " << i+1 << " : " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El Jugador gana" << endl;
		}
		if((sumaJugadores[i] == 21) && (sumaCroupier < 21)) {
			cout << "Puntaje Jugador " << i+1 << " : " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El Jugador gana - Tiene Black Jack" << endl;
		}
	}
}

