#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#define BARAJAR_H
using namespace std;

void barajar(int[], int);

int main (int argc, char *argv[]) {
	srand(time(NULL));
	int deck[52];
	int position;
	string mazo[52]={"APica","2Pica","3Pica","4Pica","5Pica","6Pica","7Pica","8Pica","9Pica","10Pica","JPica","QPica","KPica",	//declaración del mazo como arreglo de strings
			"ACorazon","2Corazon","3Corazon","4Corazon","5Corazon","6Corazon","7Corazon","8Corazon","9Corazon","10Corazon","JCorazon","QCorazon","KCorazon",
			"ATrebol","2Trebol","3Trebol","4Trebol","5Trebol","6Trebol","7Trebol","8Trebol","9Trebol","10Trebol","JTrebol","QTrebol","KTrebol",
			"ADiamante","2Diamante","3Diamante","4Diamante","5Diamante","6Diamante","7Diamante","8Diamante","9Diamante","10Diamante","JDiamante","QDiamante","KDiamante"};
	
	for(int i=0; i<52; i++){
		deck[i]=i;
	}
	
	barajar(deck,52);
	
	for(int j=0; j<52; j++){
		position=deck[j];
		cout << mazo[position] << endl;
	}
	
	cout << endl;
}
