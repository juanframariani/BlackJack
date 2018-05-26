#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string.h>
#include <stdio.h>
#define BARAJAR_H

using namespace std;

void barajar(int[],int);
void nombreJugador(int);
void juego(int[], int);
void opcionesJugador();


int main (int argc, char *argv[]) {
	int input;
	srand(time(NULL));                              	//funciÃ³n random que se conecta con el reloj de la pc para que la secuencia no sea repetitiva
	int cantJugadores = 0;
	int contador = 0;
	int mazo[52];
	
	//Menu
	do{
		
		cout << "BLACK JACK\nMENU\nSELECCIONE LA OPCION DESEADA:\n";
		cout << "1. UN JUGADOR\n";
		cout << "2. MULTIJUGADOR\n";
		cout << "3. SALIR\n";
		cout << "INGRESE NUMERO DE LA OPCION DESEADA: ";
		cin >> input;
		
		switch(input){
		case 1:
			cantJugadores = 1;
			nombreJugador(cantJugadores);
			
			for (int i=0; i<4; i++){											//creacion del vector de cartas
				for(int j=0; j<13; j++){
					
					mazo[contador] = (j+1);
					contador++;
				}
			}
			
			barajar(mazo, 52);
			juego(mazo, cantJugadores);
			
		break;
			
		case 2:
			cout << "Ingrese cantidad de jugadores: ";
			cin >> cantJugadores;
			nombreJugador(cantJugadores);
			cout << "Con cuantos mazos desean jugar?: ";
			
		break;
			
		case 3:
			return(0);
		break;
			
		default:
			cout<<"LA OPCION INGRESADA ES INCORRECTA, INTENTE NUEVAMENTE.\n\n";
		break;
		}
		
	}while(input!=3);
	
	cin.get();
}



//NOMBRE DE LOS JUGADORES
void nombreJugador(int cantJugadores) {
	
	string nombre;
	int longitud;
	string nombres[5];
	
	for (int i=0; i < cantJugadores; i++) {
		cout << "Jugador N°" << i+1 << ", Ingrese su nombre: ";
		cin >> nombre;
		nombres[i] = nombre;
	}

}





//JUEGO
void juego(int mazo[], int cantJugadores){
	int sumaCartas = 0;
	int sumaCartasCroupier = 0;
	int cantCartasIniciales = 0;
	
	cantCartasIniciales = cantJugadores*2;
	
	for (int i=0; i<cantJugadores;i++){
		cout << "Cartas Jugador " << i+1 << endl;
		for (int j=0; j<cantCartasIniciales;j++){
			cout << mazo[j] << endl;
			sumaCartas += mazo[j];
		}
		
	}
	int aux = cantCartasIniciales+2;
	
	cout << "Cartas Croupier: " << endl;
	for (int k=aux; k<(aux+2);k++){
		cout << mazo[k] << endl;
		sumaCartasCroupier += mazo[k];
	}
	
	opcionesJugador();
}

//OPCIONES DE JUEGO
void opcionesJugador(){
	
	int opcion;

	cout<< "¿Qué deseas hacer?\n\n";
	
	do{
		cout<<"1) Pedir una carta más\n";
		cout<<"2) Plantarse\n";
		cout<<"3) Separar las cartas\n";
		cin>>opcion;
		
		switch(opcion){
		case 1:
			
		break;
			
		case 2:
			
		break;
			
		case 3:
			
		break;
			
		default:
			cout<<"LA OPCION INGRESADA ES INCORRECTA, INTENTE NUEVAMENTE.\n\n";
		break;
		}
	} while(opcion!=4);
}


//FUNCION PARA BARAJAR LAS CARTAS
void barajar(int mazo[], int len){
	int temp;					              //declara una variable temp
	int randomIndex = 0;			              //declara una variable para el Ã­ndice a randomizar
	
	for(int i=0; i<len; i++){		              //recorre el arreglo
		randomIndex = rand() % len;	              //le asigna un valor random dentro del rango del largo del arreglo a la variable randomIndex
		temp = mazo[i];				              //le asigna el valor almacenado en el arreglo a la variable temp
		mazo[i] = mazo[randomIndex];	          //le asigna el valor de la variable randomIndex al valor i del arreglo
		mazo[randomIndex] = temp;		          //le asigna temp a la posiciÃ³n random del arreglo
	}
}
