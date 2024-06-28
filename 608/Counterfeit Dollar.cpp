//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema: Se tienen 12 monedas, de las cuales hay una falsa, la cual se diferencia ya que tiene un pesomas ligero pesado al de todas las demas.
Al pesar las monedas de 3 formas diferentes en una balanza, se guardaron sus resultados para determinar cual es la moneda falsa y si es mas o menos pesada que el resto.

Solucion: 
Se guardan los diferentes resultados de las balanzas y las monedas usadas en este. 
Por lo que se recorren todas las 12 monedas y se determina cual de estas tiene un peso distinto, usando las funciones check_heavy() y check_light().
Las cuales, detectan si se puede determinar si la moneda es mas pesada que el resto o mas ligera con base en los 3 estados de la balanza.

Estas dos funciones buscan situaciones que argumenten que la moneda es normal en cada estado, y si no se encuentra ninguna, se considera como anormal.

*/

vector<char> coins = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};

string lef[3], righ[3], state_r[3];

//Notemos que si queremos llegar a confirmar que coin es pesada o ligera, se requieren de a lo mas tres comparaciones

bool check_heavy(char coin){//Verificamos si la moneda es pesada con base en los 3 estados de la balanza que tenemos
	
	int L, R;
	
	for(int i = 0; i < 3; i++){//3 balanceadad
		L = R = 0;
		
		for(int j = 0; j < lef[i].size(); j++){//En la balanceada i, vemos donde esta coin
			if(lef[i][j] == coin){
				L++;
			}else if(righ[i][j] == coin){
				R++;
			}
		}
		
		if(state_r[i] == "even" && L != R){//Si coin esta en un lado y la balanza esta en equilibrio
			return false;
			
		}else if(state_r[i] == "up" && L<=R){//Si coin esta en la derecha y arriba, o no se pueden dar las 3 comparaciones
			return false;
			
		}else if(state_r[i] == "down" && L>=R){//Analogo a arriba
			return false;
		}

	}
	
	return true;
}

bool check_light(char coin){//Se hace un proceso analogo a check_heavy
    int L, R;
    
	for(int i=0; i < 3; i++){
		L = R = 0;
		
		for(int j=0; j < lef[i].size(); j++){//Nota personal: El código nunca menciona que siempre se pongan 4 monedas en cada lado
			if(lef[i][j] == coin){
				L--;
			}else if(righ[i][j] == coin){
				R--;
			}
		}
		
        if(state_r[i] == "even" && L!=R){
        	return false;
        	
		}else if(state_r[i] == "up" && L<=R){
			return false;
			
		}else if(state_r[i] == "down" && L>=R){
        	return false;
		}
 
	}
	return true;
}


int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < 3; j++){
			cin>>lef[j]>>righ[j]>>state_r[j];
			//cout<<lef[j]<<"---"<<righ[j]<<"---"<<state_r[j]<<endl;
		}

		for(int h = 0; h < coins.size(); h++){
			//cout<<"X"<<endl;
			if(check_heavy(coins[h])){
				cout<<coins[h]<<" is the counterfeit coin and it is heavy."<<endl;
				break;
				
			}else if(check_light(coins[h])){
				cout<<coins[h]<<" is the counterfeit coin and it is light."<<endl;
				break;
			}
		}
		
	}
	
	
	return 0;
}
