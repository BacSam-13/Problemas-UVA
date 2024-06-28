//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Problema:
/*
Dadas unas secuencias:
a_0, ..., a_n+1
c_1, ..., c_n

Si sabemos que se cumple que a_i = (a_i-1  +  a_i+1)/2 - c_i   para i =1,...,n
Ademas de saber N, a_0, a_n+1 y la secuencia, calcular a_1
*/

//Solucion: (Precision 2)
/*
Con base en inducción, sabemos que

a_1 = (n*a_0  +  a_n+1  -2(n*c_1 + ... + c_n)) / 2*(n+1)
para todo n natural.

Por lo tanto, al recibir todos los valores c, iremos calculando el valor de la suma de c´s para imprimir el resultado con precision 2
*/

int main(int argc, char** argv){
	
	int cases;
	cin>>cases;
	
	while(cases--){
		int n;
		cin>>n;
		double a_0, a_n1;
		
		cin>>a_0>>a_n1;
		
		double c;//Para recibir los valores de c
		double sum_c = 0;
		
		for(int i = 1; i <= n; i++){
			cin>>c;
			sum_c += (n+1-i)*c;
		}
		
		double a_1 = (n*a_0 + a_n1 - 2* sum_c)/(n+1.0);

		printf("%.2lf\n", a_1);
		
		if(cases){
			cout<<endl;
		}
	}
	
	return 0;
}
