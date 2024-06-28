//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
En este problema se pide comprobar si unas sumas y restas son correctas,
Ya que son de la forma a+b=c  o a-b=c, donde 0<=a,b<100, podemos recibir la operacion con un scanf (Para facilitar el uso de enteros y signos) y verificar facilmente
si es correcta o no.

Soluciom:
Con ayuda de scanf, podemos recibir el formato justo de las operaciones, y al conocer los numoeros de esta, y la operacion, podemos determinar si es correcta o no.
Si se reponde ?, se cuenta como incorrecta ya que no se respondio
*/

int main(int argc, char** argv) {
	
	int a, b; //a+-b
	char op;//+-
	char ans[5];//El resultado puede ser ? o un numero de a lo mas 3 digitos (100+100 = 200), 5 es por si acaso
	
	int ca = 0;
	
	while(scanf("%d%c%d=%s",&a,&op,&b,ans) == 4){
		
		if(ans[0] == '?'){
			continue;
		}
		
		int c = atoi(ans);
		
		if(op == '+'){
			if(a+b == c){
				ca++;
			}
		}else{
			if(a-b == c){
				ca++;
			}
		}
	}
	
	cout<<ca<<endl;
	
	return 0;
}
