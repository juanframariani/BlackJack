#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#define BARAJAR_H
using namespace std;

void barajar(int deck[], int len){
	int temp = 0;					              //declara una variable temp
	int randomIndex = 0;			              //declara una variable para el índice a randomizar
	
	for(int i=0; i<len; i++){		              //recorre el arreglo
		randomIndex = rand() % len;	              //le asigna un valor random dentro del rango del largo del arreglo a la variable randomIndex
		temp = deck[i];				              //le asigna el valor almacenado en el arreglo a la variable temp
		deck[i] = deck[randomIndex];	          //le asigna el valor de la variable randomIndex al valor i del arreglo
		deck[randomIndex] = temp;		          //le asigna temp a la posición random del arreglo
	}
	
}


int main (int argc, char *argv[]) {
	int input;
	
	do{

	cout<<"BLACK JACK\nMENU\nSELECCIONE LA OPCION DESEADA:\n";
	cout<<"1. UN JUGADOR\n";
	cout<<"2. MULTIJUGADOR\n";
	cout<<"3. SALIR\n";
	cout<<"INGRESE NUMERO DE LA OPCION DESEADA: ";
	cin>> input;
	
	srand(time(NULL));                             //función random que se conecta con el reloj de la pc para que la secuencia no sea repetitiva
	int deck[52];                                  //declara un arreglo donde se almacenan los números random para evitar que se repitan
	int position;                                  //declara una variable para acceder a la posición del arreglo
	string deckUser[10];				//declara un vector para las cartas del usuario
	string deckCroupier[10];			//declara un vector para las cartas del croupier
	int posU;					//declara una variable para la posición de las cartas del usuario
	int posC;					//declara una variable para la posición de las cartas del croupier
	string mazo[52]={"AP","2P","3P","4P","5P","6P","7P","8P","9P","10P","JP","QP","KP", //declaración del mazo como arreglo de strings
		"AC","2C","3C","4C","5C","6C","7C","8C","9C","10C","JC","QC","KC",
		"AT","2T","3T","4T","5T","6T","7T","8T","9T","10T","JT","QT","KT",
		"AD","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD"};


switch(input){
case 1:
	for(int i=0; i<52; i++){				 //crea un array de int desde el 0 al 51
		deck[i]=i;
	}
	
	barajar(deck,52);					//"mezcla" los valores para que no estén ordenados 
	
	for(int j=0; j<52; j++){			        //recorre el arreglo completo
		position=deck[j];				//le asigna el valor del arreglo anterior a position
	}
	
	posU = deck[0];						//asigna la posición del deck a la carta del usuario
	deckUser[0] = mazo[posU];				//busca en el mazo la posición para mostrarla
	posC = deck[1];						//asigna la posición del deck a la carta del croupier
	deckCroupier[0] = mazo[posC];				//busca en el mazo la posición para mostrarla
	posU = deck[2];
	deckUser[1] = mazo[posU];
	posC = deck[1];
	deckCroupier[1] = mazo[posC];
	
	cout << "Tus cartas: " << deckUser[0] << " - " << deckUser[1] << endl; 		//muestra el valor de las cartas repartidas al usuario
	cout << "Las cartas de la banca: " << deckCroupier[0] << " - XX" << endl; 	//muestra el valor de las cartas repartidas al croupier
	cout << "\n";
	
	break;

case 2:
	   
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

void nombreJugador() {

    char Nombre[20];
    int longitud;
    cout << "Jugador N°1, Ingrese su nombre: ";
    gets(Nombre);
    longitud = strlen(Nombre);
    if (longitud > 20) {
        cout << "El nombre ingresado es demasiado largo, por favor ingrese uno con menos de 20 caracteres.";
    } else {
        cout << "El Nombre ingresado es: " << Nombre;
    }


    return 0;

}

void turno_croupier() {
    while (mano[0].conteo_cartas < 17) {
        pedirCarta(0);
    }
    if (mano[0].conteo_cartas >= 17) {
        paso(0);

    }


    return 0;
}


 void opcionesJugador(){
	
	int opcion;
			/*cout << "Tus cartas: " << deckUser[0] << " - " << deckUser[1] << endl;*/
	cout<<"La suma de tus cartas es: "<< "¿Qué deseas hacer?\n\n";
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
