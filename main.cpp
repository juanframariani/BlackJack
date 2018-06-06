#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>

using namespace std;

int main (int argc, char *argv[]) {
	
	int mazo[52];
	int contador = 0;
	int temp;					              
	int randomIndex = 0;	
	int indice = 0;
	int sumaJugador = 0;
	int sumaCroupier = 0;
	int opcionDeJuego;
	
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
	
	//Repartir las cartas y suma los valores de las mismas
	for (int i=0; i<2; i++){
		for (int j=0; j<1; j++){
			cout << "Jugador: " << mazo[indice] << endl;
			sumaJugador += mazo[indice];
			indice++;
		}
		cout << "Croupier: " << mazo[indice] << endl;
		sumaCroupier += mazo[indice];
		indice++;
	}
	
	//Muestra los totales de la suma de las cartas.
	cout << "Total Jugador: " << sumaJugador << endl;
	
	//deberia mostrar el total, despues de que que juegan todos los jugadores
	cout << "Total Croupier: " << sumaCroupier << endl;
	
	//Lazo para pedir o plantarse
	while(sumaJugador<21){
		cout << "Que desea hacer?" << endl;
		cout << "1- Pedir  2- Plantarse" << endl;
		cin >> opcionDeJuego;
		if (opcionDeJuego == 1){
			indice++;
			cout << "Carta: " << mazo[indice] << endl;
			sumaJugador += mazo[indice];
			cout << "Total Jugador: " << sumaJugador << endl;
		}
		else
			break;
	}
	
	//Juego del Croupier
	while(sumaCroupier<17){
		cout << "El Croupier tiene menos de 17, pedira otra carta" << endl;
		indice++;
		cout << "Carta: " << mazo[indice] << endl;
		sumaCroupier += mazo[indice];
		cout << "Total Croupier: " << sumaCroupier << endl;
	}
	
	//Anlasis de puntos para determinar quien gana.
	if ((sumaCroupier < sumaJugador) && (sumaJugador<22)){
		cout << "El jugador Gana" << endl;
	}else if(sumaJugador == 21){
		cout << "JUGADOR TIENE BLACKJACK" << endl;
	}else if ((sumaCroupier > sumaJugador) && (sumaCroupier<22)){
		cout << "El croupier gana" << endl;
	}else if (sumaCroupier == sumaJugador){
		cout << "El jugador y el croupier empatan" << endl;
	}
	
return 0;
}
