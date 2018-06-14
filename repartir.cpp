#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include "cartas.h"
#include "sumar.h"
#include "repartir.h"


using namespace std;

void repartir (int mazo[], int cantJugadores, int * indiceCartas, int sumaJugadores[], int *sumaJugadorAs, int *sumaJugadorAsDos){
	
	for (int i=0; i<cantJugadores;i++){
		for(int j=0; j<2;j++){
			
			cout << "Jugador " << i+1 << " - Carta " << j+1 << ": ";
			cartas(mazo, indiceCartas);
			sumaJugadores[i] += sumar(mazo, indiceCartas);
			(*indiceCartas)++;
			
			
			if(sumaJugadores[i] == 22){
				int opcionAs = 0;
				
				do{
					cout << "¡Tiene doble As! ¿Desea separar su mano?" << endl;
					cout << "Si decide separar su amano, automáticamente se pedirá" << endl;
					cout << "una nueva carta para cada una de sus manos." << endl;
					cout << "Caso contrario, uno de sus ases valdrá 11 y el otro, 1." << endl;
					cout << "1- Sí, deseo separar mi mano." << endl;
					cout << "2- No, quiero continuar con las cartas que tengo." << endl;
					cin >> opcionAs;
					
					
					switch(opcionAs){
					case 1:
						//*Inserte código del JuanJo aquí para apuestas
						
						cout << "Su mano se dividirá en dos manos a partir de ahora." << endl;
						cout << "Se le repartirán dos cartas más, una por cada mano." << endl;
						
						
						if(sumaJugadorAs == 0){
							sumaJugadores[i] = 11;
							cout << "Jugador " << i+1 << " - Mano 1 - Carta 1: ";
							cartas(mazo, indiceCartas);
							sumaJugadores[i] += sumar(mazo, indiceCartas);
							(*indiceCartas)++;
							
							cout << "Total Mano 1: " << sumaJugadores[i] << endl;
							
							
							*sumaJugadorAs = 11;
							cout << "Jugador " << i+1 << " - Mano 2 - Carta 2: ";
							cartas(mazo, indiceCartas);
							sumaJugadorAs += sumar(mazo, indiceCartas);
							(*indiceCartas)++;
							
							cout << "Total Mano 2: " << sumaJugadorAs << endl;
							
							
						}else{
							sumaJugadores[i] = 11;
							cout << "Jugador " << i+1 << " - Mano 1 - Carta 1: ";
							cartas(mazo, indiceCartas);
							sumaJugadores[i] += sumar(mazo, indiceCartas);
							(*indiceCartas)++;
							
							cout << "Total Mano 1: " << sumaJugadores[i] << endl;
							
							
							*sumaJugadorAsDos = 11;
							cout << "Jugador " << i+1 << " - Mano 2 - Carta 2: ";
							cartas(mazo, indiceCartas);
							sumaJugadorAsDos += sumar(mazo, indiceCartas);
							(*indiceCartas)++;
							
							cout << "Total Mano 2: " << sumaJugadorAsDos << endl;
							
						}
						
						break;
					case 2:
						cout << "Total Jugador " << i+1 << " : 12." << endl;
						break;
					default:
						cout << "Opción incorrecta. Elija una opción del menú." << endl;
						break;
					}
				}while(opcionAs != 1 || opcionAs !=2);
				
			}
		}
		
		if(sumaJugadorAs == 0){
			cout << "Total Jugador " << i+1 << " : " << sumaJugadores[i] << endl << endl;	
		}else{
			
		}
	}
}

