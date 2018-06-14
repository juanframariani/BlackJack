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
	string jugadores[5];			//vector de nombre de jugadores
	int indiceCartas = 0;		//acumulador a medida que se reparten las cartas
	int sumaJugadores[5];		//suma de las cartas de los jugadores
	int opcionDeJuego=1;		//opcion para pedir o plantarse de cada jugador
	int sumaCroupier=0;			//suma de las cartas del croupier
	int opcionInicio=0;			//opcion de menu inicio
	int sumaJugadorAs = 0;			//suma del jugador al que le tocaron 2 ases
	int sumaJugadorAsDos = 0;		//suma de otro jugador al que le toquen 2 ases
	int valorAs;
	int segundaCroupier;
	int total[5];
	int apuesta = 0;
	int saldoInicial = 100;
	
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
		cout << endl;
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
			
			break;
			
		case 2:
			cout << "Ingrese la cantidad de Jugadores: ";
			cin >> cantJugadores;
			for (int i=0; i<cantJugadores;i++){
				cout << "Ingrese el nombre del jugador " << i+1 << " : ";
				cin >> jugadores[i];
			}
			
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
	
	//APUESTAS
	cout << "Cada jugador cuenta con un saldo inicial de: $ " << saldoInicial << endl;
	cout<<"La mesa cuenta con una apuesta mÃ­nima de $10 y una máxima de $50" << endl;
	
	for (int i = 0; i < cantJugadores; i++) {
		
		do
		{
			cout << jugadores[i] << ", cual es su apuesta: $ ";
			cin >> apuesta;
		} while( apuesta < 10 || apuesta > 50);
		
		total[i] = saldoInicial-apuesta;
	}
	
	cout << endl;
	
	repartir(mazo, cantJugadores, &indiceCartas, sumaJugadores, &sumaJugadorAs, &sumaJugadorAsDos);
	
	//primera carta y suma croupier
	cout << endl << "Carta Croupier: ";
	indiceCartas++;
	cartas(mazo, &indiceCartas);
	sumaCroupier += sumar(mazo,&indiceCartas);
	cout << endl;
	
	
	//segunda carta
	indiceCartas++;
	segundaCroupier = mazo[indiceCartas];
	sumaCroupier += segundaCroupier;
	
	
	//bucle para opcion de juego de cada jugador
	for(int i=0;i<cantJugadores;i++){		//una iteracion por cada jugador
		do{					
			if(sumaJugadores[i] == 21){
				cout << jugadores[i] << ", tiene BlackJack!!" << endl;
			}else if(sumaJugadores[i] < 21){
				cout << jugadores[i] << ", Total: " << sumaJugadores[i] << endl;
				cout << "Que desea hacer: 1- Pedir o 2- Plantarse" << endl;
				cin >> opcionDeJuego;
				
				switch(opcionDeJuego){
				case 1:
					++indiceCartas;
					cout << "Nueva carta: ";
					cartas(mazo, &indiceCartas);
					
					if(mazo[indiceCartas] == 1){
						cout << "Elija el valor que adquirirá el As: " << endl;
						cout << "1- El as valdrá 1" << endl;
						cout << "2- El as valdrá 11" << endl;
						cin >> valorAs;
						
						switch(valorAs){
						case 1:
							sumaJugadores[i] += 1;
							break;
						case 2:
							sumaJugadores[i] += 11;
							break;
						default:
							return 0;
							break;
						}
					}else{
						sumaJugadores[i] += sumar(mazo, &indiceCartas);
						cout << "Total " << jugadores[i] << " : " << sumaJugadores[i] << endl << endl;
					}
					break;
				case 2:
					cout << "Total " << jugadores[i] << " : " << sumaJugadores[i] << endl << endl;
					break;
				}
			}else if(sumaJugadores[i] > 21){
				cout << "Ha superado los 21 puntos. El croupier gana" << endl;
				return 0;
			}
		}while(opcionDeJuego == 1);
	}
	
	//muestra suma y segunda carta del croupier
	cout << "La segunda carta del croupier es: " << segundaCroupier << endl;
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
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El croupier gana! Tiene BlackJack." << endl;			
			cout << "El nuevo saldo de "<<jugadores[i]<<" es de $" << total[i] <<endl;
		}
		if((sumaCroupier > 21) && (sumaJugadores[i] > 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "Empate! Ambos se pasaron de 21." << endl;
			cout << "El nuevo saldo de " << jugadores[i] << " es de $" << saldoInicial <<endl;
			
		}
		if((sumaCroupier >= sumaJugadores[i]) && (sumaCroupier < 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El croupier gana." << endl;
			cout << "El nuevo saldo de "<<jugadores[i]<<" es de $"<< total[i] <<endl;
		} 
		if((sumaJugadores[i] > 21) && (sumaCroupier < 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << "El croupier gana." << endl;
			cout << "El nuevo saldo de " << jugadores[i] << " es de $" << total[i] <<endl;
		} 
		if((sumaJugadores[i] < 21) && (sumaCroupier > 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << jugadores[i] << " GANA!" << endl;
			total[i]+=(apuesta*2);
			cout << "El nuevo saldo de " << jugadores[i] << " es de $" << total[i ] <<endl;
		}
		if((sumaJugadores[i] == 21) && (sumaCroupier < 21)) {
			cout << "Puntaje " << jugadores[i] << ": " << sumaJugadores[i] << endl;
			cout << "Puntaje Croupier: " << sumaCroupier << endl;
			cout << jugadores[i] << " Gana! Tiene Black Jack." << endl;
			total[i]+=(apuesta*3);
			cout << "El nuevo saldo de " << jugadores[i] << " es de $ " << total[i] <<endl;
		}
		
	}
	
}

