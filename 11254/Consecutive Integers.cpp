//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gauss(int n){//Suma de 1 a n
	
	return((n*(n+1))/2);
}

int sum(int a, int b){//Sea a < b, se regresa a + (a+1) + ... (b-1) + b 

	if(a == b){
		return a;
	}

	return(gauss(b)- gauss(a) + a);
}

/*
Problema:
Todo entero puede escribirse como la suma de ciertos numeros enteros consecuticos.
Como hay varias solucones posibles, buscamos la solucion con la mayor cantidad de numeros posibles

15 = 1 + . . . + 5 = 4 + . . . + 6 = 7 + . . . + 8 = 15 + . . . + 15


Solucion:
Al inicio se intento usar la funcion sum para calcular las oberaciones, pero eso tomaba mucho tiempo, 
por lo que se opto por la opcion de la ventana deslizante.
Es decir, empezaremos con ambos extremos en un punto e iremos recorriendo el derecho e iremos sumando, 
en el momento en que nos pasemos, recorreremos el izquierdo y restaremos.
En el momento en que alcancemos n, imprimimos los valores del izquierdo y derecho (L,R)
*/

int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	
	while(n >= 0){
		int suma = 1;
		int L = 1, R = 1;
		
		while(suma != n){
			//suma = sum(L,R);
			//cout<<"--->"<<suma<<endl;
			if(suma < n){
				R++;
				suma += R;
			}else if(suma > n){
				L++;
				suma -= (L-1);
			}
				
		}
		
		cout<< n<<" = "<<L<<" + ... + "<<R<<endl;
		cin>>n;
		
	}
	
	
	
	return 0;
}
