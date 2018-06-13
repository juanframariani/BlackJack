#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <chrono>
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
	string jugadores[5];		//vector de nombre de jugadores
	int indiceCartas = 0;		//acumulador a medida que se reparten las cartas
	int sumaJugadores[5];		//suma de las cartas de los jugadores
	int opcionDeJuego=1;		//opcion para pedir o plantarse de cada jugador
	int sumaCroupier=0;			//suma de las cartas del croupier
	int opcionInicio=0;			//opcion de menu inicio
	int total;
	int apuesta;
	int saldoInicial = 100;
	int apMinima =10;
	int apMaxima = 50;
	int apGanadora;
	int apGanadoraB;
	
	//Creacion del Mazo de 52 Cartas
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
	do{
		cout << "BLACKJACK MDI" << endl;
		cout << "\n" << endl;
		cout << "1. UN JUGADOR" << endl;
		cout << "2. MULTIJUGADOR" << endl;
		cout << "3. SALIR" << endl;
		cout << "Ingrese la opción deseada: ";
		cin >> opcionInicio;
		
		switch(opcionInicio){
		case 1:
			cantJugadores = 1;
			cout << "\n";
			cout << "Ingrese su nombre: " << endl;
			cin>> jugadores[0];

			//apuestas
			break;
			
		case 2:
			cout << "Ingrese la cantidad de Jugadores: ";
			cin >> cantJugadores;
			for (int i=0; i<cantJugadores;i++){
				cout << "Ingrese el nombre del jugador " << i+1 << " : ";
				cin >> jugadores[i];
			}
			//apuestas
			break;
			
		case 3:
			return 0;
			break;
			
		default:
			cout << "La opción ingresada es incorrecta, intente nuevamente.\n\n";
			break;
		}
		
	}while(opcionInicio!=3&&opcionInicio!=2&&opcionInicio!=1);
	cin.get();
	
	//Inicializa en cero el vector de las sumas
	for(int i=0; i<cantJugadores;i++){
		sumaJugadores[i] = 0;
	}	
	
	//reparte 2 cartas a cada jugador
	//	repartir(mazo, cantJugadores, &indiceCartas, sumaJugadores);				//falla el indiceCartas
	for (int i = 0; i < cantJugadores; i++) {
		cout<<"\nUsted cuenta con un saldo inicial de: $"<<saldoInicial<< endl;
		cout<<"La mesa cuenta con una apuesta mínima de $10 y una máxima de $50"<<endl;
		do
		{
			cout << "\nJugador " << i + 1 << " haga su apuesta: $";
			cin >> apuesta;
		} while(apuesta < apMinima || apuesta > apMaxima);
		
		total = saldoInicial-apuesta;
		apGanadora = (apuesta*2)+total;
		apGanadoraB = (apuesta*3)+total;		
		
	}
	for (int i=0; i<cantJugadores;i++){
		for(int j=0; j<2;j++){
			
			cout << jugadores[i] << " - Carta " << j+1 << ": ";
			cartas(mazo, &indiceCartas);
			sumaJugadores[i] += sumar(mazo, &indiceCartas);
			indiceCartas++;
		}
		cout << "Total " << jugadores[i] << ": " << sumaJugadores[i] << endl << endl;
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
				cout << jugadores[i] << " tiene BlackJack!!" << endl;
			}else{
				cout << jugadores[i] << " Total: " << sumaJugadores[i] << endl;
				cout << "\n¿Qué desea hacer?: \n1. Pedir \n2. Plantarse" << endl;
				cout << "Ingrese la opción deseada: ";
				cin >> opcionDeJuego;
				switch(opcionDeJuego){
				case 1:
					++indiceCartas;
					cartas(mazo, &indiceCartas);
					sumaJugadores[i] += sumar(mazo, &indiceCartas);
					break;
					
				case 2:
					cout << "Total " << jugadores[i] << ": " << sumaJugadores[i] << endl << endl;
					cout << "\n";
					break;
				}
			}
		}while(opcionDeJuego == 1 && sumaJugadores[i]<21);
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
		cout << "El Croupier tiene menos de 17, pedira otra carta." << endl;
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
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El croupier gana! Tiene BlackJack." << endl;			
			cout << "\nEl nuevo saldo de "<<jugadores[i]<<" es de $"<< total<<endl;
		}
		if((sumaCroupier > 21) && (sumaJugadores[i] > 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "Empate! Ambos se pasaron de 21." << endl;
			cout << "\nEl nuevo saldo de "<<jugadores[i]<<" es de $"<< saldoInicial<<endl;
			
		}
		if((sumaCroupier >= sumaJugadores[i]) && (sumaCroupier < 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El croupier gana." << endl;
			cout << "\nEl nuevo saldo de "<<jugadores[i]<<" es de $"<< total<<endl;
		} 
		if((sumaJugadores[i] > 21) && (sumaCroupier < 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El croupier gana." << endl;
			cout << "\nEl nuevo saldo de "<<jugadores[i]<<" es de $"<< total<<endl;
		} 
		if((sumaJugadores[i] < 21) && (sumaCroupier > 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << jugadores[i] << " GANA!" << endl;
			cout << "\nEl nuevo saldo de "<<jugadores[i]<<" es de $"<< apGanadora<<endl;
		}
		if((sumaJugadores[i] == 21) && (sumaCroupier < 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << jugadores[i] << " Gana! Tiene Black Jack." << endl;
			cout << "\nEl nuevo saldo de "<<jugadores[i]<<" es de $ "<< apGanadoraB<<endl;
		}
		
	}
	

}
