//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
int findSwaps( int n, int a[] ){//Cuenta los swaps al ejecutar bubble sort con a
	
	int count = 0, i, j, temp, b[100000];
	for( i = 0; i < n; i++){
		b[i] = a[i];
	}
	
	for( i = 0; i < n; i++){
		for( j = 0; j < n - 1; j++){
			if( b[j] > b[j+1] ){
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
				count++;
			}
		}
	}
	
return count;
}

Tienes que encontrar el valor promedio de 'count' en el código dado si ejecutamos findSwaps() infinitamente
muchas veces usando la constante 'n' y cada vez que se dan algunos números enteros aleatorios (del 1 al n) en la matriz
a[]. Puede suponer que los enteros de entrada en la matriz a[] son ??distintos
*/


/*
Solucion:
Primero, sean a,b dos numeros enteros aleatorios, la probabilidad de que se intercambien con Bubble Sort es de 1/2, y por ende
la probabilidad de que no se intercambien es la misma.

Dado un arreglo de n numeros, se pueden formar n! /( 2! *(n-2)! ) posibles parejas, lo que es igual a n(n-1)/2, por lo que en promedio se realizaran
(1/2)*(n(n-1)/2) = n(n-1)/4 swaps


*/



/*
long long mcd(long long a, long long b){//Funcion para calcular el maximo comun divisor
    int MCD=1; //Regresamod uno si es que alguno es cero   

    int x = max(a,b);
    int y = min(a,b);

    while(y!=0){//Ciclo while para encontrar el maximo comun divisor
        MCD = y;// 
        y = x%y;//a%b regresa el residuo de la division. a%b = c tal que   n*b +c = a
        x = MCD;
    }
    
    return MCD;	
}
*/

int main(int argc, char** argv){
	
	int T;//Casos
	cin>>T;
	
	for(int i = 0; i < T; i++){
		int n;
		cin>>n;
		
		long long a = (long long)n*(n-1);//Este siempre sera un numero par, por lo que es dividible entre 2
		//long long b = 4;
		//long long MCD = mcd(a, 4);
		
		//a /= MCD;
		//b /= MCD;
		
		cout<<"Case "<<i+1<<": ";
		if(a%4 == 0){//Si se pudo dividir entre 4
			cout<<a/4<<endl;
		}else{
			cout<<a/2<<"/2"<<endl;
		}
		
	}
	
	
	return 0;
}
